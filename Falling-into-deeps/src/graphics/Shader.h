#pragma once

#include <string>
#include <unordered_map>
#include "glm/glm.hpp"

struct ShaderSource
{
	std::string vertex;
	std::string fragment;
};

class Shader
{
private:
	std::string m_FilePath;
	unsigned int m_RendererId;
	std::unordered_map<std::string, int> m_UniformLocationCache;
	int getUniformLocation(const std::string& name);
	unsigned int compileShader(unsigned int type, const std::string& source);
	unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
	ShaderSource parseShader();
public:
	Shader(const std::string& filepath);
	~Shader();

	void bind() const;
	void unbind() const;

	void setUniform1i(const std::string& name, int v0);
	void setUniform1f(const std::string& name, float v0);
	void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void setUniformMat4(const std::string& name, const glm::mat4& matrix);
};

