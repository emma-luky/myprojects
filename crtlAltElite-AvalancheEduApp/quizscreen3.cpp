/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A9-Educational App

File: QuizScreen1.h
    Description: A quiz page for module 1
*/

#include "quizscreen3.h"
#include "ui_quizscreen3.h"

QuizScreen3::QuizScreen3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuizScreen3)
{
    ui->setupUi(this);
    ui->nextButton->setEnabled(false);
    ui->submitMessage->hide();

    connect(ui->submitButton,
            &QPushButton::clicked,
            this,
            &QuizScreen3::submitClicked);

    connect(ui->backButton,
            &QPushButton::clicked,
            this,
            &QuizScreen3::backClicked);

    connect(ui->nextButton,
            &QPushButton::clicked,
            this,
            &QuizScreen3::nextClicked);
}

QuizScreen3::~QuizScreen3()
{
    delete ui;
}

void QuizScreen3::submitClicked(){
    if (ui->b1->isChecked() && ui->b2->isChecked() && ui->b3->isChecked() && ui->b4->isChecked()) {
        ui->nextButton->setEnabled(true);
        ui->submitMessage->setText("You got all the questions right!");
    }
    else {
        QString currentMessage = "Fix the answers to question(s) ";
        if (!(ui->b1->isChecked())) {
            currentMessage += "1 ";
        }
        if (!(ui->b2->isChecked())) {
            currentMessage += "2 ";
        }
        if (!(ui->b3->isChecked())) {
            currentMessage += "3 ";
        }
        if (!(ui->b4->isChecked())) {
            currentMessage += "4 ";
        }
        ui->submitMessage->setText(currentMessage);
    }
    ui->submitMessage->show();
}

void QuizScreen3::backClicked() {
    emit goBackToModule3();
}

void QuizScreen3::nextClicked() {
    emit goToNextModule();
}
