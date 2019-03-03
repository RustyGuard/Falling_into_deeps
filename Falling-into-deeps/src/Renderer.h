#pragma once
#include "LuaManager.h"
#include "events/Event.h"

class Renderer
{
public:
	Renderer();
	~Renderer();
	void OnEvent(Event & e);
private:
	lua_State * instance;
};

