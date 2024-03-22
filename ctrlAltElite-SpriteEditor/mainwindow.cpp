/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: mainwindow.cpp
    Description: The main window of the spriteEditor application. Defines the layout for all of the spirte editor widgets,
    and holds connect calls between widgets and the spriteEditor class

Reviewed by: Emma Luk
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"
#include "toolbar.h"

#include <QFileDialog>
#include <QDir>

MainWindow::MainWindow(SpriteEditor& spriteEditor, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //begin with startscreen showing and everything else hidden
    ui->startscreen->show();
    ui->canvas->hide();
    ui->animation->hide();
    ui->toolBar->hide();
    ui->frames->hide();
    ui->menubar->hide();

    //start screen connections
    connect(ui->startscreen,
            &StartScreen::createNewSprite,
            &spriteEditor,
            &SpriteEditor::createNewSprite);

    connect(&spriteEditor,
            &SpriteEditor::switchToEditorView,
            this,
            &MainWindow::switchToEditorView);

    connect(ui->startscreen,
            &StartScreen::loadExistingSprite,
            &spriteEditor,
            &SpriteEditor::loadExistingSprite);

    //canvas connections
    connect(&spriteEditor,
            &SpriteEditor::displayCanvasImage,
            ui->canvas,
            &Canvas::displayImage);

    connect(ui->canvas,
            &Canvas::pixelClicked,
            &spriteEditor,
            &SpriteEditor::handlePixelClicked);

    //toolbar connections
    connect(ui->toolBar,
            &Toolbar::toolChosen,
            &spriteEditor,
            &SpriteEditor::updateCurrentTool);

    connect(ui->toolBar,
            &Toolbar::colorChanged,
            &spriteEditor,
            &SpriteEditor::changeColor);

    connect(&spriteEditor,
            &SpriteEditor::updateColorPicker,
            ui->toolBar,
            &Toolbar::updateColorPicker);

    //frames connections
    connect(ui->frames,
            &FramesBar::addPushed,
            &spriteEditor,
            &SpriteEditor::createNewFrame);

    connect(&spriteEditor,
            &SpriteEditor::updateFrames,
            ui->frames,
            &FramesBar::showImages);

    connect(ui->frames,
            &FramesBar::currentFrameDeleted,
            &spriteEditor,
            &SpriteEditor::imageDeleted);

    connect(ui->frames,
            &FramesBar::currentImageChanged,
            &spriteEditor,
            &SpriteEditor::currentImageUpdated);

    connect(&spriteEditor,
            &SpriteEditor::initializeCurrentImage,
            ui->frames,
            &FramesBar::initializeCurrentImage);

    connect(&spriteEditor,
            &SpriteEditor::updateFrames,
            ui->animation,
            &animationpreview::updateFrames);

    connect(this,
            &MainWindow::saveFileToComputer,
            &spriteEditor,
            &SpriteEditor::saveToComputer);
}

void MainWindow::switchToEditorView(){
    ui->startscreen->hide();
    ui->canvas->show();
    ui->animation->show();
    ui->toolBar->show();
    ui->frames->show();
    ui->menubar->show();
}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_actionSave_triggered(){
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", QDir::homePath(), tr("SSP Files (*.ssp);;JSON Files (*.json);;All Files (*)"));
    emit saveFileToComputer(fileName);
}



