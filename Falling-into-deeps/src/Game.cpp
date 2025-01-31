#include "gearpch.h"
#include "Game.h"

#include "events/ApplicationEvent.h"
#include "events/KeyEvent.h"
#include "events/MouseEvent.h"
#include "events/WindowEvent.h"

#include "graphics/Graphics.h"
#include "Input.h"

Game::Game() : Application(1.0f / 60.0f)
{
	window = Window::Create(Gear::SCREEN_WIDTH, Gear::SCREEN_HEIGHT, "Application");
	window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

	renderer = new Renderer();
	Gear::OnEvent(WindowResizeEvent(1200, 675));
}


Game::~Game()
{
}

void Game::OnEvent(Event & event)
{
	switch (event.GetEventType())
	{
	case EventType::KeyPress:
		if (((KeyEvent&)event).GetKeyCode() == GLFW_KEY_ESCAPE)
		{
			window->Close();
		}
		break;

	case EventType::AppUpdate:
		Gear::Move();
		window->PollEvents();
		break;

	case EventType::AppRender:
		Gear::ClearColor(0.6f, 1.0f, 0.2f, 1.0f);
		Gear::Clear();
		renderer->OnEvent(event);
		window->SwapBuffers();
		return;

	case EventType::WindowClose:
		running = false;
		GEAR_INFO("Window closed");
		break;
	}
	renderer->OnEvent(event);
	Gear::OnEvent(event);
}

void Game::Delete()
{
	window->DeleteContext();
}

Application * Application::CreateApplication()
{
	return new Game();
}
