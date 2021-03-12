
// My original camera
// #include <glm/glm.hpp>

// class Camera {
// protected:
//   Camera() : viewVector(glm::vec3(0.0f, -2.0f, -50.0f)) {};
//   static Camera* camera_;
// public:
//   static Camera* GetCamera();
//   const float cameraSpeed = 0.05f;
//   glm::vec3 viewVector;
//   glm::mat4 getViewMat();
// };

#include <glm/glm.hpp>

class Camera {
protected:
  glm::vec3 cameraPos = glm::vec3(0.0f, 1.0f, 10.0f);
  glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
  glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);


  glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
  glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));

  glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);

  glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);

  Camera() {};
  static Camera* camera_;

public:
  static Camera* GetCamera();
  float cameraSpeed = 2.5f;
  glm::mat4 getViewMat();

  void forward();
  void left();
  void right();
  void back();
  void setCameraFront(glm::vec3 direction) {
    this->cameraFront = direction;
  }
};