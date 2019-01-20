#pragma once
#include "Event.h"

class KeyEvent : public Event
{
public:
	inline int GetKeyCode() const { return key; }

	EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

protected:
	KeyEvent(int key) : key(key) {}
	int key;
};

class KeyReleaseEvent : public KeyEvent
{
public:
	KeyReleaseEvent(int key) : KeyEvent(key) {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << key;
		return ss.str();
	}
	EVENT_CLASS_TYPE(KeyReleased)
};

class KeyPressEvent : public KeyEvent
{
public:
	KeyPressEvent(int key) : KeyEvent(key) {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << key;
		return ss.str();
	}
	EVENT_CLASS_TYPE(KeyPressed)
};

class CharInputedEvent : public Event
{
public:
	CharInputedEvent(unsigned int ch) : ch(ch) {}
	unsigned int getInputed() { return ch; }

	EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	EVENT_CLASS_TYPE(InputedChar)
private:
	unsigned int ch;
};