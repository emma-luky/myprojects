/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: framebutton.cpp
    Description: a wrapper class for a QPushButton for the purpose of storing QImage pointers

Reviewed by: Ashlyn Hansen
*/

#include "framebutton.h"
#include "ui_framebutton.h"

FrameButton::FrameButton(QImage* img, QWidget *parent) :
    QPushButton(parent),
    ui(new Ui::FrameButton)
{
    ui->setupUi(this);
    image = img;
    connect(this,
            &QPushButton::clicked,
            this,
            &FrameButton::frameButtonPushed);
}

FrameButton::~FrameButton()
{
    delete ui;
}

void FrameButton::frameButtonPushed() {
    emit frameButtonClicked(image);
}

QImage* FrameButton::getImage() {
    return image;
}
