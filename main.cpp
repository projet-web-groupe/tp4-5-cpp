#include "Test.h"

#include <iostream>

int main(){
	bool b = Test::testSimulation4();
	if(b)
		std::cout << "OK !!!" << std::endl;
	else
		std::cout << "KO !!!" << std::endl;
	return 0;
}