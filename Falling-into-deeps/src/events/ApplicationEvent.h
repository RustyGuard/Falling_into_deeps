#include "Event.h"

class RenderEvent : public Event
{
public:
	RenderEvent() {}
	EVENT_CLASS_TYPE(AppRender)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class UpdateEvent : public Event
{
public:
	UpdateEvent(float delta) : delta(delta) {}
	EVENT_CLASS_TYPE(AppUpdate)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
	float GetDelta() { return delta; }
private:
	float delta;
};