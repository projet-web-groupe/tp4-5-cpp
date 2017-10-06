#include "MobilePesant.h"

#include "Vecteur3D.h"
#include <iostream>

Vecteur3D MobilePesant::g = Vecteur3D(0,0,-9.81);

MobilePesant::MobilePesant(
	double _masse,
	Vecteur3D _position, 
	Vecteur3D _vitesse, 
	std::string _nom)
: Mobile(_position,_vitesse,_nom), masse(_masse) {}

void MobilePesant::avance(const double dt){
	position.x += dt * vitesse.x;
	position.y += dt * vitesse.y;
	position.z += dt * vitesse.z;
	
	vitesse.x += dt * g.x;
	vitesse.y += dt * g.y;
	vitesse.z += dt * g.z;
}

void MobilePesant::affiche(void) const{
	std::cout <<"Object : Mobile Pesant\n" << "\tmasse = " << masse << "\n\tnom = \"" << nom << "\"\n\tPosition = ";
	position.affiche();
	std::cout << "\tVitesse = ";
	vitesse.affiche();
}

MobilePesant * MobilePesant::copie(void)const{
	return new MobilePesant(*this);
}

const double MobilePesant::getMasse(void){return masse;}