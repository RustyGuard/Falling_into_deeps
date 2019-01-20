#pragma once

#include "sgtpch.h"
#define BIT(x) 1 << x

enum class EventType
{
	None = 0,
	WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
	AppUpdate, AppRender,
	KeyPressed, KeyReleased, InputedChar,
	MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};
	enum EventCategory
{
	None = 0,
	EventCategoryApplication = BIT(0),
	EventCategoryWindow = BIT(1),
	EventCategoryInput = BIT(2),
	EventCategoryKeyboard = BIT(3),
	EventCategoryMouse = BIT(4),
	EventCategoryMouseButton = BIT(5)
};
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
							virtual EventType GetEventType() const override { return GetStaticType(); }\
							virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

class Event
{
public:
	bool Handled = false;
	virtual EventType GetEventType() const = 0;
	virtual const char* GetName() const = 0;
	virtual int GetCategoryFlags() const = 0;
	virtual std::string ToString() const { return GetName(); }
	inline bool IsInCategory(EventCategory category)
	{
		return GetCategoryFlags() & category;
	}
};
	

inline std::ostream& operator<<(std::ostream& os, const Event& e)
{
	return os << e.ToString();
}