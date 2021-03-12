#pragma once
#include <glm/glm.hpp>

#include <Mesh.h>
#include <Shader.h>
#include <Texture.h>
#include <vector>
struct Transform {
  glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
  glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
  glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
};

class Object {
private:

  Mesh* mesh_ = nullptr;
  Texture* texture = nullptr;
  ShaderProgram shader_;

  glm::vec3 velocity = glm::vec3(0.0f, 0.0f, 0.0f);
  bool fixed = false;
  Object* trailObj = nullptr;
  // glm::vec3 netAcceleration() { return glm::vec3(0.0f, -9.81f, 0.0f); };
  glm::vec3 netAcceleration() { return this->calculateNetForce() / this->mass; };
  std::vector<glm::vec3> trailPositions;

public:
  Transform transform_;
  float mass = 1.0f;
  Object() :
    Object({ glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(1.0f, 1.0f, 1.0f) }, "res/shaders/default.shader") {};
  Object(Transform transform) :
    Object(transform, "res/shaders/default.shader") {};

  Object(Transform transform, const std::string& shaderFilePath) :
    transform_(transform),
    shader_(ShaderProgram(shaderFilePath))
  {};
  void setColor(glm::vec3 color);
  void setTexture(Texture* texture);
  void setPosition(glm::vec3 position) {
    this->transform_.position = position;
  }
  void setMesh(Mesh* mesh);
  void update(double dt);
  void draw();
  void setTrail(Object* trailObj) {
    this->trailObj = trailObj;
  }
  void deleteTrail() {
    this->trailObj = nullptr;
  }
  void setVelocity(glm::vec3 vel) { this->velocity = vel; }
  void setFixed(bool v) { this->fixed = v; }
  glm::vec3 calculateNetForce();
};