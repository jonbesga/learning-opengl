#pragma once

class VertexBuffer {
public:
  unsigned int id;
  VertexBuffer(const float arr[], int size);
  void bind();
  void unBind();
};