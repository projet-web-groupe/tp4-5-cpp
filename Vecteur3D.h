#ifndef VECTEUR3D_H
#define VECTEUR3D_H

#include <string>

class Vecteur3D {
	double x, y, z;
public:
	
	//Constructeurs :
	Vecteur3D(
		double _x = 0, 
		double _y = 0, 
		double _z = 0
		);

	//getters et setters
	const double getX(void)const;
	const double getY(void)const;
	const double getZ(void)const;

	void setX(double x);
	void setY(double y);
	void setZ(double z);

	//Methode d'affichage
	void affiche(void) const;

};

bool operator==(const Vecteur3D &a, const Vecteur3D &b);

#endif