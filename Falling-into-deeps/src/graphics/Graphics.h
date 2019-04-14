#pragma once
#include "glm/glm.hpp"
#include <string>

namespace Gear {
	const int SCREEN_WIDTH = 1200;
	const int SCREEN_HEIGHT = 675;
	void Init();
	void Draw(glm::vec3 pos, glm::vec3 half_extern);
	void Move();
	float GetCameraX();
	float GetCameraY();
	void MoveCamera(float x, float y);
	void ClearColor(float r, float g, float b, float a);
	void Clear();
	unsigned int CreateTexture(const std::string& path);
	void BindTexture(unsigned int texture, unsigned int slot = 0);
}