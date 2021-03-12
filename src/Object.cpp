#include <Object.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Camera.h>
#include <Physics.h>
#include <Scene.h>

glm::vec3 Object::calculateNetForce() {
  Scene* scene = Scene::GetScene();

  glm::vec3 netForce = glm::vec3(0.0f, 0.0f, 0.0f);
  for (int i = 0; i < scene->objects.size(); i++) {
    if (scene->objects[i].fixed == false && &scene->objects[i] != this) {
      float distanceObjects = glm::distance(
        scene->objects[i].transform_.position,
        this->transform_.position);
      netForce +=
        (Physics::G() * this->mass * scene->objects[i].mass) /
        ((float)pow(distanceObjects, 2.0f)) *
        glm::normalize(
          scene->objects[i].transform_.position - this->transform_.position);
      std::cout << netForce.x << netForce.y << netForce.z << std::endl;
    }
  }
  return netForce;
}
void Object::update(double dt) {
  if (Physics::enabled == 1 && this->fixed == false) {
    this->velocity += this->netAcceleration() * (float)dt;
    this->transform_.position = this->transform_.position + this->velocity * (float)dt;

    if (this->trailObj != nullptr) {
      this->trailPositions.push_back(this->transform_.position);
    }
  }
}

void Object::draw() {
  if (this->trailObj != nullptr) {
    for (int i = 0; i < this->trailPositions.size(); i++) {
      trailObj->setPosition(this->trailPositions[i]);
      trailObj->draw();
    }
  }
  this->shader_.use();

  glm::mat4 model = glm::translate(glm::mat4(1.0f), this->transform_.position);
  model = glm::scale(model, this->transform_.scale);
  glm::mat4 view = Camera::GetCamera()->getViewMat();
  glm::mat4 proj = glm::perspective(glm::radians(45.0f), 1920.0f / 1080.0f, 0.5f, 100.0f);

  glm::mat4 trans = proj * view * model;

  glUniformMatrix4fv(glGetUniformLocation(this->shader_.id, "transform"), 1, GL_FALSE, glm::value_ptr(trans));

  if (this->texture != nullptr) {
    glActiveTexture(GL_TEXTURE0);
    this->texture->bind();
    // glUniform1i(glGetUniformLocation(this->shader_.id, "texture1"), 0);
  }

  this->mesh_->draw();

  this->texture->unBind();
}

void Object::setMesh(Mesh* mesh) {
  this->mesh_ = mesh;
}

void Object::setColor(glm::vec3 color)
{
  this->shader_.use();
  glUniform3f(glGetUniformLocation(this->shader_.id, "in_color"), color.x, color.y, color.z);
}

void Object::setTexture(Texture* texture) {
  this->shader_.use();
  glUniform1i(glGetUniformLocation(this->shader_.id, "hasTexture"), 1);
  this->texture = texture;
}
