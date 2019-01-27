#pragma once
#include "GLFW/glfw3.h"

class Input
{
public:
	static void keyPressed(int key);
	static void keyReleased(int key);
	
	static bool isKeyPressed(int key);
};

