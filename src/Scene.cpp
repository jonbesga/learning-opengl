#include <Scene.h>

Scene* Scene::scene_ = nullptr;

Scene* Scene::GetScene() {
  if (scene_ == nullptr) {
    scene_ = new Scene();
  }
  return scene_;
};

void Scene::addObject(Object obj) {
  this->objects.push_back(obj);
}

void Scene::update(double dt) {
  for (int i = 0; i < this->objects.size(); i++) {
    objects[i].update(dt);
  }
  for (int i = 0; i < this->objects.size(); i++) {
    objects[i].draw();
  }
}