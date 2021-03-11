#pragma once
#include <Mesh.h>

class MeshCube : public Mesh {

public:
  float vertices[64] = {
  -0.5f, -0.5f, -1.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f,
  -0.5f, 0.5f, -1.0f,    0.0f, 1.0f, 0.0f,   0.0f, 1.0f,
  0.5f, -0.5f, -1.0f,    0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
  0.5f, 0.5f, -1.0f,     0.0f, 0.0f, 1.0f,   1.0f, 1.0f,

  -0.5f, -0.5f, -2.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f,
  -0.5f, 0.5f, -2.0f,    0.0f, 1.0f, 0.0f,   0.0f, 1.0f,
  0.5f, -0.5f, -2.0f,    0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
  0.5f, 0.5f, -2.0f,     0.0f, 0.0f, 1.0f,   1.0f, 1.0f
  };
  int indices[36] = {
  0, 2, 3,
  0, 3, 1,

  4, 6, 7,
  4, 7, 5,

  0, 1, 4,
  5, 4, 1,

  2, 3, 7,
  7, 6, 2,

  1, 3, 5,
  5, 3, 7,

  0, 2, 4,
  4, 2, 6
  };
  int getIndicesSize() { return sizeof(this->indices); };
  int getVerticesSize() { return sizeof(this->vertices); };
  float* getVertices() { return this->vertices; };
  int* getIndices() { return this->indices; };

  MeshCube() : Mesh() {
    this->setup(getVertices(), getVerticesSize(), getIndices(), getIndicesSize());
  };

};

