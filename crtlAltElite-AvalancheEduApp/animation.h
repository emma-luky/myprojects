/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A9 - Educational App

File: animation.h
    Description: The definition for the animation graphics view inside of learning screen 2

*/
#ifndef ANIMATION_H
#define ANIMATION_H

#include "Box2D/Collision/Shapes/b2EdgeShape.h"
#include "Box2D/Dynamics/b2Body.h"
#include "Box2D/Dynamics/b2World.h"
#include "QGraphicsView"
#include "QtCore/qtimer.h"
#include "avalanche.h"
#include <QWidget>
#include <vector>
#include <stack>
using namespace std;

namespace Ui {
class Animation;
}
///
/// \brief Animation class that draws calculations made from the physics class to the screen
///
class Animation : public QWidget
{
    Q_OBJECT

public:
    explicit Animation(QWidget *parent = nullptr);
    ~Animation();

    void startAnimation();

    ///
    /// \brief drawWorld -> calls drawSnow() and drawMountain()
    ///
    void drawWorld(Avalanche*);


    ///
    /// \brief updateWorld -> method that draws the updated values from box2d
    /// \param avalanche -> the avalanche data
    ///
    void updateWorld(Avalanche* avalanche);

    ///
    /// \brief clear -> clears the previous avalanche and all it's snow particles
    ///
    void clear();

private:
    Ui::Animation *ui;
    ///
    /// \brief scene -> the graphics view scene
    ///
    QGraphicsScene *scene;

    ///
    /// \brief snowParticles -> a list of  all the current snow particles and their positions
    ///
    stack<QGraphicsItem*> snowParticles;


    ///
    /// \brief drawSnow ->redraws the snow paticles based on their current box2d state
    ///
    void drawSnow(vector<vector<b2Vec2>>);


    ///
    /// \brief drawMountain -> draws the initial state of the simultation
    ///
    void drawMountain(vector<b2Vec2>);

};

#endif // ANIMATION_H
