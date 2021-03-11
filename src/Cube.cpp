#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Cube.h>

#include <VertexBuffer.h>
#include <IndexBuffer.h>
#include <VertexArray.h>

#include <vector>
#include <Camera.h>

Cube::Cube(glm::vec3 position, const std::string& shaderFilePath = std::string()) :
  m_position(position),
  m_vbo(this->m_vertices, sizeof(this->m_vertices)),
  m_ibo(this->m_indices, sizeof(this->m_indices)),
  m_shader(ShaderProgram(shaderFilePath)) {

  std::vector<int> layouts;
  int count = 8;

  layouts.push_back(3);
  layouts.push_back(3);
  layouts.push_back(2);

  int offset = 0;
  for (int i = 0; i < layouts.size(); i++) {
    glEnableVertexAttribArray(i);
    glVertexAttribPointer(i, layouts[i], GL_FLOAT, GL_FALSE, sizeof(float) * count, (void*)(sizeof(float) * offset));
    offset += layouts[i];
  }

  this->m_ibo.unBind();
  this->m_vbo.unBind();
  this->m_vao.unBind();
}

void Cube::draw() {
  this->m_vao.bind();
  this->m_ibo.bind();
  this->m_shader.use();

  glm::mat4 model = glm::translate(glm::mat4(1.0f), this->m_position);
  glm::mat4 view = Camera::GetCamera()->getViewMat();
  glm::mat4 proj = glm::perspective(glm::radians(45.0f), 640.0f / 480.0f, 0.5f, 100.0f);

  glm::mat4 trans = proj * view * model;

  glUniformMatrix4fv(glGetUniformLocation(this->m_shader.id, "transform"), 1, GL_FALSE, glm::value_ptr(trans));

  glDrawElements(GL_TRIANGLES, sizeof(this->m_indices) / sizeof(int), GL_UNSIGNED_INT, nullptr);

  this->m_vao.unBind();
  this->m_ibo.unBind();
}

