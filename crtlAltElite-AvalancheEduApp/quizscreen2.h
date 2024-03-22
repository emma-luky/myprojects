/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A9-Educational App

File: QuizScreen2.h
    Description: A quiz page for module 2
*/

#ifndef QUIZSCREEN2_H
#define QUIZSCREEN2_H

#include <QWidget>

namespace Ui {
class QuizScreen2;
}

class QuizScreen2 : public QWidget
{
    Q_OBJECT

public:
    explicit QuizScreen2(QWidget *parent = nullptr);
    ~QuizScreen2();

private:
    Ui::QuizScreen2 *ui;

public slots:
    //A slot to manage the submit button press
    void submitClicked();

    //A slot to manage the back button press
    void backClicked();

    //A slot to manage the next button press
    void nextClicked();

signals:
    void goToNextModule();
    void goBackToModule2();
};

#endif // QUIZSCREEN2_H
