#include "sgtpch.h"
#include "LuaManager.h"

using namespace luabridge;

std::unordered_map<std::string, lua_State*> lua_files;

lua_State * LuaManager::CreateRaw()
{
	lua_State* state = luaL_newstate();
	luaL_openlibs(state);
	return state;
}

void LuaManager::Push(lua_State * state, std::string name)
{
	std::string path = "res/scripts/" + name;
	luaL_dofile(state, path.c_str());
	lua_pcall(state, 0, 0, 0);
	lua_files[name] = state;
}

lua_State * LuaManager::GetLuaFile(std::string name)
{
	return lua_files[name];
}
