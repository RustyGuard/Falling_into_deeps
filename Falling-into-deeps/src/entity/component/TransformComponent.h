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
	}
	void Draw()
	{
		Gear::Draw(position, half_extern);
	}
	TransformComponent();
	glm::vec3 position;
	glm::vec3 half_extern;
};
