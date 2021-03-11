#include <glad/glad.h>
#include <IndexBuffer.h>

IndexBuffer::IndexBuffer() {
  glGenBuffers(1, &id);
}

void IndexBuffer::bufferData(int arr[], int size) {
  this->bind();
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, arr, GL_STATIC_DRAW);
}

void IndexBuffer::bind() {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void IndexBuffer::unBind() {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
