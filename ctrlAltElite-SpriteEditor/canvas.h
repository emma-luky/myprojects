/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: canvas.h
    Description: Defines the class for the canvas widget, which displays the image and detects mouseEvents
    on pixels of the image.

Reviewed by: Lindsey Peterson
*/

#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas();

signals:
    void pixelClicked(QPoint, QMouseEvent*);

public slots:
    ///
    /// \brief displayImage ->
    /// \param QPixmap ->
    ///
    void displayImage(QPixmap);

private:
    Ui::Canvas *ui;

    ///
    /// \brief mousePressEvent: tracks the event when a pixel on the image is clicked and emits a signal to the spriteEditor
    /// \param event: the mouse event
    ///

    void mousePressEvent(QMouseEvent *event) override;
    ///
    /// \brief mousePressEvent: tracks the event when a pixel on the image is dragged and emits a signal to the spriteEditor
    /// \param event: the mouse event
    ///
    void mouseMoveEvent(QMouseEvent *event) override;
};



#endif // CANVAS_H
