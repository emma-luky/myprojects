/*
Team: Ctrl Alt Elite
Members: Ashlyn Hansen, Ricardo Baeza, Emma Luk, Lindsey Peterson
Assignment: A8 - Sprite Editor

File:
    Description:

Reviewed by:
*/
#include "avalanchecontroller.h"
#include "slabavalanchePhysics.h"
#include "wetSnowAvalanchePhysics.h"
#include "loosesnowavalanchephysics.h"
#include "powdersnowavalanchephysics.h"
#include "ui_learningscreen2.h"

AvalancheController::AvalancheController(QObject *parent, Ui::LearningScreen2* ui, avalancheTypes::avalancheTypes avalancheType)
    : QObject{parent}, timer(new QTimer(this)), learningScreenUI(ui)
{
    connect(timer,
            &QTimer::timeout,
            this,
            &AvalancheController::simulationStep
            );

    createAvalanche(avalancheType);

}

void AvalancheController::startAnimation() {
    //adds the snow particles to the physics engine.
    avalanchePhysics->addSnowParticle();

    timer->setInterval(25);
    timer->start();
}

void AvalancheController::createAvalanche(avalancheTypes::avalancheTypes avalancheType){
    switch (avalancheType) {
    case avalancheTypes::avalancheTypes::looseSnow:
        avalanchePhysics = new LooseSnowAvalanchePhysics();
        break;
    case avalancheTypes::avalancheTypes::slab:
        avalanchePhysics = new SlabAvalanchePhysics();
        break;
    case avalancheTypes::avalancheTypes::powderSnow:
        avalanchePhysics = new powderSnowAvalanchePhysics();
        break;
    case avalancheTypes::avalancheTypes::wetSnow:
        avalanchePhysics = new WetSnowAvalanchePhysics();
        break;
    default:
        // preview not available
        break;
    }
}

void AvalancheController::simulationStep(){
    Avalanche* avalancheData = avalanchePhysics->worldStep();
    learningScreenUI->animation->drawWorld(avalancheData);
}

void AvalancheController::renderAvalanche(){

}
