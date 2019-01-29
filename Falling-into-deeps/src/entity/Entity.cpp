#include "sgtpch.h"
#include "Entity.h"
#include "component/TransformComponent.h"
#include "graphics/Graphics.h"

Entity::Entity(std::string file) : obj(LuaManager::CreateRaw())
{
	LuaManager::Push(obj, file + ".lua");

	components["transform"] = new TransformComponent();
}


Entity::~Entity()
{

}

void Entity::OnEvent(Event & event)
{
	TransformComponent * transform = getComponent<TransformComponent>("transform");
	switch (event.GetEventType())
	{
	case EventType::AppRender:
		Graphics::Draw(transform->position, transform->half_extern);
		getGlobal(obj, "render")();
		break;
	case EventType::AppUpdate:
		getGlobal(obj, "update")(1.0f);
		if (Input::isKeyPressed(GLFW_KEY_A))
			transform->Move(-1.1f, 0.0f);
		if (Input::isKeyPressed(GLFW_KEY_D))
			transform->Move(1.1f, 0.0f);
		if (Input::isKeyPressed(GLFW_KEY_W))
			transform->Move(0.0f, -1.1f);
		if (Input::isKeyPressed(GLFW_KEY_S))
			transform->Move(0.0f, 1.1f);
		break;
	}
}
