#include "Test.h"

#include <iostream>

int main(){
	bool b = Test::testTerre();
	if(b)
		std::cout << "OK !!!" << std::endl;
	else
		std::cout << "KO !!!" << std::endl;
	return 0;
}