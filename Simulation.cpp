#include "Simulation.h"

#include <list>

Simulation::Simulation() : currentTime(0){}

Simulation::Simulation(const Simulation &s) : currentTime(s.currentTime){
	std::list<Mobile *> c = s.getCorps();
	for(std::list<Mobile *>::const_iterator it = c.begin() ; it != c.end() ; ++it){
		this->ajouterCorps((*it)->copie());
	}
}

Simulation::~Simulation(){
	while(corps.size() != 0){
		Mobile * temp = corps.front();
		corps.remove(temp);
		delete temp;
	}
}

void Simulation::ajouterCorps(Mobile * m){corps.push_back(m);}

void Simulation::oteCorps(Mobile * m){corps.remove(m);}

void Simulation::afficheCorps(void) const{
	for (std::list<Mobile *>::const_iterator it=corps.begin(); it != corps.end(); ++it)
		(*it)->affiche();
}

void Simulation::simuler(double dt){
	currentTime += dt;
	for (std::list<Mobile *>::iterator it=corps.begin(); it != corps.end(); ++it)
		(*it)->avance(dt);
}

std::list<Mobile *> Simulation::getCorps(void) const{return corps;}