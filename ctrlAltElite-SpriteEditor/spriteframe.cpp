/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: spriteframe.cpp
    Description: Class for the spriteEditor model, which holds the logic for creating, handling, editing, and loading sprites.

Reviewed by: Ashlyn Hansen
*/

#include "spriteframe.h"

SpriteFrame::SpriteFrame(int initWidth, int initHeight){
    width = initWidth;
    height = initHeight;
}

void SpriteFrame::addPixel(int red, int green, int blue, int alpha) {
        QColor pixel(red , green , blue, alpha);
        pixels.push_back(pixel);
}

QImage SpriteFrame::toQImage() {
        QImage image(width, height, QImage::Format_ARGB32);

    int colorIdx = 0;
        for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++){
            QRgb color = pixels[colorIdx].rgba();
            image.setPixel(QPoint(i, j), color);
            colorIdx++;
        }
    }
    return image;
}
