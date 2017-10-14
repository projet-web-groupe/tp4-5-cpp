#include "Mobile.h"

#include "Vecteur3D.h"
#include "Terre.h"
#include <string>
#include <cmath>
#include <iostream>

//Constructeurs :
Mobile::Mobile(
	Vecteur3D _position, 
	Vecteur3D _vitesse, 
	std::string _nom
	)
: position(_position), vitesse(_vitesse), nom(_nom){
}

Mobile::~Mobile(){}

Mobile * Mobile::copie(void) const{return new Mobile(*this);}

//Accesseur : Getteurs
const std::string & Mobile::getNom() const{
	return nom;
}
const Vecteur3D & Mobile::getPosition() const{
	return position;
}
const Vecteur3D & Mobile::getVitesse() const{
	return vitesse;
}

//Accesseur : Setteurs
void Mobile::setNom(const std::string& _nom){
	nom = _nom;
}
void Mobile::setPosition(const Vecteur3D& _position){
	position = _position;
}
void Mobile::setVitesse(const Vecteur3D& _vitesse){
	vitesse = _vitesse;
}

void Mobile::affiche(void) const{
	std::cout <<"Object : Mobile\n" << "\tnom = \"" << nom << "\"\n\tPosition = ";
	position.affiche();
	std::cout << "\tVitesse = ";
	vitesse.affiche();
}

void Mobile::avance(const double dt){
	/*position.setX(position.getX() + dt * vitesse.getX());
	position.setY(position.getY() + dt * vitesse.getY());
	position.setZ(position.getZ() + dt * vitesse.getZ());*/
	position += dt * vitesse;
}