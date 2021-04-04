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
	if (data.empty())
		data = newData;
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

void KD::printNodes()
{
	// Here, we're creating a vector to
	// see what nodes were nullptrs, for
	// traversal of next height
	std::vector<bool> edgesStored;

	// Printing the root node
	if (prev == nullptr)
	{
		std::cout << data[0] << ", " << data[1] << std::endl;

		this->findChildren(edgesStored);
		this->printChildren(edgesStored);
	}

	edgesStored = this->horizontalFind(edgesStored);

	std::cout << "SIZE: " << edgesStored.size() << std::endl;

	//prev->left->printChildren(); // !!!!!
}

void KD::findChildren(std::vector<bool> &edgesStored)
{
	if (left != nullptr && right != nullptr)
	{
		edgesStored.push_back(true);
		edgesStored.push_back(true);
	}

	else if (left != nullptr && right == nullptr)
	{
		edgesStored.push_back(true);
		edgesStored.push_back(false);
	}

	else if (left == nullptr && right != nullptr)
	{
		edgesStored.push_back(false);
		edgesStored.push_back(true);
	}

	else if (left == nullptr && right == nullptr)
	{
		edgesStored.push_back(false);
		edgesStored.push_back(false);
	}
}

std::vector<bool> KD::horizontalFind(std::vector<bool> edgesStored)
{
	std::vector<bool> newChildren;

	for (int i = 0; i < int(edgesStored.size()); i++)
	{
		if (edgesStored[i] % 2 == 0)
		{
			std::cout << "Even" << std::endl;
		}
		else if (edgesStored[i] % 2 == 1)
		{
			std::cout << "Odd" << std::endl;
		}
	}

	return newChildren;
}

void KD::printChildren(std::vector<bool> edgesStored)
{
	for (int i = 0; i < int(edgesStored.size()); i++)
	{
		if (edgesStored[i] && (i % 2) == 0)
			std::cout << left->getData()[0] << ", " << left->getData()[1];
		if (edgesStored[i] && (i % 2) == 1)
			std::cout << "   " << right->getData()[0] << ", " << right->getData()[1];
		if (!edgesStored[i])
			std::cout << "   ";
	}
	
	std::cout << std::endl; std::cout << std::endl;
}