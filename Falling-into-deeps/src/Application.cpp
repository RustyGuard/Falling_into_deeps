#include "sgtpch.h"
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

void printMessage(const std::string&);

Application::Application()
{
	sgt::Log::Init();

	SGT_INFO("Application created.");

	window = Window::Create(1200, 675, "Application");
	window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
}

void Application::OnEvent(Event & event)
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

	case EventType::WindowClose:
		running = false;
		SGT_INFO("Window closed");
	case EventType::MouseMoved:
		//MouseMovedEvent& e = (MouseMovedEvent&)event;
		//LuaRef onMouseMoved = getGlobal(LuaManager::GetLuaFile("window.lua"), "onMouseMoved");
		//onMouseMoved();
		break;
	}
}

class A
{
public:
	void print()
	{
		SGT_WARN("A:print()");
	}
};

void Application::Run()
{
	lua_State* L = LuaManager::CreateRaw();
	LuaManager::addFunction(L, "printMessage", printMessage);
	getGlobalNamespace(L).beginNamespace("glm").beginClass<A>("A").addConstructor<void(*)(void)>().addFunction("print", &A::print).endClass();
	
	LuaManager::Push(L, "window.lua");

	LuaRef s = getGlobal(L, "testString");
	LuaRef n = getGlobal(L, "number");
	std::string luaString = s.cast<std::string>();
	int answer = n.cast<int>();
	std::cout << luaString << std::endl;
	std::cout << "And here's our number:" << answer << std::endl;

	Graphics::Init();
	Entity::InitComponents();

	Entity* entity = new Entity("entity");
	Entity* entity2 = new Entity("entity2");

	while (running)
	{
		glClearColor(1, 1.0f, 0.5f, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		Graphics::Move();
		entity->OnEvent(UpdateEvent(1.0f));
		entity->OnEvent(RenderEvent());
		entity2->OnEvent(UpdateEvent(1.0f));
		entity2->OnEvent(RenderEvent());
		window->OnUpdate();
	}
	window->DeleteContext();
	std::cin.get();
}

void printMessage(const std::string& text)
{
	//SGT_INFO(text);
}
