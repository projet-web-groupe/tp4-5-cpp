#include "Vecteur3D.h"

#include <iostream>
#include <string>
#include <cmath>
#include "Terre.h"

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
	return ((Vecteur3D::abs(a[0] - b[0]) <= err) && (Vecteur3D::abs(a[1] - b[1]) <= err) && (Vecteur3D::abs(a[2] - b[2]) <= err)) ;
}

double Vecteur3D::operator[](int n)const{
	switch(n){
		case 0:
		return x;
		case 1:
		return y;
		case 2:
		return z;
		default:
		return 0;
	}
}

Vecteur3D Vecteur3D::operator+(const Vecteur3D &v){
	return Vecteur3D(x + v[0], y + v[1], z + v[2]);
}

Vecteur3D Vecteur3D::operator+=(const Vecteur3D &v){
	this->x += v[0];
	this->y += v[1];
	this->z += v[2];
	return *this;
}

Vecteur3D Vecteur3D::operator*(const Vecteur3D &v){
	return Vecteur3D(x * v[0], y * v[1], z * v[2]);
}

Vecteur3D operator*(const double d, const Vecteur3D &v){
	return Vecteur3D(d * v[0], d * v[1], d * v[2]);
}

double Vecteur3D::abs(double d){return ((d<0)?-d:d);}

const Vecteur3D Vecteur3D::gravite() const{
	return  -Terre::GM*(1/(sqrt(x*x+y*y+z*z)*(x*x+y*y+z*z))) * (*this);
}

double Vecteur3D::distance(const Vecteur3D& v)const{
	return sqrt((x-v[0])*(x-v[0]) + (y-v[1])*(y-v[1]) + (z-v[2])*(z-v[2]));
}