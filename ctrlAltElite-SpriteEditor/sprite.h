/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File:sprite.h
    Description: class used to load an existing spirt into the sprite editor

Reviewed by: Ashlyn Hansen
*/

#ifndef SPRITE_H
#define SPRITE_H
#include <QString>
#include <vector>
#include <QImage>
#include "spriteframe.h"

using namespace std;

class Sprite
{
public:
    Sprite(QString spriteFileName, int initWidth, int initHeight, vector<SpriteFrame> spriteFrames);

    ///
    /// \brief toQImagePtrList: creates a QImagePtrList.
    /// \return vector<QImage*>: list of QImage pointers.
    ///
    vector<QImage*> toQImagePtrList();

private:
    QString filename;
    int width;
    int height;
    vector<SpriteFrame> frames;

};

#endif // SPRITE_H
