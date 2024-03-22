/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: mainwindow.h
    Description: Defines the main window of the spriteEditor application. Defines the layout for all of the sprte editor widgets

Reviewed by: Emma Luk
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "spriteeditor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(SpriteEditor& spriteEditor, QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    ///
    /// \brief switchToEditorView -> hides the startscreen and shows all other widgets
    ///
    void switchToEditorView();

signals:
    void saveFileToComputer(QString fileName);
private slots:
    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
