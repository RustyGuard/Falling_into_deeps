#pragma once
#include "Application.h"
#include "entity/EntityRenderer.h"
#include "Window.h"
#include "events/Event.h"

class Game : public Application
{
public:
	Game();
	~Game();
	void OnEvent(Event&) override;
private:
	EntityRenderer * renderer;
};

