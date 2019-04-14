#pragma once
#include "GLFW/glfw3.h"
#include "events/Event.h"

namespace Gear {
	void InitKeys();
	void OnEvent(Event& event);
	
	bool isKeyPressed(int key);
	bool isKeyPressed(const std::string& key);
	bool isMouseButtonPressed(int button);
	double getMouseX();
	double getMouseY();
}

