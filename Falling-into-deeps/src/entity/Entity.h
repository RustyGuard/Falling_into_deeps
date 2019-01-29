#pragma once
#include "sgtpch.h"
#include "component/Component.h"
#include "events/Event.h"
#include "Input.h"
#include "LuaManager.h"

class Entity
{
public:
	Entity(std::string file);
	~Entity();
	void OnEvent(Event& event);

	template<class T>
	T * getComponent(std::string name)
	{
		return (T*)components[name];
	}
private:
	std::map<std::string, Component*> components;
	lua_State* obj;
};

