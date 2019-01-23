#pragma once
#include "Window.h"
#include <glad/glad.h>
#include "events/Event.h"

class Application
{
public:
	Application();

	void OnEvent(Event& event);
	virtual void Run();

	static Application* CreateApplication();
private:
	Window* window;
	bool running;
};

