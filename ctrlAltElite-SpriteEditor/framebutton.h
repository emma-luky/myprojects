/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: framebutton.h
    Description: A wrapper class for a QPushButton for the purpose of storing QImage pointers

Reviewed by: Ashlyn Hansen
*/

#ifndef FRAMEBUTTON_H
#define FRAMEBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QImage>

namespace Ui {
class FrameButton;
}

class FrameButton : public QPushButton
{
    Q_OBJECT

public:
    explicit FrameButton(QImage* img, QWidget *parent = nullptr);
    ~FrameButton();
    QImage* getImage();

public slots:
    ///
    /// \brief frameButtonPushed: emits a fameButtonClicked signal
    ///
    void frameButtonPushed();

signals:
    void frameButtonClicked(QImage*);

private:
    Ui::FrameButton *ui;
    QImage* image;
};

#endif // FRAMEBUTTON_H
