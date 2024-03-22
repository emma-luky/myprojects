/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A9 - Educational App

File: modulesView.h
    Description: The modules view page for the user to see which module they are on

*/
#ifndef MODULESVIEW_H
#define MODULESVIEW_H

#include <QWidget>

namespace Ui {
class ModulesView;
}

class ModulesView : public QWidget
{
    Q_OBJECT

public:
    explicit ModulesView(QWidget *parent = nullptr);
    ~ModulesView();

signals:
    void startMod1();
    void startMod2();
    void startMod3();
    void showCertificate();

private:
    Ui::ModulesView *ui;

public slots:
    // unlocks the next module (if 2 or 3) or opens the completion page(if 4)
    void unlockModule(int level);
};

#endif // MODULESVIEW_H
