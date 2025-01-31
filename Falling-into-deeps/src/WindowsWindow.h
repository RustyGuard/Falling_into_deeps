#include "Window.h"
#include "gearpch.h"
#include <GLFW/glfw3.h>
#include "events/WindowEvent.h"

class WindowsWindow : public Window
{
public:
	WindowsWindow(int width, int height, std::string title);

	void PollEvents();
	void SwapBuffers();
	unsigned int GetWidth() const override { return data.Width; }
	unsigned int GetHeight() const override { return data.Height; }

	inline void SetEventCallback(const EventCallbackFn& callback) override { data.EventCallback = callback; }

	void Close() override
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
		data.EventCallback(WindowCloseEvent());
	}

	void DeleteContext() override
	{
		glfwTerminate();
	}
private:
	GLFWwindow* window;

	struct WindowData
	{
		std::string Title;
		unsigned int Width, Height;
		int mouseX, mouseY;

		EventCallbackFn EventCallback;
	};

	WindowData data;
};
