/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File:
    Description: Defines the physics for a loose snow avalanche
*/

#ifndef LOOSESNOWAVALANCHEPHYSICS_H
#define LOOSESNOWAVALANCHEPHYSICS_H

#include "avalanchephysics.h"

class LooseSnowAvalanchePhysics : public AvalanchePhysics
{
public:
    ///
    /// \brief addSnowParticle: creates the loosesnowavalanche snow particles
    /// and adds it to the avalanche
    ///
    void addSnowParticle();
};

#endif // LOOSESNOWAVALANCHEPHYSICS_H
