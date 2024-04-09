import { $ } from "/static/jquery/src/jquery.js";

export function say_hi(elt) {
    console.log("Say hi to", elt);
}
say_hi($("h1"));

export function make_table_sortable($table) {
    let $headerCells = $table.find("th").toArray();
    let $sortableHeaderCells = $table.find("th.sortable");
    $sortableHeaderCells.on("click", function(){
        let $tableBody = $table.find("tbody");
        let $rows = $table.find("tbody tr").toArray();

        let $clickedHeader = $(this);
        let columnIndex = $clickedHeader.index();

        $sortableHeaderCells.not($clickedHeader).removeClass('sort-asc sort-desc unsorted');

        if(columnIndex == $headerCells.length-1){
            $rows.sort(function(a, b){return weight_sort(a, b, $clickedHeader);});    
        }
        else{
            $rows.sort(function(a,b){return due_date_sort(columnIndex, a, b, $clickedHeader);});
        }

        if($clickedHeader.hasClass("sort-asc")){
            $clickedHeader.removeClass("sort-asc");
            $clickedHeader.addClass("sort-desc");
        }
        else if($clickedHeader.hasClass("sort-desc")){
            $clickedHeader.removeClass("sort-desc");
            $clickedHeader.addClass("unsorted");
        }
        else{
            $clickedHeader.removeClass("unsorted");
            $clickedHeader.addClass("sort-asc");
        }
        $tableBody.empty().append($rows);
    });
}

export function weight_sort(a, b, $clickedHeader){
    let textA = $(a).find("td:last").text().trim();
    let textB = $(b).find("td:last").text().trim();

    let numA = parseFloat(textA);
    let numB = parseFloat(textB);

    // Handle percentage of fraction signs
    if(textA.includes('%')){ numA /= 100; }
    if(textB.includes('%')){ numB /= 100; }

    if($clickedHeader.hasClass("sort-asc")){
        console.log("sort-desc");
        return numA - numB;
    }
    else if($clickedHeader.hasClass("sort-desc")){
        console.log("unsorted");
        return $(a).data("index") - $(b).data("index");
    }
    else{
        console.log("sort-asc");
        return numB - numA;
    }
}

export function due_date_sort(columnIndex, a, b, $clickedHeader){
    let dateA = $(a).find(`td:eq(${columnIndex})`).data("value");
    let dateB = $(b).find(`td:eq(${columnIndex})`).data("value");

    if($clickedHeader.hasClass("sort-asc")){
        console.log("sort-desc");
        return dateA - dateB;
    }
    else if($clickedHeader.hasClass("sort-desc")){
        console.log("unsorted");
        return $(a).data("index") - $(b).data("index");
    }
    else{
        console.log("sort-asc");
        return dateB - dateA;
    }
}
make_table_sortable($("#assignmentsTable"));
make_table_sortable($("#submissionsTable"));
make_table_sortable($("#profileTable"));

export function make_form_async($form){
    $form.on("submit", function(event){
        event.preventDefault();

        let formData = new FormData($form[0]);

        $form.find("input[type='file']").prop("disabled", true);
        $form.find("button[type='submit']").prop("disabled", true);

        $.ajax({
            url: $form.attr("action"),
            type: "POST",
            data: formData,
            processData: false,
            contentType: false,
            mimeType: $form.attr('enctype'),
            success: function () {
                $form.replaceWith("<p>Upload succeeded</p>");
            },
            error: function () {
                console.log("Error submitting the form");
            }
        });
    });
}
make_form_async($("#submissionForm"));

export function make_grade_hypothesized($table){
    let $button = $("<button>", {
        text: 'Hypothesize',
    });

    // Add the button before the table
    $table.before($button);

    // let $button = $table.find("button");
    let $rows = $table.find("tbody tr");
    $button.on("click", function(){
        if($table.hasClass("hypothesized")){
            $table.removeClass("hypothesized");
            $button.text("Hypothesize");

            for(let row of $rows){
                let $row = $(row);
                let $td = $row.find("td:last");
                $td.text($td.data("original"));
            }
        }
        else{
            $table.addClass("hypothesized");
            $button.text("Actual Grades");
            
            for(let row of $rows){
                let $row = $(row);
                let $td = $row.find("td:last");
                let tdText = $td.text().trim();
                if(tdText === "Not Due" || tdText === "Ungraded"){
                    $td.data("original", tdText);
                    $td.html("<input type='number'>");
                }
            }
        }
    });

    $table.on("change", "input[type='number']", function(){
        let student_points = 0;
        let total_available_points = 0;
        //calculate grade
        for(let row of $rows){
            let $row = $(row);
            let $td = $row.find("td:last");
            let $input = null;
            if(($td.has( "input" ) ? "True" : "False") === "True"){
                $input = $td.find("input");
            }
            if(typeof $input !== null && $input.val() !== ""){
                let weight = $td.data("weight");
                student_points += calculate_grade($td, weight);
                total_available_points += weight;
            }
            else{
                continue;
            }
        }
        let $tfoot = $table.find("tfoot");
        let $finalGrade = $tfoot.find("td:last");
        $finalGrade.text(Math.floor((student_points / total_available_points) * 100) + '.0%');
    });
}

export function calculate_grade($td, weight){
    if($td.find("input").length === 1){
        let $input = $td.find("input");
        let hypothetical_percent = $input.val();
        hypothetical_percent = parseFloat(hypothetical_percent)/100;
        return hypothetical_percent * weight;
    }
    else{
        let text = $td.text().trim();
        let percent = 0;
        if(text === "Missing"){
            return percent;
        }
        else{
            percent = parseFloat(text)/100;
            return percent * weight
        }
    }
}
make_grade_hypothesized($("#profileTable"));