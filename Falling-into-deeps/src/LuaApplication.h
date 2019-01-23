#pragma once
#include <iostream>
#include "Application.h"

extern "C" {
	#include "lua.h"
	#include "lauxlib.h"
	#include "lualib.h"
}

#include <LuaBridge/LuaBridge.h>

class LuaApplication : public Application
{
public:
	LuaApplication();
	~LuaApplication();

	void Run() override;
private:

};

