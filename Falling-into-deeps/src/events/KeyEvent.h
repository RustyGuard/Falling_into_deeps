#pragma once
#include "Event.h"

class KeyEvent : public Event
{
public:
	KeyEvent(int key, int action) : key(key), action(action) {}

	inline int GetKeyCode() const { return key; }
	inline int GetAction() const { return action; }

	EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	EVENT_CLASS_TYPE(Key)

protected:
	KeyEvent(int key) : key(key) {}
	int key, action;
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