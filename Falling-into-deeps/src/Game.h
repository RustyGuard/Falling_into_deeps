#pragma once
#include "Application.h"
#include "Window.h"
#include "events/Event.h"
#include "Renderer.h"

class Game : public Application
{
public:
	Game();
	~Game();
	void OnEvent(Event&) override;
	void Delete() override;
private:
	Window * window;
	Renderer * renderer;
};

