#include "gearpch.h"
#include "Game.h"

#include "events/ApplicationEvent.h"
#include "events/KeyEvent.h"
#include "events/MouseEvent.h"
#include "events/WindowEvent.h"

#include "graphics/Graphics.h"

#include "entity/component/StackComponent.h"

Game::Game() : Application(1.0f / 60.0f)
{
	StackComponent::Init();

	entity_renderer = new EntityRenderer();
	entity_renderer->CreateEntity("entity");
	entity_renderer->CreateEntity("entity2");

	tile_renderer = new TileRenderer();

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
		Gear::Move();
		window->PollEvents();
		break;

	case EventType::AppRender:
		Gear::ClearColor(0.6f, 1.0f, 0.2f, 1.0f);
		Gear::Clear();
		entity_renderer->OnEvent(event);
		window->SwapBuffers();
		return;

	case EventType::WindowClose:
		running = false;
		GEAR_INFO("Window closed");
		break;
	}

	entity_renderer->OnEvent(event);
	tile_renderer->OnEvent(event);
}

void Game::Delete()
{
	window->DeleteContext();
}

Application * Application::CreateApplication()
{
	return new Game();
}
