/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: sprite.cpp
    Description:

Reviewed by: Ashlyn Hansen
*/

#include "sprite.h"
Sprite::Sprite(QString spriteFileName, int initWidth, int initHeight, vector<SpriteFrame> spriteFrames)
{
    filename = spriteFileName;
    width = initWidth;
    height = initHeight;
    frames = spriteFrames;
}


vector<QImage*> Sprite::toQImagePtrList() {
    vector<QImage*> imageList;

    for(unsigned int i = 0; i < frames.size(); i++){
        imageList.push_back(new QImage(frames[i].toQImage()));
    }

    return imageList;
}
