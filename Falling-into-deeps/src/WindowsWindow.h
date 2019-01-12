#include "Window.h"
#include "sgtpch.h"
#include <GLFW/glfw3.h>

class WindowsWindow : public Window
{
public:
	WindowsWindow(int width, int height, std::string title);

	void OnUpdate() override;
	unsigned int GetWidth() const override { return data.Width; }
	unsigned int GetHeight() const override { return data.Height; }

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
