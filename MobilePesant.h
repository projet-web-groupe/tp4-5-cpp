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

	MobilePesant(double x,double y, double z, double inclinaison)
	: Position(x,y,z), m(1), nom("none")
	{
		double theta = atan(y/x);
		double phi = M_PI/180 * inclinaison;

		double norm_v = sqrt(Terre::GM/(Terre::RT + position.distance()));
		vitesse = Vecteur3D(-sin(theta)*norm_v,cos(theta)*norm_v,z);
		double v_r = sqrt(vitesse.getX()*vitesse.getX()+vitesse.getY()*vitesse.getY());
		double v_theta = atan(vitesse.getY()*vitesse.getX());
		double v_z = z;

		v_theta *= cos(phi);
		v_z *= sin(phi); 
		vitesse = Vecteur3D(v_r*cos(v_theta), v_r*sin(v_theta),z);
	}
	void avance(const double dt);
	void affiche(void) const;
	MobilePesant * copie(void) const;
	const double getMasse(void);
};

#endif