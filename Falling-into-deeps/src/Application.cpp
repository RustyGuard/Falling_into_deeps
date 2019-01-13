#include "sgtpch.h"
#include "Application.h"


Application::Application()
{
	sgt::Log::Init();

	SGT_INFO("Application created.");

	window = Window::Create(1200, 675, "Application");
	window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
}

void Application::OnEvent(Event & event)
{
	if (event.GetEventType() == EventType::WindowClose) {
		running = false;
		SGT_INFO("Window closed");
	}
}

void Application::Run()
{
	while (running)
	{
		glClearColor(1, 1.0f, 0.5f, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		window->OnUpdate();
	}
	window->DeleteContext();
	std::cin.get();
}
