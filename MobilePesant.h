#ifndef MOBILEPESANT_H
#define MOBILEPESANT_H

#include "Mobile.h"
class Vecteur3D;

class MobilePesant :public Mobile {
	double masse;
public:
	const Vecteur3D getGravite(void) const;
	MobilePesant(
		double masse,
		Vecteur3D _position = Vecteur3D(),
		Vecteur3D _vitesse = Vecteur3D(),
		std::string _nom = "none"
		);
	void avance(const double dt);
	void affiche(void) const;
	MobilePesant * copie(void) const;
	const double getMasse(void);
};

#endif