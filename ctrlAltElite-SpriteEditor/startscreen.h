/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: startscreen.h
    Description: Start screen widget

Reviewed by: Ricardo Baeza
*/

#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QWidget>
#include "sprite.h"

namespace Ui {
class StartScreen;
}

class StartScreen : public QWidget
{
    Q_OBJECT

public:
    explicit StartScreen(QWidget *parent = nullptr);
    ~StartScreen();

private slots:
    ///
    /// \brief showSizeOptions -> displays the size option buttons of sizes 16, 24, 32, and 48
    ///  called after the 'Create New Sprite' button is clicked
    ///
    void showSizeOptions();

signals:
    void createNewSprite(int size);
    void loadExistingSprite(Sprite sprite);


private:
    Ui::StartScreen *ui;

    ///
    /// \brief loadSprite -> allows the user to select a file and emits a signal with the file info spriteeditor to be used
    ///
    void loadSprite();
};

#endif // STARTSCREEN_H
