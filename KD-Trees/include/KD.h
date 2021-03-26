#pragma once

#include <vector>

class KD {
public:
	KD();
	KD(std::vector<int>);
	
	void setRoot(std::vector<int>);
	void add(std::vector<int>);
	
	void printNodes();
private:
	std::vector<int> data;

	KD* left;
	KD* right;
};
