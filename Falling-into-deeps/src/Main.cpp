#include "Log.h"
#include "sgtpch.h"
#include "Window.h"
#include <glad/glad.h>

int main()
{
	sgt::Log::Init();

	SGT_CORE_INFO("Project compiled succesfuly");
	Window* window = Window::Create();
	bool running = true;
	while (running)
	{
		glClearColor(1, 1.0f, 0.5f, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		window->OnUpdate();
	}
}
