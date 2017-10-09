#include "Test.h"

#include "Vecteur3D.h"
#include "Mobile.h"
#include "MobilePesant.h"
#include "Simulation.h"
#include "Terre.h"
#include <iostream>
#include <cmath>
#include <list>


bool Test::testVecteur3D(void){
	bool res = true;
	double err  = 0.0001;
	Vecteur3D v3;
	std::cout << "Test de la class Vecteur3D :" << std::endl;
	Vecteur3D v1(1,2,3), v2(3,2,1);
	std::cout << "\nTest de l'opérateur [] :\nv1 =";
	v1.affiche();
	std::cout << "v1[0] = " << v1[0] << ", v1[1] = " << v1[1] << ", v1[2] = " << v1[2] << "\nAutre valeur que 0-2 : " << v1[50] << std::endl;
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
	
	if(res)
		res = (Vecteur3D::abs(v3.getX() - 2.5*v1.getX()) < err && Vecteur3D::abs(v3.getY() - 2.5*v1.getY()) < err && Vecteur3D::abs(v3.getZ() - 2.5*v1.getZ()) < err);
	else
		return res;

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

bool Test::testTerre(void){
	Vecteur3D v(0, Terre::RT, 0);
	v.affiche();
	std::cout << Terre::GM/Terre::RT << "\n";
	v.gravite().affiche();
	return true;
}

bool Test::testSattelite1(void){
	bool res = true;
	double h = 200000, dt = 0, pas = 0.0005;
	double T = 2*M_PI*sqrt((Terre::RT + h)*(Terre::RT + h)*(Terre::RT + h)/Terre::GM);
	double v = sqrt(Terre::GM/(Terre::RT + h));
	MobilePesant *sat = new MobilePesant(1 ,Vecteur3D(0,Terre::RT+h,0), Vecteur3D(v,0,0));
	Simulation s;
	s.ajouterCorps(sat);
	s.afficheCorps();
	while(dt < T){
		s.simuler(pas);
		dt += pas;
	}
	s.afficheCorps();

	return res;
}