#pragma once
#include "Component.h"
#include "glm/glm.hpp"

class TransformComponent : public Component
{
public:
	void Move(float x, float y)
	{
		position.x += x;
		position.y += y;
	}
	TransformComponent();
	glm::vec3 position;
	glm::vec3 half_extern;
};
