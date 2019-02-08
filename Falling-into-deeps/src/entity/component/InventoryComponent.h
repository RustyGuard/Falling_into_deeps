#pragma once
#include "Component.h"
#include "StackComponent.h"

class InventoryComponent : public Component
{
public:
	InventoryComponent();
	~InventoryComponent();
private:
	std::vector<StackComponent*>stacks;
};

