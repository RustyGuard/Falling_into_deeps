#include "gearpch.h"
#include "StackComponent.h"
#include "LuaManager.h"

std::map<unsigned int, lua_State*>registered;

StackComponent::StackComponent()
{
}

void StackComponent::Init()
{
	RegisterItem(0, "air");
	RegisterItem(1, "apple");
}

void StackComponent::RegisterItem(unsigned int id, const std::string& file)
{
	lua_State* obj = LuaManager::CreateRaw();
	LuaManager::Push(obj, "item/" + file + ".lua");
	registered[id] = obj;
}
