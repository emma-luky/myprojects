/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: Avalanche.cpp
    Description: functions as a container for all the information about our avalanches.

*/
#include "avalanche.h"

Avalanche::Avalanche(b2Vec2 ground_Box_Postion, float32 ground_Box_Width,float32 ground_Box_Height,
                     vector<b2Vec2> mountain_Verticies, b2Vec2 mountain_Position):
                     groundBoxPosition(ground_Box_Postion), groundBoxWidth(ground_Box_Width), groundBoxHeight(ground_Box_Height),
                     mountainVerticies(mountain_Verticies), mountainPosition(mountain_Position)
                    {}

float32 Avalanche::getGroundBoxHeight(){
    return groundBoxHeight * MKStoPixelConversionRate;
}

float32 Avalanche::getGroundBoxWidth(){
    return groundBoxWidth * MKStoPixelConversionRate;
}

b2Vec2 Avalanche::getGroundBoxPosition(){
    return convertMKStoPixels(groundBoxPosition);
}

b2Vec2 Avalanche::getMountainPosition() {
    return convertMKStoPixels(mountainPosition);
}

std::vector<b2Vec2> Avalanche::getMountainVerticies() {
    vector<b2Vec2>convertedMountainVerticies;
    for(b2Vec2 vec: mountainVerticies) {
        b2Vec2 convertedVec = convertMKStoPixels(vec);
        convertedMountainVerticies.push_back(convertedVec);
    }
    return convertedMountainVerticies;
}

std::vector<b2Vec2> Avalanche::getSnowParticlePositions() {
    vector<b2Vec2>convertedSnowParticles;

    for(SnowParticle* sp: snowPack) {
        b2Vec2 pos = convertMKStoPixels(sp->getPosition());
        convertedSnowParticles.push_back(pos);
    }

    return convertedSnowParticles;
}

vector<vector<b2Vec2>> Avalanche::getSnowParticleVerticies() {
    vector<vector<b2Vec2>> convertedSnowVecticies;

    for(SnowParticle* sp: snowPack) {
        vector<b2Vec2> convertedParticleVertcies;
        vector<b2Vec2> snowParticleVertices = sp->getVertices();
        for(b2Vec2  snowParticleVertice:snowParticleVertices) {
            convertedParticleVertcies.push_back(convertMKStoPixels(snowParticleVertice));
        }
        convertedSnowVecticies.push_back(convertedParticleVertcies);
    }
    return convertedSnowVecticies;
}

void Avalanche::setSnowPack(vector<SnowParticle*>* snowpack) {
    snowPack = *snowpack;
}


b2Vec2 Avalanche::convertMKStoPixels(b2Vec2 vector) {
    float32 x = (vector.x * MKStoPixelConversionRate) + 400;
    float32 y = 300 - (vector.y * MKStoPixelConversionRate);
    return b2Vec2(x, y);
}




