class VertexBuffer {
public:
  unsigned int id;
  VertexBuffer(float arr[], int size);
  void bind();
  void unBind();
};