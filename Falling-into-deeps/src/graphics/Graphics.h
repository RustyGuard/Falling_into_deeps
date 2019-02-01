#pragma once
#include "glm/glm.hpp"

class Graphics
{
public:
	static void Init();
	static void Draw(glm::vec3 pos, glm::vec3 half_extern);
	static void Move();
	static void ClearColor(float r, float g, float b, float a);
	static void Clear();
};