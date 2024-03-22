#include "loosesnowavalanchephysics.h"
#include <vector>
using namespace std;

void LooseSnowAvalanchePhysics::addSnowParticle() {
    //create snow chunks in varying sizes
    for (int i = 0; i < 5; i++){

        //in half measures
        vector<b2Vec2> pieceVertices;
        pieceVertices.push_back(b2Vec2(-0.1f, 0));
        pieceVertices.push_back(b2Vec2(0.0f, 0.35f));
        pieceVertices.push_back(b2Vec2(0.25f, 0.6f));
        pieceVertices.push_back(b2Vec2(0.375f, 0.35f));
        pieceVertices.push_back(b2Vec2(0.6f, 0.25f));
        pieceVertices.push_back(b2Vec2(0.4f, 0.0f));
        pieceVertices.push_back(b2Vec2(0.2f, -0.15f));

        vector<b2Vec2> smallerPieceVertices;
        smallerPieceVertices.push_back(b2Vec2(0, 0));
        smallerPieceVertices.push_back(b2Vec2(0.1f, 0.25f));
        smallerPieceVertices.push_back(b2Vec2(0.375f, 0.35f));
        smallerPieceVertices.push_back(b2Vec2(0.4f, 0.0f));

        vector<b2Vec2> superSmallPieceVertices;
        superSmallPieceVertices.push_back(b2Vec2(-0.05f, 0.1f));
        superSmallPieceVertices.push_back(b2Vec2(0.05f, 0.1f));
        superSmallPieceVertices.push_back(b2Vec2(0.075f, 0.075f));
        superSmallPieceVertices.push_back(b2Vec2(0.075f, -0.075f));
        superSmallPieceVertices.push_back(b2Vec2(0.05f, -0.1f));
        superSmallPieceVertices.push_back(b2Vec2(-0.05f, 0.1f));
        superSmallPieceVertices.push_back(b2Vec2(-0.075f, -0.075f));
        superSmallPieceVertices.push_back(b2Vec2(-0.075f, 0.075f));

        float32 pieceDensity = 5.0f;
        b2Vec2 piecePosition(float32(0 - i) , float32(i/2));
        snowPack->push_back(new SnowParticle(pieceVertices, piecePosition, pieceDensity, world));
        snowPack->push_back(new SnowParticle(smallerPieceVertices, piecePosition, pieceDensity, world));
        snowPack->push_back(new SnowParticle(superSmallPieceVertices, piecePosition, pieceDensity, world));
    }

    avalanche->setSnowPack(snowPack);
}
