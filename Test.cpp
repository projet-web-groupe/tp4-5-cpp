	s->ajouterCorps(&m1);
#include "Test.h"

#include "Vecteur3D.h"
#include "Mobile.h"
#include "MobilePesant.h"
#include "Simulation.h"
#include <iostream>
#include <list>


bool Test::testVecteur3D(void){
	bool res = true;
	double err  = 0.0001;
	Vecteur3D v3;
	std::cout << "Test de la class Vecteur3D :" << std::endl;
	Vecteur3D v1(1,2,3), v2(3,2,1);
	std::cout << "\nTest de l'opérateur [] :\nv1 =";
	v1.affiche();
	std::cout << "v1.x = " << v1[0] << ", v1.y = " << v1[1] << ", v1.z = " << v1[2] << "\nAutre valeur que 0-2 : " << v1[50] << std::endl;
	if(res)
		res = (v1[0] == v1.getX() && v1[1] == v1.getY() && v1[2] == v1.getZ());
	else
		return res;
	
	std::cout << "\nTest de l'operateur * entre Vecteur3D :\nv1 = ";
	v1.affiche();
	std::cout << "v2 = ";
	v2.affiche();
	std::cout << "v1 * v2 = ";
	v3 = v1 * v2;
	v3.affiche();
	if(res)
		res = (v3.getX() == v1.getX() * v2.getX() && v3.getY() == v1.getY() * v2.getY() && v3.getZ() == v1.getZ() * v2.getZ());
	else
		return res;
	
	std::cout << "\nTest de l'operateur * entre double et Vecteur3D :\nv1 = ";
	v1.affiche();
	std::cout << "v3 = 2.5 * v1\nv3 = ";
	v3 = 2.5*v1;
	v3.affiche();
	/*
	if(res)
		res = (Vecteur3D::abs(v3.getX() - 2.5*v1.getX()) < err && Vecteur3D::abs(v3.getY() - 2.5*v1.getY()) < err && Vecteur3D::abs(v3.getZ() - 2.5*v3.getZ()) < err);
	else
		return res;*/

	std::cout << "\nTest de l'operateur + entre Vecteur3D :\nv1 = ";
	v1.affiche();
	std::cout << "v2 = ";
	v2.affiche();
	v3 = v1 + v2;
	std::cout << "v1 + v2 = ";
	v3.affiche();

	if(res)
		res = ((Vecteur3D::abs(v3.getX() - v1.getX() - v2.getX()) < err) && (Vecteur3D::abs(v3.getY() - v1.getY() - v2.getY()) < err) && (Vecteur3D::abs(v3.getZ() - v1.getZ() - v2.getZ()) < err));
	else
		return res;
	
	v3 = v1;
	std::cout << "\nTest de l'operateur += :\nv3 = ";
	v3.affiche();
	std::cout << "v2 = ";
	v2.affiche();
	v3 += v2;
	std::cout << "v3 += v2\nv3 = ";
	v3.affiche();
	if(res)
		res = ((Vecteur3D::abs(v3.getX() - v1.getX() - v2.getX()) < err) && (Vecteur3D::abs(v3.getY() - v1.getY() - v2.getY()) < err) && (Vecteur3D::abs(v3.getZ() - v1.getZ() - v2.getZ()) < err));
	return res;
}