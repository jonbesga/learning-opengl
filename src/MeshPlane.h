#pragma once
#include <Mesh.h>

class MeshPlane : public Mesh {

public:
  float vertices[32] = {
    -0.5f, 0.0f, 0.5f,     1.0f, 0.0f, 0.0f,   0.0f, 0.0f,
    0.5f, 0.0f, 0.5f,     1.0f, 0.0f, 0.0f,   0.0f, 1.0f,
    -0.5f, 0.0f, -0.5f,    1.0f, 0.0f, 0.0f,   0.0f, 0.0f,
    0.5f, 0.0f, -0.5f,      1.0f, 0.0f, 0.0f,   0.0f, 1.0f,
  };
  int indices[6] = {
    0, 1, 2,
    1, 2, 3
  };
  int getIndicesSize() { return sizeof(this->indices); };
  int getVerticesSize() { return sizeof(this->vertices); };
  float* getVertices() { return this->vertices; };
  int* getIndices() { return this->indices; };

  MeshPlane() : Mesh() {
    this->setup(getVertices(), getVerticesSize(), getIndices(), getIndicesSize());
  };

};

