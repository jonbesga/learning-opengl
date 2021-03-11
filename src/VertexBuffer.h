#pragma once

class VertexBuffer {
public:
  unsigned int id;
  VertexBuffer();
  void bufferData(const float arr[], int size);
  void bind();
  void unBind();
};