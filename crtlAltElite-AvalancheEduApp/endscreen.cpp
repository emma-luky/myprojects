#include "endscreen.h"
#include "ui_endscreen.h"

EndScreen::EndScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EndScreen)
{
    ui->setupUi(this);

    QPixmap image(":/images/bkg.png");
    ui->background->setPixmap(image);
    ui->background->lower();

    connect(ui->back,
            &QPushButton::clicked,
            this,
            &EndScreen::backClicked);
}



EndScreen::~EndScreen()
{
    delete ui;
}
