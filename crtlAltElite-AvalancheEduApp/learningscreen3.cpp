#include "learningscreen3.h"
#include "ui_learningscreen3.h"

LearningScreen3::LearningScreen3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LearningScreen3)
{
    ui->setupUi(this);
    ui->picture->setPixmap(QPixmap(":/images/snowpits.jpg"));
    ui->scrollAreaWidgetContents->setMinimumHeight(0);
    ui->scrollArea->setFrameShape(QFrame::NoFrame);

    connect(ui->nextButton,
            &QPushButton::clicked,
            this,
            &LearningScreen3::nextClicked);
    connect(ui->backButton,
            &QPushButton::clicked,
            this,
            &LearningScreen3::backClicked);

    connect(ui->avoidStormButton,
            &QPushButton::clicked,
            this,
            &LearningScreen3::avoidStormClicked);
    connect(ui->avoidSteepSlopesButton,
            &QPushButton::clicked,
            this,
            &LearningScreen3::avoidSteepSlopesClicked);
    connect(ui->forecastButton,
            &QPushButton::clicked,
            this,
            &LearningScreen3::forecastClicked);
    connect(ui->snowPitsButton,
            &QPushButton::clicked,
            this,
            &LearningScreen3::snowPitsClicked);
}

LearningScreen3::~LearningScreen3()
{
    delete ui;
}

void LearningScreen3::nextClicked(){
    emit next();
}

void LearningScreen3::backClicked(){
    emit back();
}

void LearningScreen3::avoidStormClicked(){
    ui->scrollAreaWidgetContents->setMinimumHeight(0);
    avoidStormButtonCliked = true;
    if(avoidStormButtonCliked && avoidSteepSlopesButtonClicked && forecastButtonClicked && snowPitsButtonClicked){
        ui->nextButton->setEnabled(true);
    }
    // change info window
    ui->infoTitle->setText("Avoid Hiking After a Storm");
    ui->infoWindow->setText("<style> li{ margin-bottom:20px;} </style>"
                            "<ul>"
                            "<li>"
                            "Most avalanches occur at the time of or shortly "
                            "after a heavy snowfall"
                            "</li>"
                            "</ul>");
    QPixmap pixmap(":/images/avoidSnowStorms.jpeg");

    ui->picture->setPixmap(pixmap);
}
void LearningScreen3::avoidSteepSlopesClicked(){
    ui->scrollAreaWidgetContents->setMinimumHeight(0);
    avoidSteepSlopesButtonClicked = true;
    if(avoidStormButtonCliked && avoidSteepSlopesButtonClicked && forecastButtonClicked && snowPitsButtonClicked){
        ui->nextButton->setEnabled(true);
    }
    // change info window
    ui->infoTitle->setText("Avoid Steep SLopes");
    ui->infoWindow->setText("<style> li{ margin-bottom:20px;} </style>"
                            "<ul>"
                            "<li>"
                            "Avoid slopes with pitches greater than 25 degrees"
                            "</li>"
                            "<li>"
                            "As you saw in the previous module, steep slopes "
                            "contribute to the cause of avalanches"
                            "</li>"
                            "</ul>");
    //change animation
    QPixmap pixmap(":/images/avoidSteepSlopes.jpeg");
    ui->picture->setPixmap(pixmap);

}
void LearningScreen3::forecastClicked(){
    ui->scrollAreaWidgetContents->setMinimumHeight(0);
    forecastButtonClicked = true;
    if(avoidStormButtonCliked && avoidSteepSlopesButtonClicked && forecastButtonClicked && snowPitsButtonClicked){
        ui->nextButton->setEnabled(true);
    }
    // change info window
    ui->infoTitle->setText("Check the Avalanche Forecast");
    ui->infoWindow->setText("<style> li{ margin-bottom:20px;} </style>"
                            "<ul>"
                            "<li>"
                            "Once an avalanche occurs it is more likely for "
                            "another avalanche to occur in that vicinity"
                            "</li>"
                            "<li>"
                            "Check the records for previous avalanche events"
                            "</li>"
                            "<li>"
                            "Avoid treeless slopes and gullies, the absence of "
                            "trees may reflect that previous avalanches have "
                            "occurred"
                            "</li>"
                            "</ul>");
    QPixmap pixmap(":/images/forecast.jpeg");
    ui->picture->setPixmap(pixmap);
}
void LearningScreen3::snowPitsClicked(){
    ui->scrollAreaWidgetContents->setMinimumHeight(1000);
    snowPitsButtonClicked = true;
    if(avoidStormButtonCliked && avoidSteepSlopesButtonClicked && forecastButtonClicked && snowPitsButtonClicked){
        ui->nextButton->setEnabled(true);
    }
    // change info window
    ui->infoTitle->setText("Dig Snow Pits");
    ui->infoWindow->setText("<style> li{ margin-bottom:15px;} </style>"
                            "<ul>"
                            "<li>"
                            "They can help you identify potential problems and"
                            "test instability"
                            "</li>"
                            "</ul>"

                            "<ol>"
                            "<li>"
                            "Ask “what is the season’s history?”"
                                "<ul>"
                                "<li>"
                                "seasons with persistent weak layers require "
                                "different assessment and management tools"
                                "</li>"
                                "</ul>"
                            "</li>"
                            "<li>"
                            "Choose an appropriate spot to assess stability"
                                "<ul>"
                                "<li>"
                                "You don’t want to get avalanched when "
                                "assessing the snowpack"
                                "</li>"
                                "</ul>"
                            "</li>"
                            "<li>"
                            "Probe for representative snowpack"
                                "<ul>"
                                "<li>"
                                "Dig in an average or below-average depth "
                                "spot. The goal of the pit is to assess the "
                                "worst-case scenario"
                                "</li>"
                                "</ul>"
                            "</li>"
                            "<li>"
                            "Get in your pit and do a hardness profile"
                                "<ul>"
                                "<li>"
                                "You are looking to see if there is a recipe "
                                "for an avalanche. Do you see a slab, a weaklayer, a bed "
                                "surface, etc?"
                                "</li>"
                                "</ul>"
                            "</li>"
                            "</ol>"
                            "<ul>"
                            "<li>"
                            "The results can help inform your decision making"
                            "</li>"
                            "</ul>");
    //change animation

    QPixmap pixmap(":/images/snowpits.jpeg");
    if (pixmap.isNull()) {
        ui->picture->setText("Failed to load image.");
    } else {
        ui->picture->setPixmap(pixmap);
    }

}
