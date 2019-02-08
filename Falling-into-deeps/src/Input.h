#pragma once
#include "GLFW/glfw3.h"

namespace Gear {
	void InitKeys();
	void keyPressed(int key);
	void keyReleased(int key);
	
	bool isKeyPressed(int key);
	bool isPressed(const std::string& key);
}

