#pragma once

class IndexBuffer {
public:
  unsigned int id;
  IndexBuffer();
  void bufferData(int arr[], int size);
  void bind();
  void unBind();
};
