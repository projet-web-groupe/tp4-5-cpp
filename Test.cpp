#include "Test.h"

#include "Vecteur3D.h"
#include "Mobile.h"
#include "MobilePesant.h"
#include "Simulation.h"
#include "Terre.h"
#include <iostream>
#include <cmath>
#include <list>

bool Test::testMobile1(void){
	bool b = true;
	std::cout << "Test de la class Mobile :" <<std::endl;
	Mobile m(Vecteur3D(),Vecteur3D(1,1,1),"Mobile Test");
	m.affiche();
	m.avance(1);
	m.affiche();
	if(!(m.getPosition() == Vecteur3D(1,1,1)))
		b = false;
	std::cout << "-- Fin du Test --" <<std::endl;
	return b;
}

bool Test::testSimulation1(void){
	std::cout << "Test de la class Simulation :" <<std::endl;

	Mobile m1(Vecteur3D(),Vecteur3D(1,1,1),"mobile1");
	Mobile m2(Vecteur3D(),Vecteur3D(2,2,2),"mobile2");
	Mobile m3(Vecteur3D(),Vecteur3D(3,3,3),"mobile3");

	Simulation *s = new Simulation();
	s->ajouterCorps(&m1);
	s->ajouterCorps(&m2);
	s->ajouterCorps(&m3);

	std::cout << "Affichage des Mobile allouer dynamiquement contenu dans la première simulation : \n";
	s->afficheCorps();
	std::cout << "\nLancemant de la simulation pour dt = 1\n";
	s->simuler(1);
	std::cout << "Affichage post simulation :\n";
	s->afficheCorps();
	std::cout << std::endl;

	std::list<Mobile *> c = s->getCorps();
	for (std::list<Mobile *>::iterator it = c.begin() ; it != c.end() ; ++it){
		if(!((*it)->getPosition() == (*it)->getVitesse())){
			return false;
		}
	}
	return true;
}

bool Test::testSimulation2(void){
	std::cout << "Test de la class Simulation :" <<std::endl;

	Mobile m1(Vecteur3D(),Vecteur3D(1,1,1),"mobile1");
	Mobile m2(Vecteur3D(),Vecteur3D(2,2,2),"mobile2");
	Mobile m3(Vecteur3D(),Vecteur3D(3,3,3),"mobile3");

	Mobile *m_dyn1 = new Mobile(Vecteur3D(),Vecteur3D(4,4,4),"mobile1");
	Mobile *m_dyn2 = new Mobile(Vecteur3D(),Vecteur3D(5,5,5),"mobile1");
	Mobile *m_dyn3 = new Mobile(Vecteur3D(),Vecteur3D(6,6,6),"mobile1");

	Simulation *s_auto = new Simulation();
	Simulation *s_dyn = new Simulation();

	s_dyn->ajouterCorps(m_dyn1);
	s_dyn->ajouterCorps(m_dyn2);
	s_dyn->ajouterCorps(m_dyn3);

	std::cout << "Affichage des Mobile allouer dynamiquement contenu dans la première simulation : \n";
	s_dyn->afficheCorps();
	std::cout << "\nLancemant de la simulation pour dt = 1\n";
	s_dyn->simuler(1);
	std::cout << "Affichage post simulation :\n";
	s_dyn->afficheCorps();
	std::cout << std::endl;

	std::list<Mobile *> c_dyn = s_dyn->getCorps();
	for (std::list<Mobile *>::iterator it = c_dyn.begin() ; it != c_dyn.end() ; ++it){
		if(!((*it)->getPosition() == (*it)->getVitesse())){
			return false;
		}
	}

	delete s_dyn;

	s_auto->ajouterCorps(&m1);
	s_auto->ajouterCorps(&m2);
	s_auto->ajouterCorps(&m3);

	std::cout << "\nAffichage des Mobile allouer statiquement contenu dans la deuxième simulation : \n";
	s_auto->afficheCorps();
	std::cout << "\nLancemant de la simulation pour dt = 1\n";
	s_auto->simuler(1);
	std::cout << "Affichage post simulation :\n";
	s_auto->afficheCorps();
	std::cout << std::endl;

	std::list<Mobile *> c_auto = s_auto->getCorps();
	for (std::list<Mobile *>::iterator it = c_auto.begin() ; it != c_auto.end() ; ++it){
		if(!((*it)->getPosition() == (*it)->getVitesse())){
			return false;
		}
	}
	delete s_auto;
	return true;
}

bool Test::testMobile2(void){
	MobilePesant m(10.0,Vecteur3D(0,0,Terre::RT+4.905),Vecteur3D(), "Mobile Pesant test");
	double dt = 0;
	double pas = 0.001;
	m.affiche();
	while((m.getPosition())[2] >= Terre::RT){
		m.avance(pas);
		//if(m.getPosition().z >= 0)
		dt += pas;
	}
	m.affiche();
	std::cout << dt/pas << " iteration(s)\n" << "Temps écoulé dt = " << dt << "\n";
	return (Test::abs(1-dt) <= 0.01);
}

double Test::abs(double d){return ((d<0)?-d:d);}

bool Test::testSimulation3(void){
	bool res = true;
	std::cout << "Test de la class Simulation :" <<std::endl;
	double dt = 0;
	double pas = 0.001;

	MobilePesant *m1 = new MobilePesant(1,Vecteur3D(0,0,Terre::RT+4.905),Vecteur3D(),"Mobile Pesant");
	Mobile *m2 = new Mobile(Vecteur3D(),Vecteur3D(1,1,1),"Mobile classique");

	Simulation *s = new Simulation();

	s->ajouterCorps(m1);
	s->ajouterCorps(m2);
	std::cout << "Affichage des Mobiles avant le debut de la simulation :\n";
	s->afficheCorps();
	std::cout << std::endl;

	while(m1->getPosition()[2] >= Terre::RT){
		s->simuler(pas);
		if(m1->getPosition()[2] >= Terre::RT)
			dt += pas;
	}
	std::cout << "Affichage des Mobiles après la fin de la simulation :\n";
	s->afficheCorps();

	std::cout << dt/pas << " iteration(s)\n" << "Temps écoulé dt = " << dt << "\n";
	if(res)
		res = (Test::abs(1-dt) <= 0.01);
	/*if(res)
		res = (m1->getPosition() == Vecteur3D(dt,dt,dt));
*/
	delete s;
	return res;
}

bool Test::testSimulation4(void){
	bool res = true;
	Simulation *s = new Simulation();
	Vecteur3D pos1(1,2,3), vit1(4,5,6),pos2(7,8,9),vit2(10,11,12);
	double masse = 1;
	std::string nom1("Mobile Pesant"),nom2("Mobile classique");
	MobilePesant *m1 = new MobilePesant(masse,pos1,vit1,nom1);
	Mobile *m2 = new Mobile(pos2,vit2,nom2);

	s->ajouterCorps(m1);
	s->ajouterCorps(m2);

	std::cout << "Affichage de la simulation :\n";
	s->afficheCorps();
	std::cout << "\nCopie puis destruction de la simulation...\n";
	Simulation * s_copie = new Simulation(*s);

	delete s;
	std::cout << "\nAffichage de la copie de la simulation :\n";
	s_copie->afficheCorps();

	delete s_copie;

	return res;
}

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
		res = (v1.getX() == v1[0] && v1.getY() == v1[1] && v1.getZ() == v1[2]);
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
		res = (v3[0] == v1[0] * v2[0] && v3[1] == v1[1] * v2[1] && v3[2] == v1[2] * v2[2]);
	else
		return res;
	
	std::cout << "\nTest de l'operateur * entre double et Vecteur3D :\nv1 = ";
	v1.affiche();
	std::cout << "v3 = 2.5 * v1\nv3 = ";
	v3 = 2.5*v1;
	v3.affiche();
	
	if(res)
		res = (Vecteur3D::abs(v3[0] - 2.5*v1[0]) < err && Vecteur3D::abs(v3[1] - 2.5*v1[1]) < err && Vecteur3D::abs(v3[2] - 2.5*v1[2]) < err);
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
		res = ((Vecteur3D::abs(v3[0] - v1[0] - v2[0]) < err) && (Vecteur3D::abs(v3[1] - v1[1] - v2[1]) < err) && (Vecteur3D::abs(v3[2] - v1[2] - v2[2]) < err));
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
		res = ((Vecteur3D::abs(v3[0] - v1[0] - v2[0]) < err) && (Vecteur3D::abs(v3[1] - v1[1] - v2[1]) < err) && (Vecteur3D::abs(v3[2] - v1[2] - v2[2]) < err));
	return res;
}

bool Test::testTerre(void){
	bool res = true;
	std::cout << "Position initiale : ";
	Vecteur3D v(0,Terre::RT,0);
	v.affiche();
	std::cout << "Gravité : ";
	v.gravite().affiche();
	if(res)
		res = (Test::abs(v.gravite()[1] - (-9.81)) < 0.1);
	return res;
}

bool Test::testSattelite1(void){
	bool res = true;
	double h = 200000, dt = 0, pas = 0.0005;
	double T = 2*M_PI*sqrt((Terre::RT + h)*(Terre::RT + h)*(Terre::RT + h)/Terre::GM);
	double v = sqrt(Terre::GM/(Terre::RT + h));
	MobilePesant *sat = new MobilePesant(1 ,Vecteur3D(0,Terre::RT+h,0), Vecteur3D(v,0,0));
	Vecteur3D p_init(sat->getPosition());
	Simulation s;
	s.ajouterCorps(sat);
	while(dt < T){
		s.simuler(pas);
		dt += pas;
	}
	s.afficheCorps();
	const double dist = p_init.distance(sat->getPosition());

	std::cout << "La durée de la simulation est de " << dt << "s soit "<< floor(dt/3600) <<"h"<<floor((dt-floor(dt/3600)*3600)/60)<<"m"<<dt-floor(dt/60)*60<<"s\n";
	std::cout << "Le sattelite est a une distance de " << dist << " m de sa position initiale\n";
	if(res)
		res = (dist <= 100);
	return res;
}