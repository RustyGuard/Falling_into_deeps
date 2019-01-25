#pragma once
#include "Window.h"
#include <glad/glad.h>
#include "events/Event.h"

class Application
{
public:
	Application();

	virtual void OnEvent(Event& event);
	virtual void Run();

	static Application* CreateApplication()
	{
		return new Application();
	}
private:
	Window* window;
	bool running;
};

