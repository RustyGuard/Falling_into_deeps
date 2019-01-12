#include "sgtpch.h"
#include "Window.h"
#include <glad/glad.h>

void Window::CreateGLFWWindow(int width, int height, const char* title)
{
	int success = glfwInit();
	SGT_CORE_ASSERT(success, "Could not intialize GLFW!");

	window = glfwCreateWindow(width, height, "It`s a window!", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	SGT_CORE_ASSERT(status, "Failed to initialize Glad!");
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(window);
}

void Window::PollEvents()
{
	glfwPollEvents();
}
