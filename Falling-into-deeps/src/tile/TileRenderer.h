#pragma once
#include "events/Event.h"
#include "entity/Entity.h"

class TileRenderer
{
public:
	TileRenderer();
	~TileRenderer();

	void OnEvent(Event& e);

	unsigned int GetTile(unsigned int x, unsigned int y);
	void SetTile(unsigned int x, unsigned int y, unsigned int tile);
	void SetTileEntity(unsigned int pos, const std::string& file);

	void Init();
	static const int WIDTH = 2, HEIGHT = 2;
private:
	void RegisterTile(unsigned int id, const std::string& file);
	unsigned int tiles[WIDTH * HEIGHT];
	std::map<unsigned int, Entity*>tile_entities;
	std::map<unsigned int, lua_State*>registered;
};

