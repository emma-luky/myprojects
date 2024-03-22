/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A9-Educational App

File: snowparticle.h
    Description: A class representation for one box2d snow particle object
*/

#ifndef SNOWPARTICLE_H
#define SNOWPARTICLE_H

#include "Box2D/Collision/Shapes/b2EdgeShape.h"
#include "Box2D/Dynamics/b2Body.h"
#include "Box2D/Dynamics/b2World.h"
#include "Box2D/Collision/Shapes/b2PolygonShape.h"
#include "Box2D/Collision/Shapes/b2CircleShape.h"
#include "Box2D/Dynamics/b2Fixture.h"
#include <vector>

using namespace std;


class SnowParticle
{

public:
    //A constructor for a snow particle of a unique shape with vertices given
    SnowParticle(vector<b2Vec2> initVertices, b2Vec2 pos, float32 density, b2World* world);

    //A constructor for a slab snow particle with height and width given
    SnowParticle(float32 height, float32 width, b2Vec2 pos, float32 density, b2World* world);

    //Returns the position of the snow particle
    b2Vec2 getPosition();

    //Returns the vertices of the snow particle
    vector<b2Vec2> getVertices();

    //returns the angle of the snow particle
    float32 getAngle();

private:
    b2BodyDef bodyDef;
    b2Body* body;
    b2PolygonShape shape;
    b2FixtureDef fixtureDef;
    vector<b2Vec2> vertices;
    b2Vec2 position;
};

#endif // SNOWPARTICLE_H
