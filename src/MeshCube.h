#pragma once
#include <Mesh.h>

class MeshCube : public Mesh {

public:
  int offsetTexture = 72;
  float vertices[12 * 6 * 2] = {
    // front face
    -0.5f, -0.5f, 0.5f,
    0.5f, -0.5f, 0.5f,
    -0.5f, 0.5f, 0.5f,
    0.5f, 0.5f, 0.5f,
    // back face
    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    -0.5f, 0.5f, -0.5f,
    0.5f, 0.5f, -0.5f,
    // left face
    -0.5f, -0.5f, 0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, 0.5f, 0.5f,
    -0.5f, 0.5f, -0.5f,
    // right face
    0.5f, -0.5f, 0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f, 0.5f, 0.5f,
    0.5f, 0.5f, -0.5f,
    // top face
    -0.5f, 0.5f, 0.5f,
    0.5f, 0.5f, 0.5f,
    -0.5f, 0.5f, -0.5f,
    0.5f, 0.5f, -0.5f,
    // bottom face
    -0.5f, -0.5f, 0.5f,
    0.5f, -0.5f, 0.5f,
    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,

    // text coords
    0.0f, 0.0f,
    1.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,

    0.0f, 0.0f,
    1.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,

    0.0f, 0.0f,
    1.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,

    0.0f, 0.0f,
    1.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,

    0.0f, 0.0f,
    1.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,

    0.0f, 0.0f,
    1.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,
  };
  int indices[6 * 6] = {
    // front face
    0, 1, 2,
    1, 2, 3,
    // back face
    4, 5, 6,
    5, 6, 7,
    // left face
    8, 9, 10,
    9, 10, 11,
    // right face
    12, 13, 14,
    13, 14, 15,
    // top face
    16, 17, 18,
    17, 18, 19,
    // bottom face
    20, 21, 22,
    21, 22, 23
  };
  int getIndicesSize() { return sizeof(this->indices); };
  int getVerticesSize() { return sizeof(this->vertices); };
  float* getVertices() { return this->vertices; };
  int* getIndices() { return this->indices; };

  MeshCube() : Mesh() {
    this->setup(getVertices(), getVerticesSize(), getIndices(), getIndicesSize(), this->offsetTexture);
  };

};

