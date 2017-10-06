#ifndef VECTEUR3D_H
#define VECTEUR3D_H

#include <string>

class Vecteur3D {
public:
	double x, y, z;
	
	//Constructeurs :
	Vecteur3D(
		double _x = 0, 
		double _y = 0, 
		double _z = 0
		);

	//Methode d'affichage
	void affiche(void) const;

};

bool operator==(const Vecteur3D &a, const Vecteur3D &b);

#endif