#include <Object.h>
#include <MeshCube.h>

class Cube : public Object {
public:
  MeshCube mesh;
  Cube() : Object() {
    this->setMesh(&mesh);
  }
  Cube(Transform transform) : Object(transform) {
    this->setMesh(&mesh);

  };
};
