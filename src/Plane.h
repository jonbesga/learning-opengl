#include <Object.h>
#include <MeshPlane.h>

class Plane : public Object {
public:
  MeshPlane mesh;
  Plane() : Object() {
    this->setMesh(&mesh);
  };
  Plane(Transform transform) : Object(transform) {
    this->setMesh(&mesh);
  };
};