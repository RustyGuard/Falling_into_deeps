#pragma once

#include "gearpch.h"

#include "component/Component.h"
#include "component/TransformComponent.h"
#include "component/InventoryComponent.h"

#include "events/Event.h"
#include "Input.h"
#include "LuaManager.h"

class Entity
{
public:
	Entity(const std::string& file);
	~Entity();
	static void InitComponents();
	
	template<typename T>
	static void RegisterComponent(const std::string& name);

	void AddComponent(const std::string& name);

	LuaRef GetField(const std::string& field)
	{
		return getGlobal(obj, field.c_str());
	}

	lua_State * GetState()
	{
		return obj;
	}

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
private:
	std::map<std::string, Component*> components;
	lua_State* obj;
};
