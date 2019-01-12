#pragma once
#include <GLFW/glfw3.h>

class Window
{
public:
	void CreateGLFWWindow(int width, int height, const char* title);
	void SwapBuffers();
	void PollEvents();
private:
	GLFWwindow* window;
};