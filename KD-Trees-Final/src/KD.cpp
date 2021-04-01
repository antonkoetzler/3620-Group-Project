#include "KD.h"

KD::KD()
{
	// Make every member KD* nullptr,
	// since we're at the root
	prev = nullptr;
	left = nullptr;
	right = nullptr;

	// Make level 0, the top of the tree
	level = 0;
}

KD::KD(std::vector<int> newData)
{
	prev = nullptr;
	left = nullptr;
	right = nullptr;

	level = 0;

	data = newData;
}

KD::KD(std::vector<int> newData, KD* previousNode)
{
	prev = previousNode; // Establish the parent node

	left = nullptr;
	right = nullptr;

	level = previousNode->getLevel() + 1; // Always + 1
}

int KD::getLevel()
{
	return level;
}

std::vector<int> KD::getData()
{
	return data;
}

void KD::add(std::vector<int> newData)
{
	if (level == 0 && data.empty())
	{
		data = newData;
		std::cout << "WORKING" << std::endl;
	}
	else
	{
		// Which coordinate on what level to compare
		int dataCompare = level % int(data.size());
		std::cout << "dataCompare: " << dataCompare << std::endl;

		// Left child detection
		if (newData[dataCompare] < data[dataCompare])
		{
			if (left != nullptr)
				left->add(newData);
			else {
				left = new KD(newData, this);

				std::cout << "LEFT DATA: " << std::endl;
				std::cout << left->getData()[0] << ", " << left->getData()[1] << std::endl;
			}
		}

		// Right child detection
		if (newData[dataCompare] >= data[dataCompare])
		{
			if (right != nullptr)
				right->add(newData);
			else {
				right = new KD(newData, this);

				std::cout << "RIGHT DATA: " << std::endl;
				std::cout << right->getData()[0] << ", " << right->getData()[1] << std::endl;
			}
		}
	}
}