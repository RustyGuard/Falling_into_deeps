#pragma once
#include "glm/glm.hpp"
#include <string>

namespace Gear {
	const int SCREEN_WIDTH = 1200;
	const int SCREEN_HEIGHT = 675;
	void Init();
	void DrawEntity(unsigned int texture, glm::vec3 pos, glm::vec3 half_extern, float v0);
	void DrawUI(unsigned int texture, glm::vec3 pos, glm::vec3 half_extern, float x_change, float y_change);
	void Move();
	float GetCameraX();
	float GetCameraY();
	void MoveCamera(float x, float y);
	void ClearColor(float r, float g, float b, float a);
	void Clear();

	unsigned int CreateTexture(const std::string& path);
	void BindShader(const std::string& shader);
}