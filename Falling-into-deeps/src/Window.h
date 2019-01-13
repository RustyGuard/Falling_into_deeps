#pragma once
#include "sgtpch.h"
#include "events/Event.h"

#include "sgtpch.h"

class Window
{
public:
	using EventCallbackFn = std::function<void(Event&)>;

	virtual ~Window() {}
	virtual void OnUpdate() = 0;
	virtual unsigned int GetWidth() const = 0;
	virtual unsigned int GetHeight() const = 0;
	virtual void Close() = 0;
	virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
	virtual void DeleteContext() = 0;

	static Window* Create(int width = 960, int height = 580, std::string title = "Application");
};