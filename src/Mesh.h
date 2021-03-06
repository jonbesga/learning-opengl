#pragma once
#include <glm/glm.hpp>
#include <VertexArray.h>
#include <VertexBuffer.h>
#include <IndexBuffer.h>


class Mesh {
private:
  int indices_size;
  int vertices_size;

  VertexArray vao;
  VertexBuffer vbo;
  IndexBuffer ibo;
public:
  Mesh() {};
  void setup(float* vertices, int vertices_size, int* indices, int indices_size, int offsetTexture);
  void draw();

};

