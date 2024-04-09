from . import models
from django.shortcuts import render, get_object_or_404, redirect
from django.views.decorators.csrf import csrf_protect
from django.contrib.auth import authenticate, login, logout
from django.db.models import Count, Q
from django import template
from django.utils import timezone
from django.contrib.auth.decorators import login_required, user_passes_test
from django.http import HttpResponseBadRequest, HttpResponse
from django.core.exceptions import PermissionDenied

register = template.Library()
@register.filter
def calculate_weighted_grade(score, max_score, weight):
    return (score/max_score) * weight

def is_student(user):
    return user.groups.filter(name="Students").exists()

def is_anonymous(user):
    return not user.is_authenticated

def is_ta(user):
    return user.groups.filter(name="Teaching Assistants").exists()

def is_administrative(user):
    return user.is_superuser

def is_ta_or_administrative(user):
    return is_ta(user) or is_administrative(user)

# Create your views here.
@login_required
def assignments(request):
    assignments = models.Assignment.objects.order_by("deadline")
    return render(request, "assignments.html", dict(assignments=assignments))

@login_required
def index(request, assignment_id):
    assignment = get_object_or_404(models.Assignment, pk=assignment_id)
    print(assignment.title)

    current_date = timezone.now()
    submission = None
    try:
        submission = models.Submission.objects.get(assignment=assignment, author__username=request.user.username)
        filename = submission.file
        submission_score = submission.score
    except models.Submission.DoesNotExist:
        filename = None
        # submission_score = 0
    if request.method =="GET":
        if (assignment.deadline > current_date):
            is_due = False
            if filename is None:
                # not due assingments
                submission_status = "No current submission"
            else:
                # submitted not due assignments
                submission_status = f"Your current submission is {filename}"
        else:
            is_due = True
            if filename is None:
                # missing assignments
                submission_status = "You did not submit this assignment and received 0 points"
            elif submission_score is None:
                # ungraded assignments
                submission_status = f"Your submission, {filename}, is being graded"
            else:
                # graded assignments
                score_status = format(submission_score/assignment.points, ".1%")
                submission_status = f"Your submission, {filename}, received {submission_score}/{assignment.points} points ({score_status})"

        total_submissions = models.Submission.objects.filter(assignment__id=assignment_id).count()
        assigned_submissions = models.Submission.objects.filter(assignment__id=assignment_id, grader__username=request.user.username).count()
        total_students = models.Group.objects.get(name="Students").user_set.count()
        return render(request, "index.html",
                    dict(assignment=assignment,
                    total_submissions=total_submissions,
                    assigned_submissions=assigned_submissions,
                    total_students=total_students,
                    is_student=is_student(request.user),
                    submission=submission,
                    submission_status=submission_status,
                    is_due=is_due))
    else:
        return redirect("submit_form", assignment_id)

@user_passes_test(is_student)
@login_required
def submit_form(request, assignment_id):
    assignment = get_object_or_404(models.Assignment, pk=assignment_id)
    current_date = timezone.now()
    if assignment.deadline <= current_date:
        return HttpResponseBadRequest("Assignment is past due.")
    else:
        submitted_file = request.FILES.get('file')
        print(submitted_file)
        # Look up the current user's submission for that assignment
        submission, created = models.Submission.objects.get_or_create(assignment=assignment, author=request.user,
                                                                      score=None, grader=pick_grader(assignment),
                                                                      defaults={'file': submitted_file})
        if not created:
            submission.file = submitted_file
    try:
        submission.save()
    except Exception as e:
        print(f"error saving submission: {e}")
    return redirect(f"/{assignment_id}/")

def pick_grader(assignment):
    ta_set = models.Group.objects.get(name="Teaching Assistants").user_set.annotate(total_assigned=Count("graded_set", filter=Q(graded_set__assignment=assignment)))
    ordered_ta_set = ta_set.order_by("total_assigned")
    print(type(ordered_ta_set[0]))
    return ordered_ta_set[0]

@login_required
def show_upload(request, filename):
    submission = models.Submission.objects.get(file=filename)
    if not (request.user == submission.author or request.user == submission.grader or is_administrative(request.user)):
        print("permission denied")
        raise PermissionDenied("You do not have permission")
    else:
        with submission.file.open() as fd:
            response = HttpResponse(fd)
            response["Content-Disposition"] = \
                f'attachment; filename="{submission.file.name}"'
            return response

@user_passes_test(is_ta_or_administrative)
@login_required
def submissions(request, assignment_id):
    assignment = get_object_or_404(models.Assignment, pk=assignment_id)
    if is_ta(request.user):
        assigned_submissions = models.Submission.objects.filter(assignment__id=assignment_id, grader__username=request.user.username).order_by("author")
    elif is_administrative(request.user):
        assigned_submissions = models.Submission.objects.filter(assignment__id=assignment_id).order_by("author")
    return render(request, "submissions.html",
                  dict(assignment=assignment,
                  assigned_submissions=assigned_submissions,
                  assignment_id=assignment_id))

@login_required
def profile(request):
    assignments = models.Assignment.objects.order_by("deadline")
    assignment_data = []
    final_grade = 0
    if is_ta(request.user):
        for assignment in assignments:
            assigned_submissions = models.Submission.objects.filter(assignment=assignment, grader__username=request.user.username).count()
            graded_submissions = models.Submission.objects.filter(assignment=assignment, grader__username=request.user.username).exclude(score__isnull=True).count()
            assignment_data.append({'assignment':assignment,
                                    'assigned_submissions':assigned_submissions,
                                    'graded_submissions':graded_submissions})
    elif is_administrative(request.user):
        for assignment in assignments:
            assigned_submissions = models.Submission.objects.filter(assignment=assignment).count()
            graded_submissions = models.Submission.objects.filter(assignment=assignment).exclude(score__isnull=True).count()
            assignment_data.append({'assignment':assignment,
                                    'assigned_submissions':assigned_submissions,
                                    'graded_submissions':graded_submissions})
    else:
        current_date = timezone.now()
        total_points = 0
        total_available_points = 0
        for assignment in assignments:
            print(assignment.title)
            print("weight" + str(assignment.weight))
            try:
                submission = models.Submission.objects.get(assignment=assignment, author__username=request.user.username)
                submission_score = submission.score
                submission_exists = True
            except models.Submission.DoesNotExist:
                submission_exists = False
                submission_score = 0

            if (assignment.deadline > current_date) and (not submission_exists):
                score_status = "Not Due"
            elif assignment.deadline <= current_date and (not submission_exists):
                score_status = "Missing"
                total_available_points += assignment.weight
            else:
                if(submission_score == None):
                    score_status = "Ungraded"
                else:
                    max_score = assignment.points
                    weighted_grade = calculate_weighted_grade(submission_score, max_score, assignment.weight)
                    score_status = format(submission_score/max_score, ".1%")
                    total_points += weighted_grade
                    total_available_points += assignment.weight

            assignment_data.append({'assignment':assignment,
                                    'score_status':score_status})
        final_grade= format(total_points/total_available_points, ".1%")
    return render(request, "profile.html", dict(assignment_data=assignment_data,
                                                user=request.user,
                                                is_student=is_student(request.user),
                                                final_grade=final_grade))

@csrf_protect
def login_form(request):
    if request.method == "POST":
        username = request.POST.get("username", "")
        password = request.POST.get("password", "")
        user = authenticate(request, username=username, password=password)
        if user is not None:
            print("there is a user")
            login(request, user)
            next_url = request.POST.get('next', '/profile/')
            print(next_url)
            return redirect(next_url)
        else:
            print("there is not a user")
            next_url = request.GET.get('next', '/profile/')
            print(next_url)
            return render(request, "login.html", dict(next_url=next_url,
                                                      error="Username and password do not match"))
    else:
        next_url = request.GET.get('next', '/profile/')
        print(next_url)
        return render(request, "login.html", dict(next_url=next_url))
    
@csrf_protect
def logout_form(request):
    logout(request)
    return redirect("/profile/login/")

@user_passes_test(is_ta)
@login_required
@csrf_protect
def grade(request, assignment_id):
    if request.method == "POST":
        for key in request.POST:
            if(key.startswith("grade-")):
                try:
                    submission_id = int(key.split("-")[1])
                    submission = get_object_or_404(models.Submission, pk=submission_id)
                    print("previous score: " + str(submission.score))
                    submission.score = float(request.POST[key])
                    submission.save()
                    print("current score: " + str(submission.score))
                except (ValueError, models.Submission.DoesNotExist):
                    submission.score = None
                    submission.save()
                    print("did not work")
        return redirect("submissions", assignment_id)
    else:
        return render(request, "submissions.html", assignment_id)