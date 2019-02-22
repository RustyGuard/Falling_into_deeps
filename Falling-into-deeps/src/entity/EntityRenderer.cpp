#include "gearpch.h"
#include "EntityRenderer.h"


EntityRenderer::EntityRenderer()
{
	Entity::InitComponents();

	InitTiles();
	for (int i = 0; i < HEIGHT * WIDTH; i++)
	{
		tiles[i] = 0;
	}

	SetTile(1, 1, 1);
}

unsigned int EntityRenderer::CreateEntity(const std::string & name, const std::string& path)
{
	Entity* entity = new Entity(path + name);
	for (unsigned int i = 0; i < 1000; i++)
	{
		if (entities.find(i) == entities.end())
		{
			GEAR_WARN("Entity created: " + name + " " + std::to_string(i));
			entities[i] = entity;
			return i;
		}
	}
	GEAR_ERROR("To many entities in the world!!!");
	return 0;
}

void EntityRenderer::OnEvent(Event & e)
{
	for (auto& item : entities)
	{
		item.second->OnEvent(e);
	}
	for (auto& item1 : entities)
	{
		for (auto& item2 : entities)
		{
			if (item2 != item1)
			{
				item1.second->Interact(item2.second);
			}
		}
	}
}

Entity * EntityRenderer::GetEntity(unsigned int id)
{
	return entities[id];
}

void EntityRenderer::InitTiles()
{
	RegisterTile(0, "air");
	RegisterTile(1, "grass");
}

void EntityRenderer::RegisterTile(unsigned int id, const std::string & file)
{
	lua_State* obj = LuaManager::CreateRaw();
	getGlobalNamespace(obj)
		.beginClass<EntityRenderer>("tile_renderer")
		.addFunction("CreateTileEntity", &EntityRenderer::SetTileEntity)
		.endClass();
	LuaManager::Push(obj, "tile/" + file + ".lua");
	registered[id] = obj;
}

unsigned int EntityRenderer::GetTile(unsigned int x, unsigned int y)
{
	if (x < WIDTH && y < HEIGHT)
		return tiles[x + y * WIDTH];
	else return 0;
}

void EntityRenderer::SetTile(unsigned int x, unsigned int y, unsigned int tile)
{
	if (x < WIDTH && y < HEIGHT) {
		tiles[x + y * WIDTH] = tile;
		try
		{
			getGlobal(registered[tile], "init")(this, x + y * WIDTH);
		}
		catch (const LuaException& e)
		{
			GEAR_ERROR(e.what());
		}
	}
}

void EntityRenderer::SetTileEntity(unsigned int pos, const std::string & file)
{
	tile_entities[pos] = CreateEntity(file, "tile_entities/");
}