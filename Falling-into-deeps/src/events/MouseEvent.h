#pragma once
#include "gearpch.h"
#include "Event.h"

class MouseMovedEvent : public Event
{
public:
	MouseMovedEvent(double x, double y) : mouseX(x), mouseY(y) {}
	inline double GetX() const { return mouseX; }
	inline double GetY() const { return mouseY; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseMovedEvent: " << mouseX << ", " << mouseY;
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseMoved)
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
private:
	double mouseX, mouseY;
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
	MouseButtonEvent(int button, int action) : button(button), action(action) {}

	inline int GetAction() const { return action; }
	inline int GetMouseButton() const { return button; }
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	EVENT_CLASS_TYPE(MouseButton)

protected:
	int button, action;
};
