/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: framesbar.cpp
    Description: A container for the different frames of the sprite that allows you to change which
    one you're working on, add new frames, and delete frames.

Reviewed by: Emma Luk
*/

#include "framesbar.h"
#include "ui_framesbar.h"
#include "framebutton.h"

#include <QPixmap>
#include <QLabel>
#include <QIcon>
#include <QObject>
#include <QHBoxLayout>

FramesBar::FramesBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FramesBar)
{
    ui->setupUi(this);
    ui->horizontalLayout->setAlignment(Qt::AlignLeft);
    ui->buttonHolder->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    connect(ui->AddFrameButton,
            &QPushButton::clicked,
            this,
            &FramesBar::addNewFrame);

    connect(ui->DeleteFrameButton,
            &QPushButton::clicked,
            this,
            &FramesBar::deleteCurrentFrame);
}

FramesBar::~FramesBar()
{
    delete ui;
}


void FramesBar::showImages(std::vector<QImage*> frames) {

    //remove all old widgets
    QLayoutItem* item;
    while ((item = ui->horizontalLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    //add new widgets
    for (QImage* frame : frames) {
        FrameButton *button = new FrameButton(frame);

        QImage scaledImage = frame->scaled(50, 50, Qt::IgnoreAspectRatio, Qt::FastTransformation);
        QPixmap scaledMap = QPixmap::fromImage(scaledImage);
        button->setIcon(QIcon(scaledMap));
        button->setIconSize(QSize(60,60));

        connect(button,
                &FrameButton::frameButtonClicked,
                this,
                &FramesBar::changeCurrentImage);
        const QSize size(80,80);
        button->setFixedSize(size);
        ui->horizontalLayout->addWidget(button);
    }
}


void FramesBar::changeCurrentImage() {
    FrameButton* buttonSender = qobject_cast<FrameButton*>(sender());
    currentImage = buttonSender->getImage();
    emit currentImageChanged(currentImage);
}

void FramesBar::addNewFrame() {
    emit addPushed();
}

void FramesBar::deleteCurrentFrame() {
    emit currentFrameDeleted(currentImage);
}

void FramesBar::initializeCurrentImage(QImage* img) {
    currentImage = img;
}
