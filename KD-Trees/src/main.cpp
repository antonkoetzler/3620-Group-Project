#include <iostream>
#include <vector>
#include "KD.h"

int main() {
	std::vector<int> one{5, 2};
	std::vector<int> two{2, 9};
	std::vector<int> three{3, 5};
	std::vector<int> four{9, 10};
	std::vector<int> five{11, 5};
	std::vector<int> six{1, 5};
	
	
	KD* foo = new KD(one);

	foo->add(two);
	foo->add(three);
	foo->add(four);
	foo->add(five);
	foo->add(six);
	foo->printNodes();

	return 0;
}

