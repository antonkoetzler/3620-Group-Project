#include <iostream>
#include <vector>
#include "KD.h"

KD::KD() {
	left = nullptr;
	right = nullptr;
}

KD::KD(std::vector<int> root) {
	left = nullptr;
	right = nullptr;
	
	data = root;
}

void KD::setRoot(std::vector<int> rootNode) {
	data = rootNode;
}

void KD::add(std::vector<int> data) {
	if (left == nullptr) {
		left = new KD(data);
	} else if (right == nullptr) {
		right = new KD(data);
	}
}

void KD::printNodes() {
	if
}