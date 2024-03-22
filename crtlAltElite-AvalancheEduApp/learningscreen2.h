/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A9-Educational App

File:
    Description: Defines the functionality for module two topics
*/

#ifndef LEARNINGSCREEN2_H
#define LEARNINGSCREEN2_H

#include <QWidget>
#include <avalancheTypes.h>
#include <avalanchecontroller.h>

namespace Ui {
class LearningScreen2;
}

class LearningScreen2 : public QWidget
{
    Q_OBJECT

public:
    explicit LearningScreen2(QWidget *parent = nullptr);
    ~LearningScreen2();

private:
    AvalancheController* slabAvalancheController;
    AvalancheController* looseSnowAvalancheController;
    AvalancheController* powderSnowAvalancheController;
    AvalancheController* wetSnowAvalancheController;

    bool looseSnowButtonClicked = false;
    bool slabButtonClicked = false;
    bool powderSnowButtonClicked = false;
    bool wetSnowButtonClicked = false;
    Ui::LearningScreen2 *ui;

    ///
    /// \brief resetAvalanches: changes the avalanche animation depending on which button was clicked
    ///
    void resetAvalanches();

    ///
    /// \brief nextClicked: emits next() to switch to the next module
    ///
    void nextClicked();

    ///
    /// \brief backClicked: emits back() to switch to the module's screen
    ///
    void backClicked();

    ///
    /// \brief looseSnowClicked: starts animation, changed infoWindow to current topic,
    /// and changes looseSnowButtonClicked to true
    /// Additionally, checks if all buttons have been clicked, if so, enables next button.
    ///
    void looseSnowClicked();

    ///
    /// \brief slabClicked: starts animation, changed infoWindow to current topic,
    /// and changes slabButtonClicked to true
    /// Additionally, checks if all buttons have been clicked, if so, enables next button.
    ///
    void slabClicked();

    ///
    /// \brief powderSnowClicked: starts animation, changed infoWindow to current topic,
    /// and changes powderSnowButtonClicked to true
    /// Additionally, checks if all buttons have been clicked, if so, enables next button.
    ///
    void powderSnowClicked();

    ///
    /// \brief wetSnowClicked: starts animation, changed infoWindow to current topic,
    /// and changes wetSnowButtonClicked to true
    /// Additionally, checks if all buttons have been clicked, if so, enables next button.
    ///
    void wetSnowClicked();

signals:
    void next();
    void back();
    void avalancheType(avalancheTypes::avalancheTypes);
};

#endif // LEARNINGSCREEN2_H
