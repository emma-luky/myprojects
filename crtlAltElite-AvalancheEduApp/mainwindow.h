/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A9 - Educational App

File: mainwindow.h
    Description: The main window housing the QWidgetStack with all the pages of the application

*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:

    ///
    /// \brief The following methods switch the current page on the widget stack to the designated page
    ///

    void switchToModulesView();
    void switchToModule1();
    void switchToQuiz1();
    void switchToModule2();
    void switchToQuiz2();
    void switchToModule3();
    void switchToQuiz3();
    void switchToEndScreen();

    ///
    /// \brief The following methods update the users level to the next module and unlock the necessary modules
    ///

    void completeModule1();
    void completeModule2();
    void completeModule3();

    ///
    /// \brief backFromEndScreen -> switches view from back button to end
    ///
    void backFromEndScreen();

signals:
    void unlockModule(int level);
};
#endif // MAINWINDOW_H
