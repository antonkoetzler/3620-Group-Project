#include "KD.h"
#include <fstream>
#include <string>

int main()
{
	std::ifstream inputStream("./input/SampleCoordinates.txt");

	KD* tree = new KD();

	int first, second;
	std::vector<int> input;

	if (inputStream.is_open())
	{
		while (!inputStream.eof())
		{
			inputStream >> first >> second;
			input.push_back(first);
			input.push_back(second);

			tree->add(input);

			input.clear();
		}
	}

	tree->printNodes();

	return 0;
}
