#include <VertexArray.h>
#include <glad/glad.h>

VertexArray::VertexArray() {
  glGenVertexArrays(1, &this->id);
  this->bind();
}

void VertexArray::bind() {
  glBindVertexArray(this->id);
}

void VertexArray::unBind() {
  glBindVertexArray(0);
}