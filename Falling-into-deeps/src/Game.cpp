#include "sgtpch.h"
#include "Game.h"

#include "events/ApplicationEvent.h"
#include "events/KeyEvent.h"
#include "events/MouseEvent.h"
#include "events/WindowEvent.h"

#include "graphics/Graphics.h"

Game::Game() : Application(1.0f / 60.0f)
{
	renderer = new EntityRenderer();
	renderer->CreateEntity("entity");
	renderer->CreateEntity("entity2");

	window = Window::Create(1200, 675, "Application");
	window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
}


Game::~Game()
{
}

void Game::OnEvent(Event & event)
{
	switch (event.GetEventType())
	{
	case EventType::KeyReleased:
		Input::keyReleased(((KeyReleaseEvent&)event).GetKeyCode());
		if (((KeyReleaseEvent&)event).GetKeyCode() == GLFW_KEY_ESCAPE)
		{
			window->Close();
		}
		break;
	case EventType::KeyPressed:
		Input::keyPressed(((KeyReleaseEvent&)event).GetKeyCode());
		break;

	case EventType::AppUpdate:
		Graphics::Move();
		break;

	case EventType::AppRender:
		Graphics::ClearColor(0.6f, 1.0f, 0.2f, 1.0f);
		break;

	case EventType::WindowClose:
		running = false;
		SGT_INFO("Window closed");
		break;
	}

	renderer->OnEvent(event);
}

/*void Game::Run()
{
	Graphics::Init();

	EntityRenderer* renderer = new EntityRenderer();
	renderer->CreateEntity("entity");
	renderer->CreateEntity("entity2");

	while (running)
	{
		Graphics::ClearColor(0.7f, 0.9f, 0.9f, 1.0f);
		Graphics::Clear();
		Graphics::Move();
		renderer->OnEvent(UpdateEvent(1.0f));
		renderer->OnEvent(RenderEvent());
		window->OnUpdate();
	}

	window->DeleteContext();
	std::cin.get();
}*/

Application * Application::CreateApplication()
{
	return new Game();
}
