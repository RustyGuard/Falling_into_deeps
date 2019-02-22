#include "gearpch.h"
#include "TransformComponent.h"


TransformComponent::TransformComponent()
{
	half_extern = glm::vec3(64.0f, 64.0f, 0.0f);
	position = glm::vec3(0.0f, 0.0f, 0.0f);
}

void TransformComponent::Collide(TransformComponent * transform)
{
	int distX = position.x - transform->position.x;
	int distY = position.y - transform->position.y;

	if (abs(distX) < half_extern.x + transform->half_extern.x && abs(distY) < half_extern.y + transform->half_extern.y)
	{
		if (abs(distX) > abs(distY))
		{
			if (distX > 0)
			{
				position.x = transform->position.x + (half_extern.x + transform->half_extern.x);
			}
			else
			{
				position.x = transform->position.x - (half_extern.x + transform->half_extern.x);
			}
		}
		else
		{
			if (distY > 0)
			{
				position.y = transform->position.y + (half_extern.y + transform->half_extern.y);
			}
			else
			{
				position.y = transform->position.y - (half_extern.y + transform->half_extern.y);
			}
		}
	}
}
