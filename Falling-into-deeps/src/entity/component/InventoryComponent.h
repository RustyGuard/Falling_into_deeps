#pragma once
#include "Component.h"
#include "StackComponent.h"

class InventoryComponent : public Component
{
public:
	InventoryComponent();
	~InventoryComponent();
	void Print()
	{
		for (int i = 0; i < stacks.size(); i++)
		{
			stacks[i]->Print();
		}
	}
private:
	std::vector<StackComponent*>stacks;
};

