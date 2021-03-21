#include <iostream>
#include "Test.h"

Test::Test() {
	data = 5;
}

void Test::printData() {
	std::cout << data << std::endl;
}

