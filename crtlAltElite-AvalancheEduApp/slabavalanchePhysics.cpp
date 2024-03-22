/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A9-Educational App

File: SlabAvalance Physics
    Description: Inherits from the Abstract avalanche physics class and creates a slab avalanche.
*/
#include "slabAvalanchePhysics.h"
#include <vector>

using namespace std;

void SlabAvalanchePhysics::addSnowParticle() {

    //in half measures
    float32 slabHeight = 0.15f;
    float32 slabWidth = 0.9f;
    float32 slabDensity = 5.0f;
    b2Vec2 slabPosition(-4.0f, 2.0f);

    SnowParticle* slab = new SnowParticle(slabHeight, slabWidth, slabPosition, slabDensity, world);

    snowPack->push_back(slab);

    avalanche->setSnowPack(snowPack);
}
