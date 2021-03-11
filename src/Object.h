#include <glm/glm.hpp>

#include <Mesh.h>
#include <Shader.h>
#include <MeshPlane.h>

struct Transform {
  glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
  glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
  glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
};

class Object {
private:
  Transform transform_;
  MeshPlane mesh_;
  ShaderProgram shader_;
public:
  Object(Transform transform, MeshPlane mesh) :
    Object(transform, mesh, "res/shaders/basic.shader") {};

  Object(Transform transform, MeshPlane mesh, const std::string& shaderFilePath) :
    transform_(transform),
    mesh_(mesh),
    shader_(ShaderProgram(shaderFilePath))
  {};

  void draw();

};