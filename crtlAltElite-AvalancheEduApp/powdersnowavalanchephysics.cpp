/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A9-Educational App

File: powdersnowavalanchephysics.cpp
    Description: An avalanche physics class for powder snow
*/

#include "powdersnowavalanchephysics.h"
#include <vector>

using namespace std;

void powderSnowAvalanchePhysics::addSnowParticle() {
    //create snow chunks in varying sizes
    for (int i = 0; i < 60; i++){

        //in half measures
        vector<b2Vec2> pieceVertices;
        pieceVertices.push_back(b2Vec2(0, 0));
        pieceVertices.push_back(b2Vec2(0.05f, 0.1f));
        pieceVertices.push_back(b2Vec2(0.1f, 0.1f));
        pieceVertices.push_back(b2Vec2(0.12f, 0.1f));
        pieceVertices.push_back(b2Vec2(0.16f, 0.08f));
        pieceVertices.push_back(b2Vec2(0.2f, 0.0f));

        float32 pieceDensity = 5.0f;
        b2Vec2 piecePosition = b2Vec2(randomFloat(-4.7f, -2.0f), randomFloat(1.8f, 2.0f));

        snowPack->push_back(new SnowParticle(pieceVertices, piecePosition, pieceDensity, world));
    }

    float32 slabHeight = 0.3f;
    float32 slabWidth = 0.7f;
    float32 slabDensity = 5.0f;
    b2Vec2 slabPosition(-2.5f, 1.7f);

    SnowParticle* slab = new SnowParticle(slabHeight, slabWidth, slabPosition, slabDensity, world);

    snowPack->push_back(slab);

    avalanche->setSnowPack(snowPack);
}

// Function to generate a random float between min and max
float powderSnowAvalanchePhysics::randomFloat(float min, float max) {
    return min + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (max - min));
}
