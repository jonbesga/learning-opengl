#include <Object.h>
#include <MeshPlane.h>

class Plane : public Object {
public:
  MeshPlane meshPlane;
  Plane(Transform transform) : Object(transform, &meshPlane) {};
};