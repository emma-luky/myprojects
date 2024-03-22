/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: spriteframe.h
    Description:this file represents a single sprite frame in the Sprite object

Reviewed by:
*/

#ifndef SPRITEFRAME_H
#define SPRITEFRAME_H

#include<QColor>
#include<QImage>
#include<vector>

using namespace std;

class SpriteFrame
{
public:
    SpriteFrame(int width, int height);
    ///
    /// \brief addPixel-> adds a single pixel to the sprite frame object
    /// \param red -> ranges from 0 - 225
    /// \param green -> ranges from 0 - 225
    /// \param blue -> ranges from 0 - 225
    /// \param alpha -> ranges from 0 - 225
    ///
    void addPixel(int red, int green, int blue, int alpha);

    ///
    /// \brief toQImage -> returns a QImage using the data from this class
    /// \return -> QImage
    ///
    QImage toQImage();
private:
    vector<QColor> pixels;
    int _height;
    int _width;
};



#endif // SPRITEFRAME_H
