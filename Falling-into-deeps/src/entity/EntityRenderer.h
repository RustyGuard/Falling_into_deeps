#pragma once
#include "sgtpch.h"
#include "Entity.h"

class EntityRenderer
{
public:
	EntityRenderer();
private:
	std::map<unsigned int, Entity> entities;
};

