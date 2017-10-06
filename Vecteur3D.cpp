#include "Vecteur3D.h"

#include <iostream>
#include <sstream>
#include <string>

//Constructeurs :
Vecteur3D::Vecteur3D(
	double _x, 
	double _y, 
	double _z)
: x(_x), y(_y), z(_z){}

//Methode d'affichage
void Vecteur3D::affiche(void) const{
	std::cout << "( " << x << " , " << y << " , " << z << " )" << std::endl;
}

bool operator==(const Vecteur3D &a, const Vecteur3D &b){
	double err = 0.00001;
	return ((a.x - b.x <= err) && (a.y - b.y <= err) && (a.z - b.z) <= err) ;
}