#pragma once
#include "sgtpch.h"
#include "Event.h"

class MouseMovedEvent : public Event
{
public:
	MouseMovedEvent(int x, int y) : mouseX(x), mouseY(y) {}
	inline float GetX() const { return mouseX; }
	inline float GetY() const { return mouseY; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseMovedEvent: " << mouseX << ", " << mouseY;
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseMoved)
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
private:
	int mouseX, mouseY;
};

class MouseScrolledEvent : public Event
{
public:
	MouseScrolledEvent(float xOffset, float yOffset) : XOffset(xOffset), YOffset(yOffset) {}
	inline float GetXOffset() const { return XOffset; }
	inline float GetYOffset() const { return YOffset; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseScrolled)
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

private:
	float XOffset, YOffset;

};
class MouseButtonEvent : public Event
{
public:
	inline int GetMouseButton() const { return button; }
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
protected:
	MouseButtonEvent(int x, int y, int button) : button(button) {}
	int x, y, button;
};

class MouseButtonReleaseEvent : public MouseButtonEvent
{
public:
	MouseButtonReleaseEvent(int x, int y, int button) : MouseButtonEvent(x, y, button) {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonReleasedEvent: " << button;
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseButtonReleased)
};

class MouseButtonPressEvent : public MouseButtonEvent
{
public:
	MouseButtonPressEvent(int x, int y, int button) : MouseButtonEvent(x, y, button) {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonPressedEvent: " << button;
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseButtonPressed)
};