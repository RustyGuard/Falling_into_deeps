#pragma once
#include "Component.h"

class StackComponent : public Component
{
public:
	StackComponent();
	static void Init();
	void Print();
private:
	unsigned int item = 0;
	unsigned int amount = 0;
	static void RegisterItem(unsigned int id, const std::string& file);
};
