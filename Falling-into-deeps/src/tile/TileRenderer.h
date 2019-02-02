#pragma once
#include "Tile.h"
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

	static void Init();
	static const int WIDTH = 2, HEIGHT = 2;
private:
	unsigned int tiles[WIDTH * HEIGHT];
	std::map<unsigned int, Entity*>tile_entities;
};

