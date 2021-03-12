#include <vector>
#include <Object.h>

class Scene {
protected:
  Scene() {};
  static Scene* scene_;

public:
  std::vector<Object> objects;
  static Scene* GetScene();
  void addObject(Object obj);
  void update(double dt);
};
