#include "MobilePesant.h"

#include "Vecteur3D.h"
#include "Terre.h"
#include <iostream>

MobilePesant::MobilePesant(
	double _masse,
	Vecteur3D _position, 
	Vecteur3D _vitesse, 
	std::string _nom)
: Mobile(_position,_vitesse,_nom), masse(_masse) {}

void MobilePesant::avance(const double dt){
	vitesse += dt * getGravite();
	position += dt * vitesse;
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

const Vecteur3D MobilePesant::getGravite(void)const{
	//position.affiche();
	return position.gravite();
}

