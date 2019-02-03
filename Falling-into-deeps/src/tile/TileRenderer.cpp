#include "sgtpch.h"
#include "TileRenderer.h"
#include "LuaManager.h"

TileRenderer::TileRenderer()
{
	Init();

	for (int i = 0; i < HEIGHT * WIDTH; i++)
	{
		tiles[i] = 0;
	}

	SetTile(1, 1, 1);

	//tile_entities[1 * WIDTH + 1] = new Entity("tile_entity");
	//tile_entities[1] = new Entity("tile_entity2");
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
	if (x < WIDTH && y < HEIGHT) {
		tiles[x + y * WIDTH] = tile;
		try
		{
			getGlobal(registered[tile], "init")(this, x + y * WIDTH);
		}
		catch (const LuaException& e)
		{
			SGT_ERROR(e.what());
		}
	}
}

void TileRenderer::SetTileEntity(unsigned int pos, const std::string & file)
{
	tile_entities[pos] = new Entity("tile_entities/" + file);
}

void TileRenderer::Init()
{
	RegisterTile(0, "air");
	RegisterTile(1, "grass");
}

void TileRenderer::RegisterTile(unsigned int id, const std::string & file)
{
	lua_State* obj = LuaManager::CreateRaw();
	getGlobalNamespace(obj)
		.beginClass<TileRenderer>("tile_renderer")
			.addFunction("CreateTileEntity", &TileRenderer::SetTileEntity)
		.endClass();
	LuaManager::Push(obj, "tile/" + file + ".lua");
	registered[id] = obj;
}
