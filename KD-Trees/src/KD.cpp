#include <iostream>
#include <vector>
#include "KD.h"

KD::KD(std::vector<int> newData) {
	left = nullptr;
	right = nullptr;
	
	data = newData;
}

void KD::add(std::vector<int> data) {
	if (left == nullptr) {
		left = new KD(data);
	} else if (right == nullptr) {
		right = new KD(data);
	}
}

void KD::printNodes() {
	for (int i = 0; i < int(data.size()); i++) {
		if(i != int(data.size()) - 1)
			std::cout << data[i] << ", ";
		else
			std::cout << data[i];
	} std::cout << std::endl;

	std::cout << std::endl;
}