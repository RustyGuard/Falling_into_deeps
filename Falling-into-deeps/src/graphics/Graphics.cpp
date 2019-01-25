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

VertexArray* VAO;
VertexBuffer* vertexBuffer;
IndexBuffer* indexBuffer;
Shader* shader;
glm::mat4 proj;
glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);

void Graphics::Init()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	proj = glm::mat4(glm::ortho(0.0f, 960.0f, 540.0f, 0.0f, 0.0f, 1.0f));

	float positions[16] = {
		-64.0f, -64.0f, 1.0f, 1.0f, //0
		64.0f, -64.0f, 0.0f, 1.0f,  //1
		64.0f, 64.0f, 0.0f, 0.0f,   //2
		-64.0f, 64.0f, 1.0f, 0.0f   //3
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

void Graphics::Move(float x, float y)
{
	pos.x += 0.1f;
	pos.y += 0.1f;
}
