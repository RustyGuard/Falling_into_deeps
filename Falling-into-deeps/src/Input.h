#pragma once
#include "GLFW/glfw3.h"
#include "events/Event.h"

namespace Gear {
	void InitKeys();
	void OnEvent(Event& event);
	
	bool isKeyPressed(int key);
	bool GetKey(const std::string& key);
	bool GetMouseButton(int button);
	double getMouseX();
	double getMouseY();
}

