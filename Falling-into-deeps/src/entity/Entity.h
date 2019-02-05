#pragma once
#include "sgtpch.h"

#include "component/Component.h"
#include "component/TransformComponent.h"
#include "component/InventoryComponent.h"

#include "events/Event.h"
#include "Input.h"
#include "LuaManager.h"

class Entity
{
public:
	Entity(std::string file);
	~Entity();
	void OnEvent(Event& event);
	static void InitComponents();
	
	template<typename T>
	static void RegisterComponent(const std::string& name);

	void AddComponent(const std::string& name);

	template<class T>
	T * getComponent(const std::string& name)
	{
		return (T*) components[name];
	}

	TransformComponent * GetTransform()
	{
		return getComponent<TransformComponent>("transform");
	}
	InventoryComponent * GetInventory()
	{
		return getComponent<InventoryComponent>("inventory");
	}
	/*InventoryComponent * GetInventory()
	{
		return getComponent<InventoryComponent>("inventory");
	}*/
private:
	std::map<std::string, Component*> components;
	lua_State* obj;
};
