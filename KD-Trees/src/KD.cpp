#include <iostream>
#include <vector>
#include "KD.h"

KD::KD(std::vector<int> newData) {
	left = nullptr; right = nullptr;
	
	data = newData;

	level = 0;
	dimension = int(newData.size());
}

KD::KD(std::vector<int> newData, KD* prev) {
	left = nullptr; right = nullptr;
	data = newData;

	level = prev->getLevel() + 1;
	dimension = int(newData.size());
}

void KD::add(std::vector<int> newData) {
	if (data[level] >= newData[level]) {
		if (left == nullptr) {
			left = new KD(newData, this);
		} else {
			left->add(newData);
		}
	}
	else if (data[level] < newData[level]) {
		if (right == nullptr)
			right = new KD(newData, this);
		else
			right->add(newData);

	}
}

void KD::printNodes() {
	for (int i = 0; i < int(data.size()); i++) {
		if(i != int(data.size()) - 1)
			std::cout << data[i] << ", ";
		else
			std::cout << data[i];
	} std::cout << std::endl;
	std::cout << "level: " << level << std::endl;
	std::cout << std::endl;

	if (left != nullptr) {
		left->printNodes();
	}
	if (right != nullptr) {
		right->printNodes();
	}
}

int KD::getLevel() { return this->level; }