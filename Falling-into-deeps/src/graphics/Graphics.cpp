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

VertexArray* VAO;
VertexBuffer* vertexBuffer;
IndexBuffer* indexBuffer;
Shader* shader;
glm::mat4 proj;
glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);

std::unordered_map<std::string, unsigned int> textures;

float scale;
glm::vec3 view;

void Gear::Init()
{
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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

	shader->setUniform1i("u_Texture", 0);
}

void Gear::Draw(glm::vec3 pos, glm::vec3 half_extern)
{
	glColor4f(1.0f, 0.2f, 0.3f, 1.0f);
	glm::mat4 model = glm::translate(glm::mat4(1.0f), pos);
	glm::mat4 mvp = glm::scale(glm::mat4(1.0f), glm::vec3(scale, scale, 0.0f)) * proj * glm::translate(glm::mat4(1.0f), view) * model * glm::scale(glm::mat4(1.0f), half_extern);
	VAO->bind();
	indexBuffer->bind();
	shader->bind();
	shader->setUniformMat4("u_MVP", mvp);
	glDrawElements(GL_TRIANGLES, indexBuffer->getCount(), GL_UNSIGNED_INT, nullptr);
}

void Gear::Move()
{
	if (Gear::isKeyPressed("up"))
		scale += 0.1f;
	if (Gear::isKeyPressed("down") && scale > 0.15f)
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
	glClear(GL_COLOR_BUFFER_BIT);
}
