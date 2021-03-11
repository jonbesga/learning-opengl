#pragma once
#include <glm/glm.hpp>
#include <VertexArray.h>
#include <VertexBuffer.h>
#include <IndexBuffer.h>


class Mesh {
public:
  Mesh(float vertices[], int vertices_size, int indices[], int indices_size);
  void draw();
protected:
  void setup();
private:
  float* vertices;
  int* indices;
  int indices_size;
  int vertices_size;

  VertexArray vao;
  VertexBuffer vbo;
  IndexBuffer ibo;
};

