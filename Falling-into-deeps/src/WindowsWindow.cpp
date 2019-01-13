#include "sgtpch.h"
#include "WindowsWindow.h"
#include <Glad/glad.h>
#include "events/WindowEvent.h"

WindowsWindow::WindowsWindow(int width, int height, std::string title)
{
	int success = glfwInit();
	SGT_CORE_ASSERT(success, "Could not intialize GLFW!");

	window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(window);

	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	SGT_CORE_ASSERT(status, "Failed to initialize Glad!");
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
			//KeyPressedEvent event(key, 0);
			//data.EventCallback(event);
			break;
		}
		case GLFW_RELEASE:
		{
			//KeyReleasedEvent event(key);
			//data.EventCallback(event);
			break;
		}
		case GLFW_REPEAT:
		{
			//KeyPressedEvent event(key, 1);
			//data.EventCallback(event);
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
			//MouseButtonPressedEvent event(button);
			//data.EventCallback(event);
			break;
		}
		case GLFW_RELEASE:
		{
			//MouseButtonReleasedEvent event(button);
			//data.EventCallback(event);
			break;
		}
		}
	});

	glfwSetScrollCallback(window, [](GLFWwindow* window, double xOffset, double yOffset)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		//MouseScrolledEvent event((float)xOffset, (float)yOffset);
		//data.EventCallback(event);
	});

	glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xPos, double yPos)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		//MouseMovedEvent event((float)xPos, (float)yPos);
		//data.EventCallback(event);
	});
}

void WindowsWindow::OnUpdate()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

Window* Window::Create(int width, int height, std::string title)
{
	return new WindowsWindow(400, 225, "Windows!");
}
