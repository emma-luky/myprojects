/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: framesbar.cpp
    Description: Class for the spriteEditor model, which holds the logic for creating, handling, editing, and loading sprites.

Reviewed by:
*/

#ifndef FRAMESBAR_H
#define FRAMESBAR_H

#include <QWidget>
using namespace std;

namespace Ui {
class FramesBar;
}

class FramesBar : public QWidget
{
    Q_OBJECT

public:
    explicit FramesBar(QWidget *parent = nullptr);
    ~FramesBar();

public slots:
    void showImages(std::vector<QImage*> img);
    void addNewFrame();
    void changeCurrentImage();
    void deleteCurrentFrame();

signals:
    void addPushed();
    void deletePushed();
    void imageClicked(QImage* img);
    void currentImageChanged(QImage* img);
    void currentFrameDeleted(QImage* img);

private:
    Ui::FramesBar *ui;
    QImage* currentImage;
};

#endif // FRAMESBAR_H
