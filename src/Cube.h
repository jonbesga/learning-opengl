#include <glm/glm.hpp>
#include <Shader.h>
#include <VertexArray.h>
#include <VertexBuffer.h>
#include <IndexBuffer.h>


class Cube {
public:
  Cube(glm::vec3 position) : Cube(position, "res/shaders/basic.shader") {};
  Cube(glm::vec3 position, const std::string& shaderFilePath);
  void draw();
private:
  float m_vertices[64] = {
    -0.5f, -0.5f, -1.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f,
    -0.5f, 0.5f, -1.0f,    0.0f, 1.0f, 0.0f,   0.0f, 1.0f,
    0.5f, -0.5f, -1.0f,    0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
    0.5f, 0.5f, -1.0f,     0.0f, 0.0f, 1.0f,   1.0f, 1.0f,

    -0.5f, -0.5f, -2.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f,
    -0.5f, 0.5f, -2.0f,    0.0f, 1.0f, 0.0f,   0.0f, 1.0f,
    0.5f, -0.5f, -2.0f,    0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
    0.5f, 0.5f, -2.0f,     0.0f, 0.0f, 1.0f,   1.0f, 1.0f
  };
  int m_indices[36] = {
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
  glm::vec3 m_position;
  ShaderProgram m_shader;
  VertexArray m_vao;
  VertexBuffer m_vbo;
  IndexBuffer m_ibo;
};