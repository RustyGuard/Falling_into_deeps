#include "gearpch.h"
#include "IndexBuffer.h"
#include <glad/glad.h>

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) : m_Count(count) {
	glGenBuffers(1, &m_RendererId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer() {
	glDeleteBuffers(1, &m_RendererId);
}

void IndexBuffer::bind() const {
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererId);
}

void IndexBuffer::unbind() const {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}