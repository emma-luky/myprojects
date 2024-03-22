/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: animationpreview.h
    Description: Defines the class for the animation preview widget, which displays the frames of the sprite.

Reviewed by: Lindsey Peterson
*/

#include <iostream>
#include <vector>
#include <QTimer>
#ifndef ANIMATIONPREVIEW_H
#define ANIMATIONPREVIEW_H

#include <QWidget>

namespace Ui {
class animationpreview;
}

class animationpreview : public QWidget {
    Q_OBJECT

public:
    explicit animationpreview(QWidget *parent = nullptr);
    ~animationpreview();
    const double ANIMATION_LABEL_SIZE = 141;
    std::vector<QImage*> frames;
    std::vector<QImage*>::iterator framesIt;
    QTimer previewTimer;
    int fps;

private:
    Ui::animationpreview *ui;

    ///
    /// \brief runPreview: Loops through the sprite frames and updating the label as it loops
    ///
    void runPreview();

    ///
    /// \brief updateFps: When the slider value is changed, it updates the fps varible value to the changed value
    ///
    void updateFps();

public slots:
    ///
    /// \brief updateFrames: Listens for the updateFrames(std::vector<QImage*>) signal. When that signal is recived
    /// it updates the frames to the frames value it recived fromthe signal
    /// \param a vector of QImage pointers
    ///
    void updateFrames(std::vector<QImage*>);
};

#endif // ANIMATIONPREVIEW_H
