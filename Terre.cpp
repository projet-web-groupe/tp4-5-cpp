#include "Terre.h"

double Terre::GM = 3.986e14;
double Terre::RT = 6378000;

Terre::Terre(){}
Terre::~Terre(){}

Terre & Terre::getInstance(){
	static Terre t;
	return t;
}