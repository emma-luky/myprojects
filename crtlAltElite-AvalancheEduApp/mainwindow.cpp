#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pages->setCurrentWidget(ui->startScreen);

    connect(ui->startScreen,
            &StartScreen::startClicked,
            this,
            &MainWindow::switchToModulesView);

    connect(ui->modules,
            &ModulesView::startMod1,
            this,
            &MainWindow::switchToModule1);

    connect(ui->modules,
            &ModulesView::startMod2,
            this,
            &MainWindow::switchToModule2);

    connect(ui->modules,
            &ModulesView::startMod3,
            this,
            &MainWindow::switchToModule3);

    connect(ui->learningScreen1,
            &LearningScreen1::back,
            this,
            &MainWindow::switchToModulesView);
    connect(ui->learningScreen1,
            &LearningScreen1::next,
            this,
            &MainWindow::switchToQuiz1);

    connect(ui->quizScreen1,
            &QuizScreen1::goToNextModule,
            this,
            &MainWindow::completeModule1);

    connect(ui->learningScreen2,
            &LearningScreen2::back,
            this,
            &MainWindow::switchToModulesView);

    connect(ui->learningScreen2,
            &LearningScreen2::next,
            this,
            &MainWindow::switchToQuiz2);

    connect(ui->quizScreen2,
            &QuizScreen2::goToNextModule,
            this,
            &MainWindow::completeModule2);

    connect(ui->learningScreen3,
            &LearningScreen3::back,
            this,
            &MainWindow::switchToModulesView);
    connect(ui->learningScreen3,
            &LearningScreen3::next,
            this,
            &MainWindow::switchToQuiz3);

    connect(ui->quizScreen3,
            &QuizScreen3::goToNextModule,
            this,
            &MainWindow::completeModule3);

    connect(ui->quizScreen1,
            &QuizScreen1::goBackToModule1,
            this,
            &MainWindow::switchToModule1);

    connect(ui->quizScreen2,
            &QuizScreen2::goBackToModule2,
            this,
            &MainWindow::switchToModule2);

    connect(ui->quizScreen3,
            &QuizScreen3::goBackToModule3,
            this,
            &MainWindow::switchToModule3);

    connect(ui->modules,
            &ModulesView::showCertificate,
            this,
            &MainWindow::switchToEndScreen);

    connect(this,
            &MainWindow::unlockModule,
            ui->modules,
            &ModulesView::unlockModule);
    connect(ui->endScreen,
            &EndScreen::backClicked,
            this,
            &MainWindow::backFromEndScreen);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::backFromEndScreen(){
    emit unlockModule(4);
    switchToModulesView();
}
void MainWindow::switchToModulesView(){
    ui->pages->setCurrentWidget(ui->modules);
}

void MainWindow::switchToModule1(){
    ui->pages->setCurrentWidget(ui->learningScreen1);
}

void MainWindow::switchToQuiz1(){
    ui->pages->setCurrentWidget(ui->quizScreen1);
}

void MainWindow::completeModule1(){
    emit unlockModule(2);
    ui->pages->setCurrentWidget(ui->modules);
}
void MainWindow::switchToModule2(){
    ui->pages->setCurrentWidget(ui->learningScreen2);
}

void MainWindow::switchToQuiz2(){
    ui->pages->setCurrentWidget(ui->quizScreen2);
}

void MainWindow::completeModule2(){
    emit unlockModule(3);
    ui->pages->setCurrentWidget(ui->modules);
}
void MainWindow::switchToModule3(){
    ui->pages->setCurrentWidget(ui->learningScreen3);
}

void MainWindow::switchToQuiz3(){
    ui->pages->setCurrentWidget(ui->quizScreen3);
}

void MainWindow::completeModule3(){
    emit unlockModule(4); //not actual module 4, just unlocks certificate
    ui->pages->setCurrentWidget(ui->modules);
}
void MainWindow::switchToEndScreen(){
    ui->pages->setCurrentWidget(ui->endScreen);
}
