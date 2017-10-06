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

const double Vecteur3D::getX(void)const {return x;}
const double Vecteur3D::getY(void)const {return y;}
const double Vecteur3D::getZ(void)const {return z;}

void Vecteur3D::setX(double _x){x = _x;}
void Vecteur3D::setY(double _y){y = _y;}
void Vecteur3D::setZ(double _z){z = _z;}

bool operator==(const Vecteur3D &a, const Vecteur3D &b){
	double err = 0.00001;
	return ((a.getX() - b.getX() <= err) && (a.getY() - b.getY() <= err) && (a.getZ() - b.getZ()) <= err) ;
}

