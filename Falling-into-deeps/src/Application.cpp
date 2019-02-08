#include "gearpch.h"
#include "Application.h"
#include "events/KeyEvent.h"
#include "events/MouseEvent.h"
#include "events/ApplicationEvent.h"
#include <GLFW/glfw3.h>
#include "LuaManager.h"
#include "glm/glm.hpp"
#include "graphics/Graphics.h"
#include "Input.h"
#include "entity/Entity.h"
#include "entity/EntityRenderer.h"

using namespace std::chrono;
high_resolution_clock::time_point lastTime = high_resolution_clock::now();

Application::Application(float d) : delta(d)
{
	Gear::Log::Init();
	GEAR_CORE_INFO("Application created.");
}


void Application::Run()
{
	UpdateClock(high_resolution_clock::now());
	Gear::Init();

	float processed = 0.0f;
	float frame_time = 0.0f;
	float delta = 1.0f / 60;

	int fps = 0;
	
	while (running)
	{
		bool updated = false;
		float passed = GetElapsedTime();
		processed += passed;
		frame_time += passed;

		while (processed > delta)
		{
			processed -= delta;
			OnEvent(UpdateEvent(delta));
			updated = true;
		}

		if (frame_time >= 1) {
			frame_time -= 1;
			GEAR_CORE_INFO("FPS: " + std::to_string(fps));
			fps = 0;
		}

		if (updated)
		{
			OnEvent(RenderEvent());
			fps++;
		}
	}
	Delete();

	std::cin.get();
}

float Application::GetElapsedTime()
{
	high_resolution_clock::time_point now = high_resolution_clock::now();
	nanoseconds passed = lastTime - now;
	float elapsed = -1 * (duration_cast<std::chrono::nanoseconds>(passed).count());
	UpdateClock(now);
	return elapsed / 1000000000;
}

void Application::UpdateClock(high_resolution_clock::time_point p)
{
	lastTime = p;
}
