#pragma once
#include "gearpch.h"
#include "Entity.h"
#include "events/Event.h"

class EntityRenderer
{
public:
	EntityRenderer();

	unsigned int CreateEntity(const std::string& file, const std::string& path = "entity/");
	void OnEvent(Event& e);
	Entity* GetEntity(unsigned int id);

	static const int WIDTH = 2, HEIGHT = 2;
	unsigned int GetTile(unsigned int x, unsigned int y);
	void SetTile(unsigned int x, unsigned int y, unsigned int tile);
	void SetTileEntity(unsigned int pos, const std::string& file);

private:
	/* Tile Rendering */
	void InitTiles();
	void RegisterTile(unsigned int id, const std::string& file);
	unsigned int tiles[WIDTH * HEIGHT];
	std::map<unsigned int, lua_State*>registered;

	/* Entity Rendering */
	std::map<unsigned int, unsigned int>tile_entities;
	std::map<unsigned int, Entity*> entities;
};

