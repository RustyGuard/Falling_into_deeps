#include "gearpch.h"
#include "WindowsWindow.h"
#include <Glad/glad.h>
#include "events/KeyEvent.h"
#include "events/MouseEvent.h"

WindowsWindow::WindowsWindow(int width, int height, std::string title)
{
	int success = glfwInit();
	GEAR_CORE_ASSERT(success, "Could not intialize GLFW!");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(window);

	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	GEAR_CORE_ASSERT(status, "Failed to initialize Glad!");
	glfwSetWindowUserPointer(window, &data);

	// Set GLFW callbacks
	glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		data.Width = width;
		data.Height = height;

		WindowResizeEvent event(width, height);
		data.EventCallback(event);
	});

	glfwSetWindowCloseCallback(window, [](GLFWwindow* window)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		WindowCloseEvent event;
		data.EventCallback(event);
	});

	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		switch (action)
		{
		case GLFW_PRESS:
		{
			KeyPressedEvent event(key);
			data.EventCallback(event);
			break;
		}
		case GLFW_RELEASE:
		{
			KeyReleasedEvent event(key);
			data.EventCallback(event);
			break;
		}
		}
	});

	glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		switch (action)
		{
		case GLFW_PRESS:
		{
			MouseButtonPressedEvent event(button);
			data.EventCallback(event);
			break;
		}
		case GLFW_RELEASE:
		{
			MouseButtonReleasedEvent event(button);
			data.EventCallback(event);
			break;
		}
		}
	});

	glfwSetScrollCallback(window, [](GLFWwindow* window, double xOffset, double yOffset)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		MouseScrolledEvent event((float)xOffset, (float)yOffset);
		data.EventCallback(event);
	});

	glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xPos, double yPos)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		MouseMovedEvent event((float)xPos, (float)yPos);
		data.EventCallback(event);
	});

	glfwSetCharCallback(window, [](GLFWwindow* window, unsigned int key)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		CharInputedEvent event((wchar_t)key);
		data.EventCallback(event);
	});

	glfwSetErrorCallback([](int code, const char* error)
	{
		GEAR_ERROR(std::to_string(code) + " " + error);
	});
}

void WindowsWindow::PollEvents()
{
	glfwPollEvents();
}

void WindowsWindow::SwapBuffers()
{
	glfwSwapBuffers(window);
}

#ifdef GEAR_PLATFORM_WINDOWS

Window* Window::Create(int width, int height, std::string title)
{
	return new WindowsWindow(width, height, title);
}

#endif


