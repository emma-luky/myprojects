/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A9 - Educational App

File: wetSnowAvalanchePhysics.h
    Description: The avalanche definitions for a wet snow avalanche

*/
#ifndef WETSNOWAVALANCHEPHYSICS_H
#define WETSNOWAVALANCHEPHYSICS_H

#include "avalanchephysics.h"

class WetSnowAvalanchePhysics : public AvalanchePhysics
{
public:
    // overwritten method that adds the particles specifically for a wet snow avalanche
    void addSnowParticle();

    // gives a random float out of the x and y
    float randomFloat(float min, float max) ;
};

#endif // WETSNOWAVALANCHEPHYSICS_H
