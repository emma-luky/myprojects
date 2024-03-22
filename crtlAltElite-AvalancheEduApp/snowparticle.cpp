/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A9-Educational App

File: snowparticle.h
    Description: A class representation for one box2d snow particle object
*/

#include "snowparticle.h"
#include "Box2D/Collision/Shapes/b2EdgeShape.h"
#include "Box2D/Dynamics/b2Body.h"
#include "Box2D/Dynamics/b2World.h"
#include "Box2D/Collision/Shapes/b2PolygonShape.h"
#include "Box2D/Dynamics/b2Fixture.h"
#include <QDebug>

SnowParticle::SnowParticle(vector<b2Vec2> initVertices, b2Vec2 pos, float32 density, b2World* world)
    :
    vertices(initVertices),
    position(pos)
{
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(pos.x, pos.y);
    body = world->CreateBody(&bodyDef);
    shape.Set(vertices.data(), vertices.size());

    fixtureDef.shape = &shape;
    fixtureDef.density = density;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
}

SnowParticle::SnowParticle(float32 height, float32 width, b2Vec2 pos, float32 density, b2World* world)
    :
    position(pos)
{
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(pos.x, pos.y);

    body = world->CreateBody(&bodyDef);

    shape.SetAsBox(width, height);

    vector<b2Vec2> rectangleVerticies;
    for(int i = 0; i < shape.GetVertexCount(); ++i) {
        rectangleVerticies.push_back(shape.GetVertex(i));
    }

    fixtureDef.shape = &shape;
    fixtureDef.density = density;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = .01f;
    body->CreateFixture(&fixtureDef);

    vertices = rectangleVerticies;
}
b2Vec2 SnowParticle::getPosition() {
    return body->GetPosition();
}

vector<b2Vec2> SnowParticle::getVertices() {
    vector<b2Vec2> worldPoints;
    for ( b2Vec2 vertice : vertices) {
        worldPoints.push_back(body->GetWorldPoint(vertice));
    }
    return worldPoints;
}

float32 SnowParticle::getAngle() {
    return body->GetAngle();
}

