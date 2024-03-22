/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: spriteeditor.cpp
    Description: Class for the spriteEditor model, which holds the logic for creating, handling, editing, and loading sprites.

Reviewed by: Emma Luk
*/
#include <QDebug>
#include <QPainter>
#include <QRgb>
#include <QMouseEvent>
#include "jsonparser.h"
#include "spriteeditor.h"

SpriteEditor::SpriteEditor(QWidget *parent)
    : QWidget{parent}
{
}

void SpriteEditor::createNewSprite(int size){
    emit switchToEditorView();
    emit updateColorPicker(currentColor);
    createBlankCanvas(size);
}

void SpriteEditor::loadExistingSprite(Sprite sprite){
    frames = sprite.toQImagePtrList();
    currentImage = frames[0];
    emit switchToEditorView();
    emit updateColorPicker(currentColor);

    QPixmap scaledPixmap = scaleCurrentImageToPixmap();
    emit displayCanvasImage(scaledPixmap);
    emit updateFrames(frames);

}
void SpriteEditor::createBlankCanvas(int size){
    //creates blank image of actual size
    currentImage = new QImage(size, size, QImage::Format_RGB32);
    currentImage->fill(QColor(255, 255, 255).rgba());
    frames.push_back(currentImage);
    QPixmap scaledPixmap = scaleCurrentImageToPixmap();
    emit displayCanvasImage(scaledPixmap);
}

void SpriteEditor::createNewFrame(){
    createBlankCanvas(currentImage->width());
    emit updateFrames(frames);
}

QPixmap SpriteEditor::scaleCurrentImageToPixmap(){
    //creates a scaled pixmap
    QPixmap scaledPixmap(CANVAS_SIZE, CANVAS_SIZE);
    scaledPixmap.fill(Qt::white);

    QPainter painter(&scaledPixmap);
    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, false);

    //draws the scaled image with nearest-neighbor interpolation (keeps lines sharp)
    QImage scaledImage = currentImage->scaled(CANVAS_SIZE, CANVAS_SIZE, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    painter.drawImage(0, 0, scaledImage);

    //draws the gridlines
    painter.setPen(QColor(Qt::gray));

    double pixelWidth = (CANVAS_SIZE) / currentImage->width();
    for (int i = 0; i <= CANVAS_SIZE; ++i) {
        int x = static_cast<int>(i * pixelWidth + 0.5);
        int y = static_cast<int>(i * pixelWidth + 0.5);
        painter.drawLine(x, 0, x, CANVAS_SIZE);
        painter.drawLine(0, y, CANVAS_SIZE, y);
    }
    return scaledPixmap;
}

QPoint SpriteEditor::calculateActualPixel(QPoint mousePos){
    double scaledPixelWidth = (CANVAS_SIZE) / currentImage->width();

    QPoint actualPixel;
    actualPixel.setX(mousePos.x() - scaledPixelWidth/2);
    actualPixel.setY(mousePos.y() - scaledPixelWidth/2);

    //scale down
    actualPixel /= scaledPixelWidth;
    return actualPixel;
}

void SpriteEditor::updateCurrentTool(enumTools::Tool tool){
    currentTool = tool;
}

void SpriteEditor::handlePixelClicked(QPoint mousePos, QMouseEvent* event){
    if (event->type() == QEvent::MouseMove){
        clicks = 0;
    }
    else{
        clicks++;
    }

    //check in here if the pen, line, rectangle or circle is clicked
    QPoint pixel = calculateActualPixel(mousePos);

    //update image
    if (currentTool == enumTools::Tool::pen){
        currentImage->setPixel(pixel, currentColor.rgba());
        clicks = 0;
    }
    else if (currentTool == enumTools::Tool::eraser){
        currentImage->setPixel(pixel, QColor(255, 255, 255, 0).rgba());
        currentImage->setPixel(pixel, currentColor.rgba());
        QPixmap scaledPixmap = scaleCurrentImageToPixmap();
        emit displayCanvasImage(scaledPixmap);
        clicks = 0;
    }
    if (currentTool == enumTools::Tool::line && clicks >= 1 && event->type() == QEvent::MouseButtonPress){
        if(clicks == 1){
            x0 = mousePos.x();
            y0 = mousePos.y();
        }
        if(clicks == 2){
            int x1 = mousePos.x();
            int y1 = mousePos.y();
            clicks = 0;
            drawLine(x0, y0, x1, y1);
            clicks = 0;
        }
    }
    if (currentTool == enumTools::Tool::rectangle && clicks >= 1 && event->type() == QEvent::MouseButtonPress){
        if(clicks == 1){
            x0 = mousePos.x();
            y0 = mousePos.y();
        }
        if(clicks == 2){
            int x1 = mousePos.x();
            int y1 = mousePos.y();

            int dx = x1 - x0;
            int dy = y1 - y0;
            if(dx < 0 && dy < 0){
                drawRectangle(x1, y1, x0, y0, -dx, -dy);
            }
            else if(dx > 0 && dy < 0){
                drawRectangle(x0, y1, x1, y0, dx, -dy);
            }
            else if(dx < 0 && dy > 0){
                drawRectangle(x1, y0, x0, y1, -dx, dy);
            }
            else if(dx > 0 && dy > 0){
                drawRectangle(x0, y0, x1, y1, dx, dy);
            }
            else{
                currentImage->setPixel(pixel, currentColor.rgba());
                QPixmap scaledPixmap = scaleCurrentImageToPixmap();
                emit displayCanvasImage(scaledPixmap);
            }
            clicks = 0;
        }
    }
    if (currentTool == enumTools::Tool::circle && clicks >= 1 && event->type() == QEvent::MouseButtonPress){
        if(clicks == 1){
            x0 = mousePos.x();
            y0 = mousePos.y();
        }
        if(clicks == 2){
            int x1 = mousePos.x();
            int y1 = mousePos.y();
            clicks = 0;
            int dx = x1 - x0;
            int dy = y1 - y0;
            int r = sqrt((dx*dx)+(dy*dy));
            drawCircle(x0, y0, r);
            clicks = 0;
        }
    }
    else if (currentTool == enumTools::Tool::eraser){
        currentImage->setPixel(pixel, QColor(255, 255, 255).rgba());
        clicks = 0;
    }
    else if (currentTool == enumTools::Tool::fillBucket){
        QColor originalColor = currentImage->pixelColor(pixel);
        fillPixelsAround(pixel, originalColor);
        QPixmap scaledPixmap = scaleCurrentImageToPixmap();
        emit displayCanvasImage(scaledPixmap);
        clicks = 0;
    }
    QPixmap scaledPixmap = scaleCurrentImageToPixmap();
    emit displayCanvasImage(scaledPixmap);
    emit updateFrames(frames);
}

void SpriteEditor::fillPixelsAround(QPoint pixel, QColor originalColor){
    int x = pixel.x();
    int y = pixel.y();

    //pixel not in canvas
    if ((x >= currentImage->width()) || (y >= currentImage->height()) || (x < 0) || (y < 0)){
        return;
    }
    //already is the currentColor
    else if (currentImage->pixelColor(pixel).rgba() == currentColor.rgba()){
        return;
    }

    if (currentImage->pixelColor(pixel).rgba() == originalColor.rgba()) {
        currentImage->setPixel(pixel, currentColor.rgba());

        //continue recursing
        fillPixelsAround(QPoint(x, y + 1),originalColor); //top
        fillPixelsAround(QPoint(x + 1, y),originalColor); //right
        fillPixelsAround(QPoint(x, y - 1),originalColor); //bottom
        fillPixelsAround(QPoint(x - 1, y),originalColor); //left
    }
}

void SpriteEditor::changeColor(QColor color){
    currentColor = color;
    emit updateColorPicker(color);
}


void SpriteEditor::imageDeleted(QImage* img) {
    //look for image passed in and delete it from frames if we find it
    auto imageInVector = std::find(frames.begin(), frames.end(), img);
    if (imageInVector != frames.end()) {
        frames.erase(imageInVector);
        emit updateFrames(frames);
    }
}

void SpriteEditor::currentImageUpdated(QImage* img) {
//    auto imageInVector = std::find(frames.begin(), frames.end(), img);
//    if (imageInVector != frames.end()) {
//        currentImage = img;
//    }
}

void SpriteEditor::drawCircle(int xCenter, int yCenter, int r){
    int x = r;
    int y = 0;
    int p = 1 - r;
    while(x > y){
        y++;
        if (p <= 0){
            p += (2*y + 1);
        }
        else{
            x--;
            p += (2*y - 2*x + 1);
        }
        if(x < y){
            break;
        }

        QPoint pixel = calculateActualPixel(QPoint(x + xCenter, y + yCenter));
        QPoint pixel2 = calculateActualPixel(QPoint(xCenter - x, y + yCenter));
        QPoint pixel3 = calculateActualPixel(QPoint(x + xCenter, yCenter - y));
        QPoint pixel4 = calculateActualPixel(QPoint(xCenter - x, yCenter - y));
        currentImage->setPixel(pixel, currentColor.rgba());
        currentImage->setPixel(pixel2, currentColor.rgba());
        currentImage->setPixel(pixel3, currentColor.rgba());
        currentImage->setPixel(pixel4, currentColor.rgba());
        QPixmap scaledPixmap = scaleCurrentImageToPixmap();
        emit displayCanvasImage(scaledPixmap);

        if (x != y){
            QPoint pixel = calculateActualPixel(QPoint(y + xCenter, x + yCenter));
            QPoint pixel2 = calculateActualPixel(QPoint(xCenter - y, x + yCenter));
            QPoint pixel3 = calculateActualPixel(QPoint(y + xCenter, yCenter - x));
            QPoint pixel4 = calculateActualPixel(QPoint(xCenter - y, yCenter - x));
            currentImage->setPixel(pixel, currentColor.rgba());
            currentImage->setPixel(pixel2, currentColor.rgba());
            currentImage->setPixel(pixel3, currentColor.rgba());
            currentImage->setPixel(pixel4, currentColor.rgba());
            QPixmap scaledPixmap = scaleCurrentImageToPixmap();
            emit displayCanvasImage(scaledPixmap);
        }
    }
}

void SpriteEditor::drawRectangle(int x0, int y0, int x1, int y1, int dx, int dy){
    for(int x = x0; x < x1; x++){
        QPoint pixel = calculateActualPixel(QPoint(x, y0));
        QPoint pixel2 = calculateActualPixel(QPoint(x, y0 + dy));
        currentImage->setPixel(pixel, currentColor.rgba());
        currentImage->setPixel(pixel2, currentColor.rgba());
        QPixmap scaledPixmap = scaleCurrentImageToPixmap();
        emit displayCanvasImage(scaledPixmap);
    }
    for(int y = y0; y < y1; y++){
        QPoint pixel = calculateActualPixel(QPoint(x0,y));
        QPoint pixel2 = calculateActualPixel(QPoint(x0 + dx, y));
        currentImage->setPixel(pixel, currentColor.rgba());
        currentImage->setPixel(pixel2, currentColor.rgba());
        QPixmap scaledPixmap = scaleCurrentImageToPixmap();
        emit displayCanvasImage(scaledPixmap);
    }
}


void SpriteEditor::drawLineLow(int x0, int y0, int x1, int y1){
    qDebug() << "in drawLineLow: point1 (" << x0 << ", " << y0 << ") point2: (" << x1 << ", " << y1 << ")";
    // CITATION: used Bresenham's line algorithm
    // https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;
    if(dy < 0){
        yi = -1;
        dy = -dy;
    }
    int D = 2*dy - dx;
    int y = y0;
    for(int x = x0; x<x1; x++){
        QPoint pixel = calculateActualPixel(QPoint(x,y));
        currentImage->setPixel(pixel, currentColor.rgba());
        QPixmap scaledPixmap = scaleCurrentImageToPixmap();
        emit displayCanvasImage(scaledPixmap);
        if(D > 0){
            y += yi;
            D += (2 * (dy - dx));
        }
        else{
            D += 2*dy;
        }
    }
    // END CITATION
}
void SpriteEditor::drawLineHigh(int x0, int y0, int x1, int y1){
    qDebug() << "in drawLineHigh: point1 (" << x0 << ", " << y0 << ") point2: (" << x1 << ", " << y1 << ")";
    // CITATION: used Bresenham's line algorithm
    // https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
    int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;
    if(dx < 0){
        xi = -1;
        dx = -dx;
    }
    int D = 2*dx - dy;
    int x = x0;
    for(int y = y0; y<y1; y++){
        QPoint pixel = calculateActualPixel(QPoint(x,y));
        currentImage->setPixel(pixel, currentColor.rgba());
        QPixmap scaledPixmap = scaleCurrentImageToPixmap();
        emit displayCanvasImage(scaledPixmap);
        if(D > 0){
            x += xi;
            D += (2 * (dx - dy));
        }
        else{
            D += 2*dx;
        }
    }
    // END CITATION
}
void SpriteEditor::drawLine(int x0, int y0, int x1, int y1){
    // CITATION: used Bresenham's line algorithm
    // https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
    if(abs(y1-y0) < abs(x1-x0)){
        if(x0 > x1){
            drawLineLow(x1, y1, x0, y0);
        }
        else{
            drawLineLow(x0, y0, x1, y1);
        }
    }
    else{
        if(y0 > y1){
            drawLineHigh(x1, y1, x0, y0);
        }
        else{
            drawLineHigh(x0, y0, x1, y1);
        }
    }
    // END CITATION
}

void SpriteEditor::saveToComputer(QString fileName) {
    JsonParser::saveFileFromQImages(frames, fileName);
}
