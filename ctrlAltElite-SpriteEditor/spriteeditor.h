/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: spriteeditor.h
    Description: Defines the class for the spriteEditor model, which holds the logic for creating, handling, editing, and loading sprites.

Reviewed by: Emma Luk
*/

#ifndef SPRITEEDITOR_H
#define SPRITEEDITOR_H

#include <QWidget>
#include <QImage>
#include "sprite.h"
#include "enumTools.h"

class SpriteEditor : public QWidget
{
    Q_OBJECT
public:
    explicit SpriteEditor(QWidget *parent = nullptr);

private:
    //variables
    std::vector<QImage*> frames;
    QImage* currentImage;
    int clicks = 0;
    int x0;
    int y0;
    const double CANVAS_SIZE = 450;
    QColor currentColor = Qt::black;
    enumTools::Tool currentTool = enumTools::Tool::pen;

    //methods
    ///
    /// \brief createBlankCanvas -> creates a the first image in a new sprite of the given size and displays it on the canvas
    /// \param size -> the size of the sprite (i.e. 16, 24, 32, 48)
    ///
    void createBlankCanvas(int size);

    ///
    /// \brief scaleCurrentImageToPixmap -> scales the current image to a pixmap of CANVAS_SIZE
    /// \return the scaled pixmap - ready to be displayed on the canvas
    ///
    QPixmap scaleCurrentImageToPixmap();

    ///
    /// \brief calculateActualPixel -> calculates the pixel on the image based on where the user clicked on the scaled pixmap
    /// \return the pixel as a QPoint
    ///
    QPoint calculateActualPixel(QPoint);

    ///
    /// \brief fillPixelsAround -> used by the fillBucket tool to recursively traverse pixels outward and fill adjacent
    /// colors of the original color to the currentColor
    ///
    void fillPixelsAround(QPoint, QColor);

    ///
    /// \brief drawLine: if the slope is less than 1 or greater than -1 use drawLineLow
    /// if the slope is greater than or equal to 1 or less than or equal to -1 use drawLineHigh
    /// \param x0: x positon of the inital first click
    /// \param y0: y positon of the inital first click
    /// \param x1: x positon of the second click
    /// \param y1: y positon of the second click
    ///
    void drawLine(int x0, int y0, int x1, int y1);

    ///
    /// \brief drawLineLow: draws a line based on the location of the first and second click
    /// \param x0: x positon of the inital first click
    /// \param y0: y positon of the inital first click
    /// \param x1: x positon of the second click
    /// \param y1: y positon of the second click
    ///
    void drawLineLow(int x0, int y0, int x1, int y1);

    ///
    /// \brief drawLineHigh: draws a line based on the location of the first and second click
    /// \param x0: x positon of the inital first click
    /// \param y0: y positon of the inital first click
    /// \param x1: x positon of the second click
    /// \param y1: y positon of the second click
    ///
    void drawLineHigh(int x0, int y0, int x1, int y1);

    ///
    /// \brief drawRectangle: draws a rectangle based on the location of the first and second click
    /// \param x0: x positon of the inital first click
    /// \param y0: y positon of the inital first click
    /// \param x1: x positon of the second click
    /// \param y1: y positon of the second click
    /// \param dx: difference between x1 and x0, ie dx = x1-x0
    /// \param dy: difference between y1 and y0, ie dy = y1-y0
    ///
    void drawRectangle(int x0, int y0, int x1, int y1, int dx, int dy);

    ///
    /// \brief drawCircle: draws a circle based on the location of the first and second click
    /// \param x0: x positon of the inital first click, ie the x position of the center of the circle
    /// \param y0: y positon of the inital first click, ie the y position of the center of the circle
    /// \param r: radius of the circle
    ///
    void drawCircle(int x0, int y0, int r);

public slots:
    ///
    /// \brief createNewSprite -> sends the necessary signals to update the UI to create a new sprite and calls createBlankCanvas
    /// \param size -> the size of the sprite (i.e. 16, 24, 32, 48)
    ///
    void createNewSprite(int size);

    ///
    /// \brief handlePixelClicked -> based off of the currentTool, performs the tool's action on the pixel
    /// \param point -> the pixel that was clicked
    /// \param event -> the mouse event (i.e. MouseButtonPress (click) or MouseMove(drag))
    ///
    void handlePixelClicked(QPoint point, QMouseEvent* event);

    ///
    /// \brief updateCurrentTool: listens for toolChosen signal and updates currentTool varible
    /// to the value with toolChosen
    ///
    void updateCurrentTool(enumTools::Tool);
    void changeColor(QColor);
    void createNewFrame();
    void imageDeleted(QImage*);
    void currentImageUpdated(QImage*);
    void saveToComputer(QString fileName);

    ///
    /// \brief loadExistingSprite -> given the sprite object, loads the frames and updates the UI
    /// \param sprite -> the Sprite object to load
    ///
    void loadExistingSprite(Sprite sprite);
    void handlePixelClicked(QPoint);

signals:
    void switchToEditorView();
    void displayCanvasImage(QPixmap);
    void updateColorPicker(QColor);
    void updateFrames(std::vector<QImage*>);
};

#endif // SPRITEEDITOR_H
