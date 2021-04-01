#pragma once

#include <iostream>
#include <vector>

class KD
{
public:
	// Constructors
	KD(); // Empty KD-Tree object
	KD(std::vector<int>); // KD-Tree with root node
	KD(std::vector<int>, KD*); // Child node

	// Getters
	int getLevel();
	std::vector<int> getData();

	// Allocation
	void add(std::vector<int>);

private:
	std::vector<int> data; // Our information

	// Parent node
	KD* prev;

	// Child nodes
	KD* left;
	KD* right;

	// Level of the tree node is at
	int level;
};
