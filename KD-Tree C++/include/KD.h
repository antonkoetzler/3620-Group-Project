#pragma once

#include <iostream>
#include <vector>

class KD
{
public:
	KD(); // Empty tree, if we use fstream
	KD(std::vector<int>); // Root node
	KD(std::vector<int>, KD*); // Child node

	// Allocation
	void add(std::vector<int> newData);

	// Getters
	std::vector<int> getData();
	int getLevel();

private:
	std::vector<int> data;

	KD* prev;
	KD* left;
	KD* right;

	int level; // Height of the node (to the tree)
};
