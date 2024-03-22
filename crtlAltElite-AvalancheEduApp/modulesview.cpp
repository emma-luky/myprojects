#include "modulesview.h"
#include "ui_modulesview.h"

ModulesView::ModulesView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModulesView)
{
    ui->setupUi(this);

    ui->mod2Button->setDisabled(true);
    ui->mod3Button->setDisabled(true);
    ui->certificateButton->hide();

    connect(ui->mod1Button,
            &QPushButton::clicked,
            this,
            [this] () {emit startMod1(); });
    connect(ui->mod2Button,
            &QPushButton::clicked,
            this,
            [this] () {emit startMod2(); });
    connect(ui->mod3Button,
            &QPushButton::clicked,
            this,
            [this] () {emit startMod3(); });

    connect(ui->certificateButton,
            &QPushButton::clicked,
            this,
            [this] () {emit showCertificate(); });
}

ModulesView::~ModulesView()
{
    delete ui;
}

void ModulesView::unlockModule(int level){
    if (level >=2){
        ui->mod2Button->setEnabled(true);
        ui->progress->setText("You have completed 1 / 3 modules");
    }
    if (level >= 3){
        ui->mod3Button->setEnabled(true);
        ui->progress->setText("You have completed 2 / 3 modules");
    }
    if (level >= 4){
        ui->certificateButton->show();
        ui->certificateButton->setEnabled(true);
        ui->progress->setText("You have completed all the modules!");
    }
}
