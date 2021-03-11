#pragma once

class IndexBuffer {
public:
  unsigned int id;
  IndexBuffer(int arr[], int size);
  void bind();
  void unBind();
};
