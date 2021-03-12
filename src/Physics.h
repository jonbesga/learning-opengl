#include <glm/glm.hpp>

class Physics {
public:
  const static int enabled = 1;

  const static float G() { return 6.667e-11f; };
  const static glm::vec3 gravity() { return glm::vec3(0.0f, -9.81f, 0.0f); };
};