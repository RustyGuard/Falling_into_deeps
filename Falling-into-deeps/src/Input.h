#pragma once
#include "GLFW/glfw3.h"
#include "events/Event.h"

namespace Gear {
	void InitKeys();
	void OnEvent(Event& event);
	
	bool isKeyPressed(int key);
	int GetKey(const std::string& key);
	int GetMouseButton(int button);
	double getMouseX();
	double getMouseY();
}

