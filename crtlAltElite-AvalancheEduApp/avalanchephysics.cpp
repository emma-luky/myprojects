/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File: AvalanchePhysics
    Description: this class handles all of the box2d logic and puts it in the Avalanche object that is shared between the model, view and controller

*/
#include "avalanchephysics.h"
#include <Box2D/Box2D.h>
#include <cstdio>
#include <QDebug>
AvalanchePhysics::AvalanchePhysics(){
    //ground box physics
    world = new b2World(b2Vec2(0.0,-10.0f));

    b2BodyDef groundBoxDef;
    b2Vec2 groundBoxPosition(0.0, -3.5f);
    groundBoxDef.position.Set(groundBoxPosition.x, groundBoxPosition.y);

    b2Body* groundBoxBody;
    groundBoxBody = world->CreateBody(&groundBoxDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(5.0f, .10f);

    groundBoxBody->CreateFixture(&groundBox, 0.0f);

    /* mountain physics
     * currently is a triangle that should show up at PIXEL coordinates
     * (0,600),(800,590),(0,640)
     */
    b2Vec2 mountainVerticies[3];

    mountainVerticies[0].Set(-5.0f, -3.47f);
    mountainVerticies[1].Set(4.0f, -3.47f);
    mountainVerticies[2].Set(-5.0f, 1.75f);

    vector<b2Vec2> mountainVerticiesVector(mountainVerticies, mountainVerticies + 3);

    //setting the shape of the mountain
    b2PolygonShape mountainShape;
    mountainShape.Set(mountainVerticies, 3);

    //defining the mountain fixtures
    b2FixtureDef mountainFixtureDef;
    mountainFixtureDef.shape = &mountainShape;
    mountainFixtureDef.density = 1;
    mountainFixtureDef.friction = .75;

    //setting the mountain body definitions
    b2BodyDef mountainBodyDef;
    mountainBodyDef.type = b2_staticBody;
    b2Vec2 mountainPosition(0.0f, 0.0f);
    mountainBodyDef.position.Set(mountainPosition.x, mountainPosition.y);

    //adding the body to our world
    b2Body* mountainBody = world->CreateBody(&mountainBodyDef);

    mountainBody->CreateFixture(&mountainFixtureDef);

    b2BodyDef rightEdgeBodyDef;
    b2Vec2 rightEdgePosition(4.0, -3.5f);
    rightEdgeBodyDef.position.Set(rightEdgePosition.x, rightEdgePosition.y);

    b2Body* rightEdgeBody;
    rightEdgeBody = world->CreateBody(&rightEdgeBodyDef);

    b2PolygonShape rightEdgeBox;
    rightEdgeBox.SetAsBox(.1f, 1.75f);
    rightEdgeBody->CreateFixture(&rightEdgeBox, 0.0f);

    // both of these are in half
    float32 groundBoxWidth = 10.0f;
    float32 groundBoxHeight = 0.2f;

    avalanche = new Avalanche(groundBoxPosition, groundBoxWidth, groundBoxHeight, mountainVerticiesVector, mountainPosition);
    snowPack = new vector<SnowParticle*>();
}

vector<b2Vec2> AvalanchePhysics::getSnowParticlePositions() {
    vector<b2Vec2> snowParticlesPositions;

    for(auto snowParticle: (*snowPack)) {
        snowParticlesPositions.push_back(snowParticle->getPosition());
    }
    return snowParticlesPositions;
}

vector<vector<b2Vec2>> AvalanchePhysics::getSnowParticleVerticies() {
    vector<vector<b2Vec2>> snowParticlesVerticies;

    for(auto snowParticle: (*snowPack)) {
        snowParticlesVerticies.push_back(snowParticle->getVertices());
    }
    return snowParticlesVerticies;
}


Avalanche* AvalanchePhysics::worldStep(){
    world->Step(timeStep, velocityIterations, positionIterations);
    return avalanche;
}

AvalanchePhysics::~AvalanchePhysics(){
    delete world;
    delete avalanche;

    for (SnowParticle* ptr : *snowPack) {
        delete ptr;
    }
    delete snowPack;
}
