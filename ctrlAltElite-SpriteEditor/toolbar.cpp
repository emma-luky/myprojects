/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: toolbar.cpp
    Description: updates the toolbar widget UI and sends signals when a tool or color is chosen

Reviewed by: Ricardo Baeza
*/

#include "toolbar.h"
#include "ui_toolbar.h"
#include <QColorDialog>

Toolbar::Toolbar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Toolbar)
{
    ui->setupUi(this);

    ui->penButton->setStyleSheet( QString("QPushButton {border: 2px solid black;}"));
    ui->penButton->setIcon(QIcon(":/icons/penIcon.png"));
    ui->penButton->setIconSize(QSize(30, 30));
    ui->lineButton->setIcon(QIcon(":/icons/lineIcon.png"));
    ui->lineButton->setIconSize(QSize(40, 40));
    ui->rectangleButton->setIcon(QIcon(":/icons/rectangleIcon.png"));
    ui->rectangleButton->setIconSize(QSize(30, 30));
    ui->circleButton->setIcon(QIcon(":/icons/circleIcon.png"));
    ui->circleButton->setIconSize(QSize(30, 30));
    ui->fillBucketButton->setIcon(QIcon(":/icons/fillBucketIcon.png"));
    ui->fillBucketButton->setIconSize(QSize(30, 30));
    ui->eraserButton->setIcon(QIcon(":/icons/eraserIcon.png"));
    ui->eraserButton->setIconSize(QSize(30, 30));

    connect(ui->penButton,
            &QPushButton::clicked,
            this,
            &Toolbar::penClicked);
    connect(ui->lineButton,
            &QPushButton::clicked,
            this,
            &Toolbar::lineClicked);
    connect(ui->rectangleButton,
            &QPushButton::clicked,
            this,
            &Toolbar::rectangleClicked);
    connect(ui->circleButton,
            &QPushButton::clicked,
            this,
            &Toolbar::circleClicked);
    connect(ui->fillBucketButton,
            &QPushButton::clicked,
            this,
            &Toolbar::fillBucketClicked);
    connect(ui->eraserButton,
            &QPushButton::clicked,
            this,
            &Toolbar::eraserClicked);

    connect(ui->colorPicker,
            &QPushButton::clicked,
            this,
            &Toolbar::changeColor);

}

Toolbar::~Toolbar(){
    delete ui;
}

void Toolbar::penClicked(){
    ui->penButton->setStyleSheet( QString("QPushButton {border: 2px solid black;}"));
    ui->lineButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->rectangleButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->circleButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->fillBucketButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->eraserButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    emit toolChosen(enumTools::Tool::pen);
}

void Toolbar::lineClicked(){
    ui->penButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->lineButton->setStyleSheet( QString("QPushButton {border: 2px solid black;}"));
    ui->rectangleButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->circleButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->fillBucketButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->eraserButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    emit toolChosen(enumTools::Tool::line);
}

void Toolbar::rectangleClicked(){
    ui->penButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->lineButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->rectangleButton->setStyleSheet( QString("QPushButton {border: 2px solid black;}"));
    ui->circleButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->fillBucketButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->eraserButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    emit toolChosen(enumTools::Tool::rectangle);
}

void Toolbar::circleClicked(){
    ui->penButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->lineButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->rectangleButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->circleButton->setStyleSheet( QString("QPushButton {border: 2px solid black;}"));
    ui->fillBucketButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->eraserButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    emit toolChosen(enumTools::Tool::circle);
}

void Toolbar::fillBucketClicked(){
    ui->penButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->lineButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->rectangleButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->circleButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->fillBucketButton->setStyleSheet( QString("QPushButton {border: 2px solid black;}"));
    ui->eraserButton->setStyleSheet( QString("QPushButton {background-color: {border: 0px;}"));
    emit toolChosen(enumTools::Tool::fillBucket);
}

void Toolbar::eraserClicked(){
    ui->penButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->lineButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->rectangleButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->circleButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->fillBucketButton->setStyleSheet( QString("QPushButton {border: 0px;}"));
    ui->eraserButton->setStyleSheet( QString("QPushButton {border: 2px solid black;}"));
    emit toolChosen(enumTools::Tool::eraser);
}

void Toolbar::changeColor()
{
    QColorDialog colorDialog;
    QColor color = colorDialog.getColor();
    if (color.isValid()){
        emit colorChanged(color);
    }
}

void Toolbar::updateColorPicker(QColor color)
{
    ui->colorPicker->setStyleSheet(QString("#colorPicker{ background-color:" + color.name() + "; }"));
}
