#include <Object.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Camera.h>

#include <glad/glad.h>

void Object::draw() {
  this->shader_.use();

  glm::mat4 model = glm::translate(glm::mat4(1.0f), this->transform_.position);
  model = glm::scale(model, this->transform_.scale);
  glm::mat4 view = Camera::GetCamera()->getViewMat();
  glm::mat4 proj = glm::perspective(glm::radians(45.0f), 640.0f / 480.0f, 0.5f, 100.0f);

  glm::mat4 trans = proj * view * model;

  glUniformMatrix4fv(glGetUniformLocation(this->shader_.id, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
  std::cout << "mesh trans: " << &this->mesh_ << std::endl;
  this->mesh_->draw();
}
