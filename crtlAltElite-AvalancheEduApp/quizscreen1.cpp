/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A9-Educational App

File: QuizScreen1.cpp
    Description: A quiz page for module 1
*/

#include "quizscreen1.h"
#include "ui_quizscreen1.h"

using namespace std;

QuizScreen1::QuizScreen1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuizScreen1)
{
    ui->setupUi(this);
    ui->nextButton->setEnabled(false);
    ui->submitMessage->hide();

    connect(ui->submitButton,
            &QPushButton::clicked,
            this,
            &QuizScreen1::submitClicked);

    connect(ui->backButton,
            &QPushButton::clicked,
            this,
            &QuizScreen1::backClicked);

    connect(ui->nextButton,
            &QPushButton::clicked,
            this,
            &QuizScreen1::nextClicked);
}

QuizScreen1::~QuizScreen1()
{
    delete ui;
}

void QuizScreen1::submitClicked(){
    if (ui->c1->isChecked() && ui->b2->isChecked() && ui->c3->isChecked() && ui->b4->isChecked()) {
        ui->nextButton->setEnabled(true);
        ui->submitMessage->setText("You got all the questions right!");
    }
    else {
        QString currentMessage = "Fix the answers to question(s) ";
        if (!(ui->c1->isChecked())) {
            currentMessage += "1 ";
        }
        if (!(ui->b2->isChecked())) {
            currentMessage += "2 ";
        }
        if (!(ui->c3->isChecked())) {
            currentMessage += "3 ";
        }
        if (!(ui->b4->isChecked())) {
            currentMessage += "4 ";
        }
        ui->submitMessage->setText(currentMessage);
    }
    ui->submitMessage->show();
}

void QuizScreen1::backClicked() {
    emit goBackToModule1();
}

void QuizScreen1::nextClicked() {
    emit goToNextModule();
}


