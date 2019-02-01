#pragma once
#include "Window.h"
#include "events/Event.h"
#include <chrono>

class Application
{
public:
	Application(float delta);

	virtual void OnEvent(Event& event) = 0;

	void Run();
	float GetElapsedTime();
	void UpdateClock(std::chrono::high_resolution_clock::time_point p);

	static Application * CreateApplication();
protected:
	Window * window;
	bool running;
	float delta;
};

