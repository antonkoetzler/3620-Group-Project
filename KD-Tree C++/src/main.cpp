/*
TODO LIST
1) Insert
2) Search (, and return)
*/


#include "KD.h"
#include <fstream>

void extractInformation(KD*);

int main()
{
	KD* tree = new KD();

	extractInformation(tree);

	return 0;
}

void extractInformation(KD* tree)
{
	std::ifstream inputStream("./input/input.txt");

	int first, second; // Grabbing Coordinates
	char comma; // Comma catching
	std::vector<int> newData; // Encapsulation


	if (inputStream.is_open())
	{
		while (!inputStream.eof())
		{
			inputStream >> first >> comma >> second;

			newData.push_back(first);
			newData.push_back(second);

			tree->add(newData);

			newData.clear();
		}
	}
}