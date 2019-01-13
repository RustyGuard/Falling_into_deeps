#pragma once
#include "Window.h"
#include <glad/glad.h>
#include "events/Event.h"

class Application
{
public:
	Application();

	void OnEvent(Event& event);
	void Run();

	static Application* CreateApplication()
	{
		return new Application();
	}
private:
	Window* window;
	bool running;
};

