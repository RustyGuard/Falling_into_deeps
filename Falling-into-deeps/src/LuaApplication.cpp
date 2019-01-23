#include "sgtpch.h"
#include "LuaApplication.h"


LuaApplication::LuaApplication()
{
}


LuaApplication::~LuaApplication()
{
}

using namespace luabridge;
void LuaApplication::Run()
{
	lua_State* L = luaL_newstate();
	luaL_dofile(L, "res/script.lua");
	luaL_openlibs(L);
	lua_pcall(L, 0, 0, 0);
	LuaRef s = getGlobal(L, "testString");
	LuaRef n = getGlobal(L, "number");
	std::string luaString = s.cast<std::string>();
	int answer = n.cast<int>();
	std::cout << luaString << std::endl;
	std::cout << "And here's our number:" << answer << std::endl;
	std::cin.get();
}

Application* Application::CreateApplication()
{
	return new LuaApplication();
}