#ifndef MOBILE_H
#define MOBILE_H

#include "Vecteur3D.h"

class Mobile {
	friend class Test;
protected:
	bool dyn;
	Vecteur3D position;
	Vecteur3D vitesse;
	std::string nom;
public:
	//Constructeurs :
	Mobile(
		Vecteur3D _position = Vecteur3D(),
		Vecteur3D _vitesse = Vecteur3D(),
		std::string _nom = "none"
		);
	virtual ~Mobile();
	//Accesseurs : getteurs
	const std::string & getNom() const;
	const Vecteur3D & getPosition() const;
	const Vecteur3D & getVitesse() const;
	//Accesseur : Setteur
	void setNom(const std::string& _nom);
	void setPosition(const Vecteur3D& _position);
	void setVitesse(const Vecteur3D& _vitesse);
	//Methode d'affichage
	virtual void affiche(void) const;

	//Autre methode
	virtual void avance(const double dt);
	virtual Mobile * copie(void) const;
};

#endif