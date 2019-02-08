#include "gearpch.h"
#include "Input.h"

bool keys[GLFW_KEY_LAST];

void Input::keyPressed(int key)
{
	keys[key] = true;
}

void Input::keyReleased(int key)
{
	keys[key] = false;
}

bool Input::isKeyPressed(int key)
{
	return keys[key];
}
