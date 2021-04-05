#include "KD.h"

KD::KD()
{
	prev = nullptr;
	left = nullptr;
	right = nullptr;

	level = 0;
}

KD::KD (std::vector<int> newData)
{
	data = newData;

	prev = nullptr;
	left = nullptr;
	right = nullptr;

	level = 0;
}

KD::KD (std::vector<int> newData, KD* parent)
{
	data = newData;

	prev = parent;
	left = nullptr;
	right = nullptr;

	level = parent->getLevel() + 1;
}


void KD::add(std::vector<int> newData)
{
	// Checking the root node
	if (data.empty()) {
		data = newData;
	}
	else
	{
		// Setting what coordinate to compare
		int dataCompare = level % int(data.size());

		// Left child detection
		if (newData[dataCompare] < data[dataCompare])
		{
			if (left == nullptr)
				left = new KD(newData, this);
			else
				left->add(newData);
		}

		// Right child detection
		else if (newData[dataCompare] >= data[dataCompare])
		{
			if (right == nullptr)
				right = new KD(newData, this);
			else
				right->add(newData);
		}
	}
}

std::vector<int> KD::getData()
{
	return data;
}

int KD::getLevel()
{
	return level;
}