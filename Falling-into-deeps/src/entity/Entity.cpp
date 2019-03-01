#include "gearpch.h"
#include "Entity.h"
#include "Input.h"
#include "graphics/Graphics.h"

std::map<std::string, std::function<Component*()>> s_components;

Entity::Entity(const std::string& file) : obj(LuaManager::CreateRaw())
{
	LuaManager::Push(obj, file + ".lua");

	getGlobalNamespace(obj)
		.beginClass<TransformComponent>("transform_component")
			.addFunction("move", &TransformComponent::Move)
			.addFunction("draw", &TransformComponent::Draw)
			.addFunction("collide", &TransformComponent::Collide)
			.addFunction("setMovable", &TransformComponent::setMovable)
			.addFunction("isMovable", &TransformComponent::isMovable)
			.addFunction("isMoved", &TransformComponent::isMoved)
		.endClass()
		.beginClass<Entity>("Entity")
			.addFunction("AddComponent", &Entity::AddComponent)
			.addFunction("GetTransform", &Entity::GetTransform)
		.endClass()
		.addFunction("Draw", &Gear::Draw)
		.addFunction<bool(*)(const std::string&)>("isPressed", &Gear::isKeyPressed);

	getGlobal(obj, "init")(this);
}


Entity::~Entity()
{

}

void Entity::InitComponents()
{
	RegisterComponent<TransformComponent>("transform");
	RegisterComponent<InventoryComponent>("inventory");
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