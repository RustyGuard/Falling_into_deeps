#include "sgtpch.h"
#include "TileRenderer.h"

std::map<unsigned int, Tile*>registered;

TileRenderer::TileRenderer()
{
	Init();
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			/* Set all to None */
			SetTile(j, i, 0);
		}
	}

	SetTile(1, 1, 1);
	SetTile(1, 0, 1);

	tile_entities[1 * WIDTH + 1] = new Entity("tile_entity");
	tile_entities[1] = new Entity("tile_entity2");
}

TileRenderer::~TileRenderer()
{
}

void TileRenderer::OnEvent(Event & e)
{
	switch (e.GetEventType())
	{
	case EventType::AppUpdate:
		for (auto& item : tile_entities)
		{
			item.second->OnEvent(e);
		}
	}
}

unsigned int TileRenderer::GetTile(unsigned int x, unsigned int y)
{
	if (x < WIDTH && y < HEIGHT)
		return tiles[x + y * WIDTH];
	else return 0;
}

void TileRenderer::SetTile(unsigned int x, unsigned int y, unsigned int tile)
{
	if (x < WIDTH && y < HEIGHT)
		tiles[x + y * WIDTH] = tile;
}

void TileRenderer::Init()
{
	// None
	registered[0] = new Tile();

	// Grass
	registered[1] = new Tile();
}
