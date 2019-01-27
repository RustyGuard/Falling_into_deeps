#include "sgtpch.h"
#include "Application.h"
#include "events/KeyEvent.h"
#include "events/MouseEvent.h"
#include <GLFW/glfw3.h>
#include "LuaManager.h"
#include "glm/glm.hpp"
#include "graphics/Graphics.h"
#include "Input.h"

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
	glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 half = glm::vec3(32.0f, 32.0f, 0.0f);

	while (running)
	{
		glClearColor(1, 1.0f, 0.5f, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		if (Input::isKeyPressed(GLFW_KEY_A))
			pos.x -= 1.1f;
		if (Input::isKeyPressed(GLFW_KEY_D))
			pos.x += 1.1f;
		if (Input::isKeyPressed(GLFW_KEY_W))
			pos.y -= 1.1f;
		if (Input::isKeyPressed(GLFW_KEY_S))
			pos.y += 1.1f;

		Graphics::Draw(pos, half);
		Graphics::Move();
		window->OnUpdate();
	}
	window->DeleteContext();
	std::cin.get();
}

void printMessage(const std::string& text)
{
	//SGT_INFO(text);
}
