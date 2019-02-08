#pragma once
#include "glm/glm.hpp"

namespace Gear {
	void Init();
	void Draw(glm::vec3 pos, glm::vec3 half_extern);
	void Move();
	void ClearColor(float r, float g, float b, float a);
	void Clear();
}