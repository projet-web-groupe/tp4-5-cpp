#ifndef SIMULATION_H
#define SIMULATION_H

#include <list>
#include "Mobile.h"

class Simulation {
    double currentTime;
    std::list<Mobile *> corps;

public:
    Simulation();
    Simulation(const Simulation &m);
    ~Simulation();
    void ajouterCorps(Mobile * m);
    void oteCorps(Mobile * m);
    void afficheCorps(void) const;
    void simuler(double dt);

    std::list<Mobile *> getCorps(void) const;
};

#endif