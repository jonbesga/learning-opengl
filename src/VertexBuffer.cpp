#include <glad/glad.h>
#include <VertexBuffer.h>

VertexBuffer::VertexBuffer(float arr[], int size) {
  glGenBuffers(1, &id);
  bind();
  glBufferData(GL_ARRAY_BUFFER, size, arr, GL_STATIC_DRAW);
}

void VertexBuffer::bind() {
  glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VertexBuffer::unBind() {
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}