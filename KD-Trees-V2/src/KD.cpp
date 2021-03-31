#include "KD.h"

KD::KD()
{
	left = nullptr;
	right = nullptr;
	prev = nullptr;

	level = 0;
}

KD::KD(std::vector<int> newData)
{
	left = nullptr;
	right = nullptr;
	prev = nullptr;

	data = newData;
	level = 0;
}

KD::KD(std::vector<int> newData, KD* prevNode)
{
	prev = prevNode;

	left = nullptr;
	right = nullptr;

	data = newData;
	level = prevNode->getLevel() + 1;
}

void KD::printNodes()
{
	std::string spaces = "   ";

	// Checking the root node
	if (prev == nullptr)
		std::cout << data[0] << ", " << data[1] << std::endl;

	std::vector<std::vector<int>> path;
	left->gatherPath(path);

	/*



	YOU ARE HERE



	*/
}

int KD::getLevel() { return level; }

void KD::add(std::vector<int> newData)
{
	// Checking if we're at the root
	if (int(data.size()) == 0) data = newData;

	else
	{
		// Left child placement
		if (newData[level % int(data.size())] < data[level % int(data.size())])
		{
			if (left == nullptr)
				left = new KD(newData, this);
			else
				left->add(newData);
		}

		// Right child placement
		if (newData[level % int(data.size())] >= data[level % int(data.size())])
		{
			if (right == nullptr)
				right = new KD(newData, this);
			else
				right->add(newData);
		}
	}
}

void KD::gatherPath(std::vector<std::vector<int>> path)
{
	path.push_back(data);

	if(left != nullptr) left->gatherPath(path);
}