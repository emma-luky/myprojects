#include "learningscreen1.h"
#include "ui_learningscreen1.h"

LearningScreen1::LearningScreen1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LearningScreen1)
{
    ui->setupUi(this);
    ui->scrollAreaWidgetContents->setMinimumHeight(0);
    ui->scrollArea->setFrameShape(QFrame::NoFrame);

    connect(ui->nextButton,
            &QPushButton::clicked,
            this,
            &LearningScreen1::nextClicked);
    connect(ui->backButton,
            &QPushButton::clicked,
            this,
            &LearningScreen1::backClicked);

    connect(ui->snowfallButton,
            &QPushButton::clicked,
            this,
            &LearningScreen1::snowfallClicked);

    connect(ui->tempChangesButton,
            &QPushButton::clicked,
            this,
            &LearningScreen1::temperatureChangedClicked);
    connect(ui->vibrationsButton,
            &QPushButton::clicked,
            this,
            &LearningScreen1::vibrationsClicked);
    connect(ui->steepSlopesButton,
            &QPushButton::clicked,
            this,
            &LearningScreen1::steepSlopesCLicked);
}

LearningScreen1::~LearningScreen1()
{
    delete ui;
}

void LearningScreen1::nextClicked(){
    emit next();
}

void LearningScreen1::backClicked(){
    emit back();
}

void LearningScreen1::snowfallClicked(){
    snowFallButtonClicked = true;
    if(snowFallButtonClicked && tempChangesButtonClicked && vibrationsButtonClicked && steepSlopesButtonClicked){
        ui->nextButton->setEnabled(true);
    }
    // change info window
    ui->infoTitle->setText("Heavy Snowfall");
    ui->infoWindow->setText("<style> li{ margin-bottom:20px;;} </style>"
                            "<ul>"
                            "<li>"
                            "During a storm wind normally blows from one "
                            "side of the slope of mountain to another side, "
                            "but can also blow upwards scouring snow off the "
                            "surface, which can overhang a mountain."
                            "</li>"
                            "<li>"
                            "It deposits snow in unstable areas and puts "
                            "pressure on the snow-pack"
                            "</li>"
                            "<li>"
                            "If new snow piles up during a storm, the "
                            "snowpack may become overloaded, setting off a "
                            "slide"
                            "</li>"
                            "<li>"
                            "The 24 hours after a storm are considered to "
                            "be the most critical"
                            "</li>"
                            "</ul>");
    ui->scrollAreaWidgetContents->setMinimumHeight(600);
    //change animation
    QPixmap pixmap(":/images/heavySnow.jpeg");
    ui->picture->setPixmap(pixmap);
}

void LearningScreen1::temperatureChangedClicked(){
    ui->scrollAreaWidgetContents->setMinimumHeight(0);
    tempChangesButtonClicked = true;
    if(snowFallButtonClicked && tempChangesButtonClicked && vibrationsButtonClicked && steepSlopesButtonClicked){
        ui->nextButton->setEnabled(true);
    }
    // change info window
    ui->infoTitle->setText("Varying Thawing and Freezing Cycles");
    ui->infoWindow->setText("<style> li{ margin-bottom:20px;;} </style>"
                            "<ul>"
                            "<li>"
                            "Warm temperatures that can last several hours "
                            "a day can weaken some of the upper layers of "
                            "snow and cause it to slide down"
                            "</li>"
                            "<li>"
                            "Melted snow that refreezes may cause a slick "
                            "coating of ice to form on the surface of a layer"
                            "</li>"
                            "<li>"
                            "A new snowfall may not stick to this slippery "
                            "layer, and it may slide off."
                            "</li>"
                            "</ul>");

    QPixmap pixmap(":/images/tempuratureChange.jpg");
    ui->picture->setPixmap(pixmap);
}

void LearningScreen1::steepSlopesCLicked(){
    ui->scrollAreaWidgetContents->setMinimumHeight(0);
    steepSlopesButtonClicked = true;
    if(snowFallButtonClicked && tempChangesButtonClicked && vibrationsButtonClicked && steepSlopesButtonClicked){
        ui->nextButton->setEnabled(true);
    }
    // change info window
    ui->infoTitle->setText("Steep Slopes");
    ui->infoWindow->setText("<style> li{ margin-bottom:20px;;} </style>"
                            "<ul>"
                            "<li>"
                            "Steepeness fo the mountain side can increase "
                            "the speed of avalanches"
                            "</li>"
                            "<li>"
                            "Layers of snow build up and slide down the "
                            "mountain"
                            "</li>"
                            "</ul>");
    QPixmap pixmap(":/images/steepSlope.jpg");
    ui->picture->setPixmap(pixmap);
}

void LearningScreen1::vibrationsClicked(){
    ui->scrollAreaWidgetContents->setMinimumHeight(0);
    vibrationsButtonClicked = true;
    if(snowFallButtonClicked && tempChangesButtonClicked && vibrationsButtonClicked && steepSlopesButtonClicked){
        ui->nextButton->setEnabled(true);
    }
    // change info window
    ui->infoTitle->setText("Vibration Movements");
    ui->infoWindow->setText("<style> li{ margin-bottom:20px;} </style>"
                            "<ul>"
                            "<li>"
                            "Vibration movements Ccan include humans, "
                            "wildlife, all terrain vehicles, earthquakes, "
                            "explosives, etc"
                            "</li>"
                            "<li>"
                            "By itself, but especially in combination with "
                            "any of the other causes, added weight or "
                            "vibration, can easily send the top layers of a "
                            "snow pack hurtling downhill"
                            "</li>"
                            "</ul>");

    QPixmap pixmap(":/images/humanActivity.jpg");
    ui->picture->setPixmap(pixmap);
}
