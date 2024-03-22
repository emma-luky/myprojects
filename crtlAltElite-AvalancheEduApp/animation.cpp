#include "animation.h"
#include "Box2D/Collision/Shapes/b2ChainShape.h"
#include "Box2D/Collision/Shapes/b2PolygonShape.h"
#include "Box2D/Dynamics/b2Fixture.h"
#include "ui_animation.h"
#include <QGraphicsScene>
#include <QDialog>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QTimer>

Animation::Animation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Animation)
{
    ui->setupUi(this);

    /************* GraphicsView Setup ************/
    scene = new QGraphicsScene(this);
    //change later
    scene->setBackgroundBrush(QBrush(QColor(Qt::gray)));
    ui->graphicsView->setScene(scene);

    ui->graphicsView->fitInView(scene->sceneRect());

}


void Animation::drawSnow(vector<vector<b2Vec2>> snowShapes) {

    //deletes all of the Snow particles on the screen
    while(!snowParticles.empty()) {

        //grabs the reference to the SnowParticle on top of the Animation stack.
        QGraphicsItem* oldSnowParticle = snowParticles.top();
        snowParticles.pop();

        //uses the pointer to oldSnowParticle to remove the item from the screen.
        scene->removeItem(oldSnowParticle);
    }

    //this adds each snowparticle to the scene and adds it to the stack of pointers.
    for(auto i = 0; i < snowShapes.size(); i++){
        vector<b2Vec2> currentSnowVerticies = snowShapes[i];
        QList<QPoint> graphicPoints;

        for(b2Vec2 vertice : currentSnowVerticies) {
            QPoint point(vertice.x, vertice.y);
            graphicPoints.append(point);
        }

        QPolygonF currentSnow(graphicPoints);
        scene->items();
        QBrush snowParticleColor(QColor(237,247, 251));
        QGraphicsItem* snowPolygon = scene->addPolygon(currentSnow, QPen(QColor(Qt::gray)), snowParticleColor);
        snowParticles.push(snowPolygon);
    }

}

void Animation::drawMountain(vector<b2Vec2> mountainVerticies){
    QPen outlinePen(Qt::gray);
    outlinePen.setWidth(0);
    QList<QPoint> graphicPoints;

    for(b2Vec2 vertice : mountainVerticies) {
        QPoint point(vertice.x, vertice.y);
        graphicPoints.append(point);
    }

    scene->addPolygon(QPolygonF(graphicPoints), outlinePen);
}

void Animation::drawWorld(Avalanche* avalanche) {
    drawMountain(avalanche->getMountainVerticies());
    drawSnow(avalanche->getSnowParticleVerticies());
}

void Animation::clear(){
    scene->clear();
    while(!snowParticles.empty()) {
        snowParticles.pop();
    }
}

Animation::~Animation(){
    delete ui;
}
