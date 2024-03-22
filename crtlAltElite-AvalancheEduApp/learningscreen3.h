/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A9-Educational App

File:
    Description: Defines the functionality for module three topics
*/

#ifndef LEARNINGSCREEN3_H
#define LEARNINGSCREEN3_H

#include <QWidget>

namespace Ui {
class LearningScreen3;
}

class LearningScreen3 : public QWidget
{
    Q_OBJECT

public:
    explicit LearningScreen3(QWidget *parent = nullptr);
    ~LearningScreen3();

private:
    bool avoidStormButtonCliked = false;
    bool avoidSteepSlopesButtonClicked = false;
    bool forecastButtonClicked = false;
    bool snowPitsButtonClicked = false;
    Ui::LearningScreen3 *ui;

    ///
    /// \brief nextClicked: emits next() to switch to the next module
    ///
    void nextClicked();

    ///
    /// \brief backClicked: emits back() to switch to the module's screen
    ///
    void backClicked();

    ///
    /// \brief avoidStormClicked: starts animation, changed infoWindow to current topic,
    /// and changes avoidStormButtonClicked to true
    /// Additionally, checks if all buttons have been clicked, if so, enables next button.
    ///
    void avoidStormClicked();

    ///
    /// \brief avoidSteepSlopesClicked: starts animation, changed infoWindow to current topic,
    /// and changes avoidSteepSlopesButtonClicked to true
    /// Additionally, checks if all buttons have been clicked, if so, enables next button.
    ///
    void avoidSteepSlopesClicked();

    ///
    /// \brief forecastClicked: starts animation, changed infoWindow to current topic,
    /// and changes forecastClicked to true
    /// Additionally, checks if all buttons have been clicked, if so, enables next button.
    ///
    void forecastClicked();

    ///
    /// \brief snowPitsClicked: starts animation, changed infoWindow to current topic,
    /// and changes snowPitsButtonClicked to true
    /// Additionally, checks if all buttons have been clicked, if so, enables next button.
    ///
    void snowPitsClicked();

signals:
    void next();
    void back();
};

#endif // LEARNINGSCREEN3_H
