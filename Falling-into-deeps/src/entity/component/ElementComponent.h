#pragma once
#include "Component.h"
#include "gearpch.h"

class ElementComponent : public Component
{
public:
	
private:
	std::function<bool()> func;
};
