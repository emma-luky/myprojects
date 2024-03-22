/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: toolbar.h
    Description: Defines the class for the toolbar widget, which displays all the types of tools. Detects when a tool is clicked
    and when a color is changed.

Reviewed by:
*/

#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include "enumTools.h"

namespace Ui {
class Toolbar;
}

class Toolbar : public QWidget
{
    Q_OBJECT

public:
    explicit Toolbar(QWidget *parent = nullptr);
    ~Toolbar();

private:
    Ui::Toolbar *ui;

    ///
    /// \brief penClicked: when the penButton is pushed it changes the button border to black
    /// and emits a toolChosen signal with the pen tool as the the param value.
    ///
    void penClicked();

    ///
    /// \brief eraserClicked: when the eraserButton is pushed it changes the button border to black
    /// and emits a toolChosen signal with the eraser tool as the the param value.
    ///
    void eraserClicked();

    ///
    /// \brief fillBucketClicked: when the fillBucketButton is pushed it changes the button border to black
    /// and emits a toolChosen signal with the fillBucket tool as the the param value.
    ///
    void fillBucketClicked();

    ///
    /// \brief rectangleClicked: when the rectangleButton is pushed it changes the button border to black
    /// and emits a toolChosen signal with the rectangle tool as the the param value.
    ///
    void rectangleClicked();

    ///
    /// \brief circleClicked: when the circleButton is pushed it changes the button border to black
    /// and emits a toolChosen signal with the circle tool as the the param value.
    ///
    void circleClicked();

    ///
    /// \brief lineClicked: when the lineButton is pushed it changes the button border to black
    /// and emits a toolChosen signal with the line tool as the the param value.
    ///
    void lineClicked();

signals:
    ///
    /// \brief penChosen: sends the tool value within the parameter
    ///
    void toolChosen(enumTools::Tool);

    ///
    /// \brief penChosen: sends the color value within the parameter
    ///
    void colorChanged(QColor);

private slots:
    ///
    /// \brief changeColor: when a color is changed/chosen it emits a signal with that color
    ///
    void changeColor();

public slots:
    ///
    /// \brief updateColorPicker: updates the color picker background to the color chosen
    ///
   void updateColorPicker(QColor);

};

#endif // TOOLBAR_H
