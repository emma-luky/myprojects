/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A9 - Educational App

File: endscreen.h
    Description: The completion page for once users make it through the entire app

*/
#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <QWidget>

namespace Ui {
class EndScreen;
}

class EndScreen : public QWidget
{
    Q_OBJECT

public:
    explicit EndScreen(QWidget *parent = nullptr);
    ~EndScreen();

private:
    Ui::EndScreen *ui;

signals:
    void backClicked();
};

#endif // ENDSCREEN_H
