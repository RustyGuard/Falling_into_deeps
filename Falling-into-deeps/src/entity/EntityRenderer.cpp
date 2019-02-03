#include "sgtpch.h"
#include "EntityRenderer.h"


EntityRenderer::EntityRenderer()
{
	Entity::InitComponents();
}

unsigned int EntityRenderer::CreateEntity(const std::string & name)
{
	Entity* entity = new Entity("entity/" + name);
	for (unsigned int i = 0; i < 1000; i++)
	{
		if (entities.find(i) == entities.end())
		{
			entities[i] = entity;
			return i;
		}
	}
	SGT_ERROR("To many entities on the world!!!");
	return 0;
}

void EntityRenderer::OnEvent(Event & e)
{
	for (auto& item : entities)
	{
		item.second->OnEvent(e);
	}
}

Entity * EntityRenderer::GetEntity(unsigned int id)
{
	return entities[id];
}
