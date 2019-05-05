#include "gearpch.h"
#include "Graphics.h"
#include <Glad/glad.h>

#include "graphics/IndexBuffer.h"
#include "graphics/VertexArray.h"
#include "graphics/VertexBuffer.h"
#include "graphics/VertexBufferLayout.h"
#include "graphics/Shader.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Input.h"
#include "stbi/stbi_image.h"

VertexArray* VAO;
VertexBuffer* vertexBuffer;
IndexBuffer* indexBuffer;
glm::mat4 proj;
glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);

std::unordered_map<std::string, unsigned int> textures;
std::unordered_map<std::string, Shader*> shaders;

float scale;
glm::vec3 view;

void Gear::Init()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DEPTH_FUNC);

	glDepthFunc(GL_LEQUAL);

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.2f);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	float w = SCREEN_WIDTH / 2;
	float h = SCREEN_HEIGHT / 2;
	proj = glm::mat4(glm::ortho(-w, w, h, -h, 0.0f, 1.0f));
	scale = 1.0f;
	view = glm::vec3(0, 0, 0);

	float positions[16] = {
		-1.0f, -1.0f, 0.0f, 0.0f, //0
		1.0f, -1.0f, 1.0f, 0.0f,  //1
		1.0f, 1.0f, 1.0f, 1.0f,   //2
		-1.0f, 1.0f, 0.0f, 1.0f   //3
	};

	unsigned int indices[6]{
		0, 1, 2,
		3, 2, 0
	};

	VAO = new VertexArray();

	vertexBuffer = new VertexBuffer(positions, 4 * 4 * sizeof(float));

	VertexBufferLayout layout;
	layout.push<float>(2);
	layout.push<float>(2);
	VAO->addBuffer(*vertexBuffer, layout);

	indexBuffer = new IndexBuffer(indices, 6);

	shaders["default"] = new Shader("res/shader/Basic.shader");
	shaders["default"]->setUniform1i("u_Texture", 0);

	shaders["ui"] = new Shader("res/shader/Ui.shader");
	shaders["ui"]->setUniform1i("u_Texture", 0);
}

void Gear::DrawUI(unsigned int texture, glm::vec3 pos, glm::vec3 half_extern, float x_change, float y_change)
{
	glm::mat4 model = glm::translate(glm::mat4(1.0f), pos);
	glm::mat4 mvp = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f)) * proj * glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)) * model * glm::scale(glm::mat4(1.0f), half_extern);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	shaders["ui"]->bind();
	shaders["ui"]->setUniformMat4("u_MVP", mvp);
	shaders["ui"]->setUniform1f("x_mul", x_change);
	shaders["ui"]->setUniform1f("y_mul", y_change);
	VAO->bind();
	indexBuffer->bind();
	glDrawElements(GL_TRIANGLES, indexBuffer->getCount(), GL_UNSIGNED_INT, nullptr);
	shaders["ui"]->unbind();
}

void Gear::DrawEntity(unsigned int texture, glm::vec3 pos, glm::vec3 half_extern, float z)
{
	glm::mat4 model = glm::translate(glm::mat4(1.0f), pos);
	glm::mat4 mvp = glm::scale(glm::mat4(1.0f), glm::vec3(scale, scale, 1.0f)) * proj * glm::translate(glm::mat4(1.0f), view) * model * glm::scale(glm::mat4(1.0f), half_extern);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	shaders["default"]->bind();
	shaders["default"]->setUniformMat4("u_MVP", mvp);
	shaders["default"]->setUniform1f("z_coord", z);
	VAO->bind();
	indexBuffer->bind();
	glDrawElements(GL_TRIANGLES, indexBuffer->getCount(), GL_UNSIGNED_INT, nullptr);
	shaders["default"]->unbind();
}

void Gear::Move()
{
	if (Gear::GetKey("up") && scale < 3.0f)
		scale += 0.1f;
	if (Gear::GetKey("down") && scale > 0.35f)
		scale -= 0.1f;
}

float Gear::GetCameraX()
{
	return view.x;
}

float Gear::GetCameraY()
{
	return view.y;
}

void Gear::MoveCamera(float x, float y)
{
	view.x += x;
	view.y += y;
}

void Gear::ClearColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

void Gear::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

unsigned int Gear::CreateTexture(const std::string & path)
{
	if (textures.find(path) != textures.end())
	{
		return textures[path];
	}
	unsigned int m_RendererId;
	unsigned char* m_LocalBuffer;
	int width, height, BPP;

	//stbi_set_flip_vertically_on_load(1);
	m_LocalBuffer = stbi_load(path.c_str(), &width, &height, &BPP, 4);

	glGenTextures(1, &m_RendererId);
	glBindTexture(GL_TEXTURE_2D, m_RendererId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);

	if (m_LocalBuffer)
		stbi_image_free(m_LocalBuffer);

	glBindTexture(GL_TEXTURE_2D, 0);

	textures[path] = m_RendererId;
	return m_RendererId;
}

void Gear::BindShader(const std::string & shader)
{
	shaders[shader]->bind();
}
