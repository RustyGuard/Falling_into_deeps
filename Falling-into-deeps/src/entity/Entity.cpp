#include "sgtpch.h"
#include "Entity.h"
#include "component/TransformComponent.h"
#include "graphics/Graphics.h"

std::map<std::string, std::function<Component*()>> s_components;

Entity::Entity(std::string file) : obj(LuaManager::CreateRaw())
{
	LuaManager::Push(obj, file + ".lua");

	getGlobalNamespace(obj)
		.beginClass<TransformComponent>("transform_component")
			.addFunction("move", &TransformComponent::Move)
		.endClass()
		.beginClass<Entity>("Entity")
			.addFunction("AddComponent", &Entity::AddComponent)
			.addFunction("GetTransform", &Entity::GetTransform)
		.endClass();

	getGlobal(obj, "init")(this);
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
		getGlobal(obj, "render")(this);
		break;
	case EventType::AppUpdate:
		getGlobal(obj, "update")(this, 1.0f);
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

void Entity::InitComponents()
{
	RegisterComponent<TransformComponent>("transform");
}

void Entity::AddComponent(const std::string & name)
{
	components[name] = s_components[name]();
}

template<class T>
void Entity::RegisterComponent(const std::string& name)
{
	s_components[name] = []() {return new T(); };
}