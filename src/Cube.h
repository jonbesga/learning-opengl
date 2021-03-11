#include <Object.h>
#include <MeshCube.h>

class Cube : public Object {
public:
  MeshCube mesh;
  Cube(Transform transform) : Object(transform, &mesh) {};
};
