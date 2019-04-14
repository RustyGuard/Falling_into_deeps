#include "gearpch.h"
#include "Renderer.h"
#include "glm/glm.hpp"
#include "graphics/Graphics.h"
#include "Input.h"

Renderer::Renderer() : instance(LuaManager::CreateRaw())
{
	getGlobalNamespace(instance)
		.addFunction("Draw", &Gear::Draw)
		.addFunction<bool(*)(const std::string&)>("isPressed", &Gear::isKeyPressed)
		.addFunction("GetCameraX", &Gear::GetCameraX)
		.addFunction("GetCameraY", &Gear::GetCameraY)
		.addFunction("MoveCamera", &Gear::MoveCamera)
		.addFunction("GetMouseX", &Gear::getMouseX)
		.addFunction("GetMouseY", &Gear::getMouseY)
		.addFunction("CreateTexture", &Gear::CreateTexture)
		.addFunction("BindTexture", &Gear::BindTexture)
		.addFunction("IsButtonPressed", &Gear::isMouseButtonPressed)
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
	switch (e.GetEventType())
	{
	case EventType::AppRender:
		try
		{
			getGlobal(instance, "render")();
		}
		catch (const std::exception& ex)
		{
			GEAR_ERROR(ex.what());
		}
		break;
	case EventType::AppUpdate:
		try
		{
			getGlobal(instance, "update")(1.0f / 60.0f);
		}
		catch (const std::exception& ex)
		{
			GEAR_ERROR(ex.what());
		}
		break;
	}
}
