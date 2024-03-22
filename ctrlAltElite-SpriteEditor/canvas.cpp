/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: canvas.cpp
    Description: Class for the canvas widget, which displays the image and detects mouseEvents
    on pixels of the image.

Reviewed by: Lindsey Peterson
*/

#include "canvas.h"
#include "ui_canvas.h"

Canvas::Canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canvas)
{
    ui->setupUi(this);

}

Canvas::~Canvas()
{
    delete ui;
}

void Canvas::displayImage(QPixmap newImage){
    ui->imageLabel->setPixmap(newImage);
}

void Canvas::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
        QPoint clickPos = event->pos();
        emit pixelClicked(clickPos, event);
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event) {
    //check if left mouse button was held down (drag)
    if (event->buttons() & Qt::LeftButton) {
        QPoint movePos = event->pos();
        emit pixelClicked(movePos, event);
    }
}
