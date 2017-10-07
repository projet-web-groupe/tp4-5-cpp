#include "Test.h"

#include <iostream>

int main(){
	bool b = Test::testVecteur3D();
	if(b)
		std::cout << "OK !!!" << std::endl;
	else
		std::cout << "KO !!!" << std::endl;
	return 0;
}