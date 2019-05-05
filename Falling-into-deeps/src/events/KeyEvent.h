#pragma once
#include "Event.h"

class KeyEvent : public Event
{
public:
	KeyEvent(int key) : key(key) {}

	inline int GetKeyCode() const { return key; }

	EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
protected:
	int key;
};

class KeyReleasedEvent : public KeyEvent
{
public:
	KeyReleasedEvent(int key) : KeyEvent(key) {}
	EVENT_CLASS_TYPE(KeyRelease)
};

class KeyPressedEvent : public KeyEvent
{
public:
	KeyPressedEvent(int key) : KeyEvent(key) {}
	EVENT_CLASS_TYPE(KeyPress)
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