#pragma once
#include "sgtpch.h"
#include "Entity.h"
#include "events/Event.h"

class EntityRenderer
{
public:
	EntityRenderer();
	unsigned int CreateEntity(const std::string&);
	void OnEvent(Event& e);
	Entity* GetEntity(unsigned int id);
private:
	std::map<unsigned int, Entity*> entities;
};

