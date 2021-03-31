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
	}
	else
	{
		// Coordinate to compare
		int dataCompare = level % int(data.size());

		// Left child placement
		/*

		YOU ARE HERE

		*/
	}
}