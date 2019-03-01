#pragma once
#include "Component.h"
#include "glm/glm.hpp"
#include "graphics/Graphics.h"

class TransformComponent : public Component
{
public:
	void Move(float x, float y)
	{
		position.x += x;
		position.y += y;
		moved = true;
	}
	void Draw()
	{
		Gear::Draw(position, half_extern);
	}
	bool isMoved()
	{
		if (moved)
		{
			moved = false;
			return true;
		}
		return false;
	}
	bool isMovable()
	{
		return movable;
	}
	void setMovable(bool m)
	{
		movable = m;
	}
	TransformComponent();
	glm::vec3 position;
	glm::vec3 half_extern;
	bool moved = true;
	bool movable = true;
	bool Collide(TransformComponent * transform);
};
