/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A9-Educational App

File:
    Description: Defines the functionality for module one topics
*/

#ifndef LEARNINGSCREEN1_H
#define LEARNINGSCREEN1_H

#include <QWidget>

namespace Ui {
class LearningScreen1;
}

class LearningScreen1 : public QWidget
{
    Q_OBJECT

public:
    explicit LearningScreen1(QWidget *parent = nullptr);
    ~LearningScreen1();

private:
    bool snowFallButtonClicked = false;
    bool tempChangesButtonClicked = false;
    bool vibrationsButtonClicked = false;
    bool steepSlopesButtonClicked = false;
    Ui::LearningScreen1 *ui;

    ///
    /// \brief nextClicked: emits next() to switch to the next module
    ///
    void nextClicked();

    ///
    /// \brief backClicked: emits back() to switch to the module's screen
    ///
    void backClicked();

    ///
    /// \brief snowfallClicked: starts animation, changed infoWindow to current topic,
    /// and changes snowFallButtonClicked to true
    /// Additionally, checks if all buttons have been clicked, if so, enables next button.
    ///
    void snowfallClicked();

    ///
    /// \brief temperatureChangedClicked: starts animation, changed infoWindow to current topic,
    /// and changes tempChangesButtonClicked to true
    /// Additionally, checks if all buttons have been clicked, if so, enables next button.
    ///
    void temperatureChangedClicked();

    ///
    /// \brief vibrationsClicked: starts animation, changed infoWindow to current topic,
    /// and changes vibrationsButtonClicked to true
    /// Additionally, checks if all buttons have been clicked, if so, enables next button.
    ///
    void vibrationsClicked();

    ///
    /// \brief steepSlopesCLicked: starts animation, changed infoWindow to current topic,
    /// and changes steepSlopesButtonClicked to true
    /// Additionally, checks if all buttons have been clicked, if so, enables next button.
    ///
    void steepSlopesCLicked();

signals:
    void next();
    void back();
    void newImage(QPixmap);
};

#endif // LEARNINGSCREEN1_H
