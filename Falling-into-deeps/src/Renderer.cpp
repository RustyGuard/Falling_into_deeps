#include "gearpch.h"
#include "Renderer.h"
#include "glm/glm.hpp"
#include "graphics/Graphics.h"
#include "Input.h"
#include "events/KeyEvent.h"
#include "events/MouseEvent.h"

Renderer::Renderer() : instance(LuaManager::CreateRaw())
{
	getGlobalNamespace(instance)
		.addFunction("Draw", &Gear::DrawEntity)
		.addFunction("DrawUI", &Gear::DrawUI)
		.addFunction<bool(*)(const std::string&)>("GetKey", &Gear::GetKey)
		.addFunction("GetCameraX", &Gear::GetCameraX)
		.addFunction("GetCameraY", &Gear::GetCameraY)
		.addFunction("MoveCamera", &Gear::MoveCamera)
		.addFunction("GetMouseX", &Gear::getMouseX)
		.addFunction("GetMouseY", &Gear::getMouseY)
		.addFunction("CreateTexture", &Gear::CreateTexture)
		.addFunction("GetMouseButton", &Gear::GetMouseButton)
		.beginClass<glm::vec3>("vec3")
			.addConstructor<void (*) (void)>()
			.addData("x", &glm::vec3::x, true)
			.addData("y", &glm::vec3::y, true)
			.addData("z", &glm::vec3::z, true)
		.endClass();
	LuaManager::Push(instance, "renderer.lua");
}


Renderer::~Renderer()
{
}

void Renderer::OnEvent(Event & e)
{
	try {
		switch (e.GetEventType())
		{
		case EventType::AppRender:
			getGlobal(instance, "PushEvent")("OnRender");
			break;
		case EventType::AppUpdate:
			getGlobal(instance, "PushEvent")("OnUpdate", 1.0f / 60.0f);
			break;
		case EventType::MouseButtonPress:
			getGlobal(instance, "PushEvent")("OnMouseButtonPressed", ((MouseButtonEvent&)e).GetMouseButton());
			break;
		case EventType::MouseButtonRelease:
			getGlobal(instance, "PushEvent")("OnMouseButtonReleased", ((MouseButtonEvent&)e).GetMouseButton());
			break;
		case EventType::KeyPress:
			getGlobal(instance, "PushEvent")("OnKeyPressed", ((KeyEvent&)e).GetKeyCode());
			break;
		case EventType::KeyRelease:
			getGlobal(instance, "PushEvent")("OnKeyReleased", ((KeyEvent&)e).GetKeyCode());
			break;
		}
	}
	catch (const std::exception& ex) {
		GEAR_ERROR(ex.what());
	}
}
