#include "sgtpch.h"
#include "InventoryComponent.h"


InventoryComponent::InventoryComponent()
{
	for (int i = 0; i < 9; i++)
	{
		stacks.push_back(new StackComponent());
	}
}


InventoryComponent::~InventoryComponent()
{
}
