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
  return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
  // return glm::translate(glm::mat4(1.0f), this->viewVector);
}

void Camera::forward()
{
  cameraPos += cameraSpeed * cameraFront;
}

void Camera::left()
{
  cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}

void Camera::right()
{
  cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}

void Camera::back()
{
  cameraPos -= cameraSpeed * cameraFront;
}