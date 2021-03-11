#include <glm/glm.hpp>

class Camera {
protected:
  Camera() : viewVector(glm::vec3(0.0f, -2.0f, -5.0f)) {};
  static Camera* camera_;
public:
  static Camera* GetCamera();
  const float cameraSpeed = 0.05f;
  glm::vec3 viewVector;
  glm::mat4 getViewMat();
};