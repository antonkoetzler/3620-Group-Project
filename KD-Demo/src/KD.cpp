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

		std::cout << "Data: " << data[0] << ", " << data[1] << std::endl;
		std::cout << "Level: " << level << std::endl;
		std::cout << std::endl << std::endl;
	}
	else
	{
		// Setting what coordinate to compare
		int dataCompare = level % int(data.size());

		// Left child detection
		if (newData[dataCompare] < data[dataCompare])
		{
			if (left == nullptr)
			{
				left = new KD(newData, this);

				std::cout << "Data: " << left->getData()[0]
					<< ", " << left->getData()[1] << std::endl;
				std::cout << "Level: " << left->getLevel() << std::endl;
				std::cout << std::endl << std::endl;
			}
			else
			{
				left->add(newData);
			}
		}

		// Right child detection
		else if (newData[dataCompare] >= data[dataCompare])
		{
			if (right == nullptr)
			{
				right = new KD(newData, this);

				std::cout << "Data: " << right->getData()[0]
					<< ", " << right->getData()[1] << std::endl;
				std::cout << "Level: " << right->getLevel() << std::endl;
				std::cout << std::endl << std::endl;
			}
			else
			{
				right->add(newData);
			}
		}
	}
}

void KD::deleteMin()
{
	int dataCompare = level % int(data.size());

	data.clear();

	if (left != nullptr && right != nullptr)
	{
		// Left replacement
		if (left->getData()[dataCompare] < right->getData()[dataCompare])
		{
			data = left->getData();
			left->deleteMin();
		}
		else if (left->getData()[dataCompare] >= right->getData()[dataCompare])
		{
			data = right->getData();
			right->deleteMin();
		}
	}
	else if (left != nullptr && right == nullptr)
	{
		data = left->getData();
		left->deleteMin();
	}
	else if (left == nullptr && right != nullptr)
	{
		data = right->getData();
		right->deleteMin();
	}
	else
		std::cout << "Root node deleted" << std::endl;
}

std::vector<int> KD::getData()
{
	return data;
}

int KD::getLevel()
{
	return level;
}