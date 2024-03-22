/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: startscreen.cpp
    Description: Start screen widget

Reviewed by: Ricardo Baeza
*/

#include "startscreen.h"
#include "ui_startscreen.h"
#include "jsonparser.h"
#include <QFileDialog>

StartScreen::StartScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartScreen)
{
    ui->setupUi(this);

    ui->size16Button->hide();
    ui->size24Button->hide();
    ui->size32Button->hide();
    ui->size48Button->hide();
    ui->instructionLabel->hide();

    connect(ui->createNewButton,
            &QPushButton::clicked,
            this,
            &StartScreen::showSizeOptions);

    //size selected
    connect(ui->size16Button,
            &QPushButton::clicked,
            this,
            [this] () { emit StartScreen::createNewSprite(16);});

    connect(ui->size24Button,
            &QPushButton::clicked,
            this,
            [this] () { emit StartScreen::createNewSprite(24);});

    connect(ui->size32Button,
            &QPushButton::clicked,
            this,
            [this] () { emit StartScreen::createNewSprite(32);});

    connect(ui->size48Button,
            &QPushButton::clicked,
            this,
            [this] () { emit StartScreen::createNewSprite(48);});

    connect(ui->loadButton,
            &QPushButton::clicked,
            this,
            &StartScreen::loadSprite);

}

StartScreen::~StartScreen()
{
    delete ui;
}

void StartScreen::showSizeOptions()
{
    ui->createNewButton->hide();
    ui->loadButton->hide();
    ui->instructionLabel->show();
    ui->size16Button->show();
    ui->size24Button->show();
    ui->size32Button->show();
    ui->size48Button->show();
}

void StartScreen::loadSprite() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(),
                                                    tr("SSP Files (*.ssp);;JSON Files (*.json);;All Files (*)"));
    Sprite sprite = JsonParser::parseJson(fileName);
    emit loadExistingSprite(sprite);
}

