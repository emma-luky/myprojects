#include "startscreen.h"
#include "ui_startscreen.h"

StartScreen::StartScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartScreen)
{
    ui->setupUi(this);

    QPixmap image(":/images/bkg.png");
    ui->background->setPixmap(image);
    ui->background->lower();

    connect(ui->startButton,
            &QPushButton::clicked,
            this,
            [this] () {emit startClicked(); });
}

StartScreen::~StartScreen()
{
    delete ui;
}
