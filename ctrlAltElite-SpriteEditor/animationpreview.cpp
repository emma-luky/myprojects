/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: animationpreview.cpp
    Description: updates the animation preview widget UI

Reviewed by: Lindsey Peterson
*/

#include "animationpreview.h"
#include "ui_animationpreview.h"
#include <QTimer>

animationpreview::animationpreview(QWidget *parent) :
    QWidget(parent),
    frames{ },
    fps(20),
    ui(new Ui::animationpreview)
{
    ui->setupUi(this);

    ui->fpsSlider->setTickPosition(QSlider::TicksBelow);
    ui->fpsSlider->setTickInterval(100);
    connect(ui->fpsSlider,
            &QSlider::valueChanged,
            this,
            &animationpreview::updateFps);

    framesIt = frames.begin();
    connect(&previewTimer,
            &QTimer::timeout,
            this,
            &animationpreview::runPreview);
    previewTimer.start(fps);
}

animationpreview::~animationpreview(){
    delete ui;
}

void animationpreview::updateFrames(std::vector<QImage*> newFrames){
    frames = newFrames;
    framesIt = frames.begin();
}

void animationpreview::runPreview(){
    if(framesIt != frames.end()){
        QImage currentFrame = **framesIt;
        ui->previewLabel->setPixmap(QPixmap::fromImage(currentFrame).scaled(ANIMATION_LABEL_SIZE, ANIMATION_LABEL_SIZE,Qt::KeepAspectRatio));
        ++framesIt;
    }
    else{
        framesIt = frames.begin();
    }
}

void animationpreview::updateFps(){
    fps = ui->fpsSlider->value();
    previewTimer.start(fps);
}
