#include "sgtpch.h"
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

VertexArray* VAO;
VertexBuffer* vertexBuffer;
IndexBuffer* indexBuffer;
Shader* shader;
glm::mat4 proj;
glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);

std::unordered_map<std::string, unsigned int> textures;

float scale;
glm::vec3 view;

void Graphics::Init()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	proj = glm::mat4(glm::ortho(-480.0f, 480.0f, 270.0f, -270.0f, 0.0f, 1.0f));
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

	shader = new Shader("res/shader/Basic.shader");
}

void Graphics::Draw()
{
	glm::mat4 position = glm::translate(glm::mat4(1.0f), pos);
	glm::mat4 mvp = proj * position;
	VAO->bind();
	indexBuffer->bind();
	shader->bind();
	shader->setUniformMat4("u_MVP", mvp);
	glDrawElements(GL_TRIANGLES, indexBuffer->getCount(), GL_UNSIGNED_INT, nullptr);
}

void Graphics::Draw(glm::vec3 pos, glm::vec3 half_extern)
{
	glm::mat4 model = glm::translate(glm::mat4(1.0f), pos);
	glm::mat4 mvp = glm::scale(glm::mat4(1.0f), glm::vec3(scale, scale, 0.0f)) * proj * glm::translate(glm::mat4(1.0f), view) * model * glm::scale(glm::mat4(1.0f), half_extern);
	VAO->bind();
	indexBuffer->bind();
	shader->bind();
	shader->setUniformMat4("u_MVP", mvp);
	glDrawElements(GL_TRIANGLES, indexBuffer->getCount(), GL_UNSIGNED_INT, nullptr);
}

void Graphics::Move()
{
	if (Input::isKeyPressed(GLFW_KEY_UP))
		scale += 0.1f;
	if (Input::isKeyPressed(GLFW_KEY_DOWN) && scale > 0.25f)
		scale -= 0.1f;
	if (Input::isKeyPressed(GLFW_KEY_LEFT))
		view.x -= 1.1f;
	if (Input::isKeyPressed(GLFW_KEY_RIGHT))
		view.x += 1.1f;
}
