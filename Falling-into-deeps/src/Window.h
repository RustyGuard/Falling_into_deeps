#pragma once
#include "sgtpch.h"
#include "Event.h"

#include "sgtpch.h"

class Window
{
public:
	virtual ~Window() {}
	virtual void OnUpdate() = 0;
	virtual unsigned int GetWidth() const = 0;
	virtual unsigned int GetHeight() const = 0;

	using EventCallbackFn = std::function<void(Event&)>;

	static Window* Create(int width = 960, int height = 580, std::string title = "Application");
};