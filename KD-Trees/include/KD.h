#pragma once

#include <vector>

class KD {
public:
	KD(std::vector<int>);
	KD(std::vector<int>, KD*);
	
	void add(std::vector<int>);
	
	void printNodes();

	int getLevel();
private:
	std::vector<int> data;

	KD* left;
	KD* right;

	int level;
	int dimension;
};
