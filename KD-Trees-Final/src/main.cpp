#include "KD.h"
#include <fstream>

void extractInformation(KD*);

int main()
{
	std::cout << std::endl;
	std::cout << "KD-Tree Program" << std::endl;
	std::cout << std::endl;

	// TESTING
	KD* tree = new KD();

	// Sample vectors
	std::vector<int> one{5,2};
	std::vector<int> two{3, 6};

	tree->add(one);
	tree->add(two);

	return 0;
	//
}

void extractInformation(KD* tree)
{
	// Variables to gather input
	// and add to our KD-Tree
	int first, second;
	char comma;
	std::vector<int> newData;

	std::ifstream inputStream("./input/input.txt");

	if (inputStream.is_open())
	{
		while (!inputStream.eof())
		{
			inputStream >> first >> comma >> second;
			newData.push_back(first); newData.push_back(second);
			tree->add(newData);
		}
	}

	inputStream.close();
}