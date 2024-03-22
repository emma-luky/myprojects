#include "wetSnowAvalanchePhysics.h"
#include <vector>

using namespace std;

void WetSnowAvalanchePhysics::addSnowParticle() {
    //create snow chunks in varying sizes

    //in half measures
    vector<b2Vec2> pieceVertices;
    pieceVertices.push_back(b2Vec2(0.0f, 0.25f));
    pieceVertices.push_back(b2Vec2(0.2f, 0.5f));
    pieceVertices.push_back(b2Vec2(0.3f, 0.4f));
    pieceVertices.push_back(b2Vec2(0.5f, 0.39f));
    pieceVertices.push_back(b2Vec2(0.75f, 0.05f));
    pieceVertices.push_back(b2Vec2(0.6f, 0.0f));
    pieceVertices.push_back(b2Vec2(0.4f, 0.15f));
    pieceVertices.push_back(b2Vec2(0.2f, 0.2f));

    float32 pieceDensity = 1.0f;
    b2Vec2 piecePosition(-5.0f, 1.1f);
    snowPack->push_back(new SnowParticle(pieceVertices, piecePosition, pieceDensity, world));

    //2
    pieceVertices.clear();
    pieceVertices.push_back(b2Vec2(0.0f, 0.4f));
    pieceVertices.push_back(b2Vec2(0.3f, 0.35f));
    pieceVertices.push_back(b2Vec2(0.5f, 0.3f));
    pieceVertices.push_back(b2Vec2(0.7f, 0.35f));
    pieceVertices.push_back(b2Vec2(0.9f, 0.2f));
    pieceVertices.push_back(b2Vec2(0.8f, 0.1f));
    pieceVertices.push_back(b2Vec2(0.6f, 0.05f));
    pieceVertices.push_back(b2Vec2(0.4f, 0.15f));

    pieceDensity = 0.8f;
    piecePosition = b2Vec2(-3.5f, .5f);
    snowPack->push_back(new SnowParticle(pieceVertices, piecePosition, pieceDensity, world));

    //3
    pieceVertices.clear();
    pieceVertices.push_back(b2Vec2(0.0f, 0.15f));
    pieceVertices.push_back(b2Vec2(0.3f, 0.3f));
    pieceVertices.push_back(b2Vec2(0.6f, 0.2f));
    pieceVertices.push_back(b2Vec2(0.8f, 0.35f));
    pieceVertices.push_back(b2Vec2(1.0f, 0.2f));
    pieceVertices.push_back(b2Vec2(0.9f, 0.1f));
    pieceVertices.push_back(b2Vec2(0.6f, 0.05f));
    pieceVertices.push_back(b2Vec2(0.3f, 0.15f));

    pieceDensity = 0.6f;
    piecePosition = b2Vec2(-4.2f, .6f);
    snowPack->push_back(new SnowParticle(pieceVertices, piecePosition, pieceDensity, world));

    //4
    pieceVertices.clear();
    pieceVertices.push_back(b2Vec2(0.0f, 0.25f));
    pieceVertices.push_back(b2Vec2(0.5f, 0.5f));
    pieceVertices.push_back(b2Vec2(1.0f, 0.4f));
    pieceVertices.push_back(b2Vec2(1.5f, 0.35f));
    pieceVertices.push_back(b2Vec2(2.0f, 0.2f));
    pieceVertices.push_back(b2Vec2(1.8f, 0.1f));
    pieceVertices.push_back(b2Vec2(1.2f, 0.05f));
    pieceVertices.push_back(b2Vec2(0.5f, 0.15f));

    pieceDensity = 1.5f;
    piecePosition = b2Vec2(-2.7f, .1f);
    snowPack->push_back(new SnowParticle(pieceVertices, piecePosition, pieceDensity, world));

    // Create 20 small pieces (rain)
    for (int i = 0; i < 50; i++) {
        pieceVertices.clear();
        pieceVertices.push_back(b2Vec2(0.0f, 0.055f));
        pieceVertices.push_back(b2Vec2(0.05, 0.0f));
        pieceVertices.push_back(b2Vec2(0.05f, 0.1f));

        pieceDensity = 0.5f;  // Adjust the density for smaller pieces
        piecePosition = b2Vec2(randomFloat(-4.7f, -2.0f), randomFloat(1.8f, 2.5f));

        // Create the raindrop and add it to the simulation
        snowPack->push_back(new SnowParticle(pieceVertices, piecePosition, pieceDensity, world));
    }

    avalanche->setSnowPack(snowPack);

}
// Function to generate a random float between min and max
float WetSnowAvalanchePhysics::randomFloat(float min, float max) {
    return min + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (max - min));
}

