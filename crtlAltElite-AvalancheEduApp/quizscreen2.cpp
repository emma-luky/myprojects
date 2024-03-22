/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A9-Educational App

File: QuizScreen2.h
    Description: A quiz page for module 2
*/

#include "quizscreen2.h"
#include "ui_quizscreen2.h"

QuizScreen2::QuizScreen2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuizScreen2)
{
    ui->setupUi(this);
    ui->nextButton->setEnabled(false);
    ui->submitMessage->hide();

    connect(ui->submitButton,
            &QPushButton::clicked,
            this,
            &QuizScreen2::submitClicked);

    connect(ui->backButton,
            &QPushButton::clicked,
            this,
            &QuizScreen2::backClicked);

    connect(ui->nextButton,
            &QPushButton::clicked,
            this,
            &QuizScreen2::nextClicked);
}

QuizScreen2::~QuizScreen2()
{
    delete ui;
}

void QuizScreen2::submitClicked(){
    if (ui->c1->isChecked() && ui->d2->isChecked() && ui->c3->isChecked() && ui->a4->isChecked()) {
        ui->nextButton->setEnabled(true);
        ui->submitMessage->setText("You got all the questions right!");
    }
    else {
        QString currentMessage = "Fix the answers to question(s) ";
        if (!(ui->c1->isChecked())) {
            currentMessage += "1 ";
        }
        if (!(ui->d2->isChecked())) {
            currentMessage += "2 ";
        }
        if (!(ui->c3->isChecked())) {
            currentMessage += "3 ";
        }
        if (!(ui->a4->isChecked())) {
            currentMessage += "4 ";
        }
        ui->submitMessage->setText(currentMessage);
    }
    ui->submitMessage->show();
}

void QuizScreen2::backClicked() {
    emit goBackToModule2();
}

void QuizScreen2::nextClicked() {
    emit goToNextModule();
}
