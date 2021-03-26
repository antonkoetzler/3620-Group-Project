#include <iostream>
#include <vector>
#include "KD.h"

int main() {
	std::vector<int> one{5, 2};
	std::vector<int> two{2, 9};
	std::vector<int> three{3, 5};
	
	
	KD* foo = new KD();
	foo->setRoot(one);
	
	foo->printNodes();
	foo->add(two);

	return 0;
}

