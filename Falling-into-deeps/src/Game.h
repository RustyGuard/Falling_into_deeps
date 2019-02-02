#pragma once
#include "Application.h"
#include "entity/EntityRenderer.h"
#include "tile/TileRenderer.h"
#include "Window.h"
#include "events/Event.h"

class Game : public Application
{
public:
	Game();
	~Game();
	void OnEvent(Event&) override;
	void Delete() override;
private:
	Window * window;
	EntityRenderer * entity_renderer;
	TileRenderer * tile_renderer;
};

