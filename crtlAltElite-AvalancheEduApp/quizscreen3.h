/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A9-Educational App

File: QuizScreen3.h
    Description: A quiz page for module 3
*/

#ifndef QUIZSCREEN3_H
#define QUIZSCREEN3_H

#include <QWidget>

namespace Ui {
class QuizScreen3;
}

class QuizScreen3 : public QWidget
{
    Q_OBJECT

public:
    explicit QuizScreen3(QWidget *parent = nullptr);
    ~QuizScreen3();

private:
    Ui::QuizScreen3 *ui;

public slots:
    //A slot to manage the submit button press
    void submitClicked();

    //A slot to manage the back button press
    void backClicked();

    //A slot to manage the next button press
    void nextClicked();

signals:
    void goToNextModule();
    void goBackToModule3();
};

#endif // QUIZSCREEN3_H
