#include "learningscreen2.h"
#include "ui_learningscreen2.h"

LearningScreen2::LearningScreen2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LearningScreen2)
{
    ui->setupUi(this);
    ui->scrollAreaWidgetContents->setMinimumHeight(0);
    ui->scrollArea->setFrameShape(QFrame::NoFrame);

    connect(ui->nextButton,
            &QPushButton::clicked,
            this,
            &LearningScreen2::nextClicked);
    connect(ui->backButton,
            &QPushButton::clicked,
            this,
            &LearningScreen2::backClicked);

    connect(ui->looseSnowButton,
            &QPushButton::clicked,
            this,
            &LearningScreen2::looseSnowClicked);
    connect(ui->slabButton,
            &QPushButton::clicked,
            this,
            &LearningScreen2::slabClicked);
    connect(ui->powderSnowButton,
            &QPushButton::clicked,
            this,
            &LearningScreen2::powderSnowClicked);
    connect(ui->wetSnowButton,
            &QPushButton::clicked,
            this,
            &LearningScreen2::wetSnowClicked);

    QPixmap pixmap(":/images/mountain.png");
    ui->label->setPixmap(pixmap);
}

LearningScreen2::~LearningScreen2()
{
    delete ui;
}

void LearningScreen2::nextClicked(){
    emit next();
}

void LearningScreen2::backClicked(){
    emit back();
}

void LearningScreen2::looseSnowClicked(){
    looseSnowButtonClicked = true;
    if(looseSnowButtonClicked && slabButtonClicked && powderSnowButtonClicked && wetSnowButtonClicked){
        ui->nextButton->setEnabled(true);
    }
    // change info window
    ui->infoTitle->setText("Loose Snow Avalanche");
    ui->infoWindow->setText("<style> li{ margin-bottom:20px;;} </style>"
                            "<ul>"
                            "<li>"
                            "They are common on steep slopes and are seen "
                            "after a fresh snowfall"
                            "</li>"
                            "<li>"
                            "Since the snow does not have time to settle down "
                            "fully or has been made loose by sunlight, the "
                            "snow-pack is not very solid"
                            "</li>"
                            "<li>"
                            "Such avalanches have a single point of origin, "
                            "from where they widen as they travel down the "
                            "slope"
                            "</li>"
                            "</ul>");
    ui->scrollAreaWidgetContents->setMinimumHeight(0);
    resetAvalanches();
    slabAvalancheController = new AvalancheController(this, ui, avalancheTypes::avalancheTypes::looseSnow);
    slabAvalancheController->startAnimation();

}
void LearningScreen2::slabClicked(){
    slabButtonClicked = true;
    if(looseSnowButtonClicked && slabButtonClicked && powderSnowButtonClicked && wetSnowButtonClicked){
        ui->nextButton->setEnabled(true);
    }
    // change info window
    ui->infoTitle->setText("Slab Avalanche");
    ui->infoWindow->setText("<style> li{ margin-bottom:20px;;} </style>"
                            "<ul>"
                            "<li>"
                            "Loose Snow Avalanches in turn could cause a "
                            "slab avalanche, which are characterized by the "
                            "fall of a large block of ice down the slopes"
                            "</li>"
                            "<li>"
                            "The slabs cause fairly small amount of damage, "
                            "while the thick ones are responsible for MANY "
                            "FATALITIES"
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
    resetAvalanches();
    slabAvalancheController = new AvalancheController(this, ui, avalancheTypes::avalancheTypes::slab);
    slabAvalancheController->startAnimation();

}
void LearningScreen2::powderSnowClicked(){
    powderSnowButtonClicked = true;
    if(looseSnowButtonClicked && slabButtonClicked && powderSnowButtonClicked && wetSnowButtonClicked){
        ui->nextButton->setEnabled(true);
    }
    // change info window
    ui->infoTitle->setText("Powder Snow Avalanche");
    ui->infoWindow->setText("<style> li{ margin-bottom:20px;;} </style>"
                            "<ul>"
                            "<li>"
                            "A mix of Loose Snow and Slab avalanches"
                            "</li>"
                            "<li>"
                            "The bottom half of this avalanche consists of a "
                            "slab or a dense concentration of snow, ice, and air."
                            "</li>"
                            "<li>"
                            "Above this is a cloud of powdered snow, which can "
                            "snowball into a larger avalanche as it progresses "
                            "down the slope"
                            "</li>"
                            "<li>"
                            "The speed attained by this avalanche cancross 190 "
                            "miles per hour and they can cross large distances"
                            "</li>"
                            "</ul>");
    ui->scrollAreaWidgetContents->setMinimumHeight(0);
    resetAvalanches();
    powderSnowAvalancheController = new AvalancheController(this, ui, avalancheTypes::avalancheTypes::powderSnow);
    powderSnowAvalancheController->startAnimation();
}
void LearningScreen2::wetSnowClicked(){
    wetSnowButtonClicked = true;
    if(looseSnowButtonClicked && slabButtonClicked && powderSnowButtonClicked && wetSnowButtonClicked){
        ui->nextButton->setEnabled(true);
    }
    // change info window
    ui->infoTitle->setText("Wet Snow Avalanche");
    ui->infoWindow->setText("<style> li{ margin-bottom:20px;;} </style>"
                            "<ul>"
                            "<li>"
                            "Caused by precipitation on top of the snow during the summer months"
                            "</li>"
                            "<li>"
                            "These are quite dangerous as they travel slowly "
                            "due to friction, which collects debris from the "
                            "path fairly easily"
                            "</li>"
                            "<li>"
                            "The avalanche comprises of water and snow at the "
                            "beginning, but understanding of avalanches has "
                            "showed us that it can pick up speed with ease"
                            "</li>"

                            "</ul>");
    ui->scrollAreaWidgetContents->setMinimumHeight(0);
    resetAvalanches();
    wetSnowAvalancheController = new AvalancheController(this, ui, avalancheTypes::avalancheTypes::wetSnow);
    wetSnowAvalancheController->startAnimation();
}

void LearningScreen2::resetAvalanches(){
    ui->animation->clear();

    if (slabAvalancheController) {
        slabAvalancheController->deleteLater();
        slabAvalancheController = nullptr;
    }
    if (wetSnowAvalancheController) {
        wetSnowAvalancheController->deleteLater();
        wetSnowAvalancheController = nullptr;
    }
    if (powderSnowAvalancheController) {
        powderSnowAvalancheController->deleteLater();
        powderSnowAvalancheController = nullptr;
    }
    if (looseSnowAvalancheController) {
        looseSnowAvalancheController->deleteLater();
        looseSnowAvalancheController = nullptr;
    }
}
