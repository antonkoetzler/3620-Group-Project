#pragma once

#include <vector>
#include <iostream>

class KD
{
public:
	// Constructors
	KD(); // Empty KD-Tree
	KD(std::vector<int>); // Root node set
	KD(std::vector<int>, KD*); // Child node

	// Printing
	void printNodes();

	// Getters
	int getLevel();

	// Allocation
	void add(std::vector<int>);
	void gatherPath(std::vector<std::vector<int>>);

private:
	std::vector<int> data;

	KD* left;
	KD* right;
	KD* prev;

	int level;
};
