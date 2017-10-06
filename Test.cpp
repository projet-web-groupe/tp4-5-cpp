#include "Test.h"

#include "Vecteur3D.h"
#include "Mobile.h"
#include "MobilePesant.h"
#include "Simulation.h"
#include <iostream>
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
	MobilePesant m(10.0,Vecteur3D(0,0,4.905),Vecteur3D(), "Mobile Pesant test");
	double dt = 0;
	double pas = 0.001;
	m.affiche();
	while(m.getPosition().z >= 0){
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

	MobilePesant *m1 = new MobilePesant(1,Vecteur3D(0,0,4.905),Vecteur3D(),"Mobile Pesant");
	Mobile *m2 = new Mobile(Vecteur3D(),Vecteur3D(1,1,1),"Mobile classique");

	Simulation *s = new Simulation();

	s->ajouterCorps(m1);
	s->ajouterCorps(m2);
	std::cout << "Affichage des Mobiles avant le debut de la simulation :\n";
	s->afficheCorps();
	std::cout << std::endl;

	while(m1->getPosition().z >= 0){
		s->simuler(pas);
		//if(m1->getPosition().z >= 0)
		dt += pas;
	}
	std::cout << "Affichage des Mobiles après la fin de la simulation :\n";
	s->afficheCorps();

	std::cout << dt/pas << " iteration(s)\n" << "Temps écoulé dt = " << dt << "\n";
	if(res)
		res = (Test::abs(1-dt) <= 0.01);
	if(res)
		res = (m1->getPosition() == Vecteur3D(dt,dt,dt));

	delete s;
	return res;
}

bool Test::testSimulation4(void){

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
	std::cout << "Copie puis destruction de la simulation...\n";
	Simulation * s_copie = new Simulation(*s);

	delete s;
	std::cout << "Affichage de la copie de la simulation :\n";
	s_copie->afficheCorps();

	delete s_copie;

	return true;
}