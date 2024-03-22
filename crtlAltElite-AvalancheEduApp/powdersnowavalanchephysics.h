/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A9-Educational App

File: powdersnowavalanchephysics.h
    Description: An avalanche physics class for powder snow
*/

#ifndef POWDERSNOWAVALANCHEPHYSICS_H
#define POWDERSNOWAVALANCHEPHYSICS_H

#include "avalanchephysics.h"

class powderSnowAvalanchePhysics : public AvalanchePhysics
{
public:
    void addSnowParticle();

    //a method for getting a random number to use as a position for a b2d object
    float randomFloat(float min, float max);
};

#endif // POWDERSNOWAVALANCHEPHYSICS_H
