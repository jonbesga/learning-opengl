#include <Camera.h>
#include <glm/gtc/matrix_transform.hpp>

Camera* Camera::camera_ = nullptr;

Camera* Camera::GetCamera() {
  if (camera_ == nullptr) {
    camera_ = new Camera();
  }
  return camera_;
};

glm::mat4 Camera::getViewMat() {
  return glm::translate(glm::mat4(1.0f), this->viewVector);
}
