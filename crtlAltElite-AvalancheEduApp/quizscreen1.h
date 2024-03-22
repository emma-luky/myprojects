/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A9-Educational App

File: QuizScreen1.h
    Description: A quiz page for module 1
*/

#ifndef QUIZSCREEN1_H
#define QUIZSCREEN1_H

#include <QWidget>

namespace Ui {
class QuizScreen1;
}

class QuizScreen1 : public QWidget
{
    Q_OBJECT

public:
    explicit QuizScreen1(QWidget *parent = nullptr);
    ~QuizScreen1();

private:
    Ui::QuizScreen1 *ui;

public slots:
    //A slot to manage the submit button press
    void submitClicked();

    //A slot to manage the back button press
    void backClicked();

    //A slot to manage the next button press
    void nextClicked();

signals:
    void goToNextModule();
    void goBackToModule1();
};

#endif // QUIZSCREEN1_H
