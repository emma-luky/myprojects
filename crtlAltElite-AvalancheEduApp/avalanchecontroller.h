#ifndef AVALANCHECONTROLLER_H
#define AVALANCHECONTROLLER_H

#include <QObject>
#include <QTimer>
#include "avalancheTypes.h"
#include "avalanchephysics.h"

namespace Ui {
class LearningScreen2;
class Animation;
}

class AvalancheController : public QObject
{
    Q_OBJECT
public:
    //default avalanche is arbitrally picked as a slab
    AvalancheController(QObject *parent = nullptr, Ui::LearningScreen2* ui = nullptr, avalancheTypes::avalancheTypes avalancheType = avalancheTypes::avalancheTypes::slab);
    void startSimulation();
    QTimer *timer;
    AvalanchePhysics* avalanchePhysics;
    void startAnimation();


private:
    QTimer simulationClock;
    void simulationStep();
    void renderAvalanche();
    void createAvalanche(avalancheTypes::avalancheTypes);
    Ui::LearningScreen2* learningScreenUI;


public slots:


signals:

};

#endif // AVALANCHECONTROLLER_H
