#pragma once

#include "Application.h"
#include "sgtpch.h"

extern "C" {
	#include "lua.h"
	#include "lauxlib.h"
	#include "lualib.h"
}
#include <LuaBridge/LuaBridge.h>

using namespace luabridge;
class LuaManager
{
public:	
	static lua_State* CreateRaw();

	template <class FUNC>
	static void addFunction(lua_State* state, const std::string name, FUNC func)
	{
		getGlobalNamespace(state).addFunction(name.c_str(), func);
	}

	static void Push(lua_State* state, std::string name);

	static lua_State* GetLuaFile(std::string name);
};
