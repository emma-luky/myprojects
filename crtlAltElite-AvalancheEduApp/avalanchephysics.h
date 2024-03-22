#ifndef AVALANCHEPHYSICS_H
#define AVALANCHEPHYSICS_H
#include <Box2D/Box2D.h>
#include "avalanche.h"
#include "snowparticle.h"
///
/// \brief The AvalanchePhysics class -> abstract class that will be used as a base class for the different types of avalanches.
///
///
using namespace std;

class AvalanchePhysics
{
protected:
    ///
    /// \brief world -> the world in which box2d's physics will occcur
    ///
    b2World* world;

    ///
    /// \brief timeStep -> varable that represents how much we should move forward in time in box2d
    ///
    float32 timeStep = 1.0f / 60.0f;

    ///
    /// \brief velocityIterations
    ///
    int32 velocityIterations = 6;

    ///
    /// \brief positionIterations ->
    ///
    int32 positionIterations = 2;

    b2PolygonShape mountain;

    ///
    /// \brief groundBodyDef -> the groundBody definition of our box2d world.
    ///
    b2BodyDef groundBodyDef;

    ///
    /// \brief groundBody-> groundBody body
    ///
    b2Body* groundBody;



    ///
    /// \brief getSnowParticlePositions -> gets the position of every particle in avalanche
    /// \return
    ///
    vector<b2Vec2> getSnowParticlePositions();

    ///
    /// \brief getSnowParticleVerticies -> creates a list of snow particles verticies
    /// \return returns a vector containing a vector of verticie
    ///
    vector<vector<b2Vec2>> getSnowParticleVerticies();



    ///
    /// \brief snowPack -> represents all of the snowparticle entities inside of the avalanche
    ///
    vector<SnowParticle*>* snowPack;



public:
    ///
    /// \brief avalanche this represents the data in the avalanche.
    ///
    Avalanche* avalanche;

    AvalanchePhysics();

    ///
    /// \brief worldStep -> will move the box2d world forward by one step and Modify an avalanche object
    /// \return
    ///
    Avalanche* worldStep();

    ///
    /// \brief add a SnowParticle to the snowpack
    ///
    virtual void addSnowParticle()=0;

    ~AvalanchePhysics();
};

#endif // AVALANCHEPHYSICS_H
