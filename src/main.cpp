#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Camera.h>
#include <Cube.h>
#include <Plane.h>

#include <Texture.h>
#include <Scene.h>
#include <Physics.h>

float yaw = -90.0f;
float pitch = 0.0f;

double deltaTime = 0.0f;	// Time between current frame and last frame
double lastFrame = 0.0f; // Time of last frame
bool firstMouse = true;
float lastX = 1920 / 2, lastY = 1080 / 2;
void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
  if (firstMouse) { // initially set to true
    lastX = xpos;
    lastY = ypos;
    firstMouse = false;
  }
  float xoffset = xpos - lastX;
  float yoffset = lastY - ypos; // reversed since y-coordinates range from bottom to top
  lastX = xpos;
  lastY = ypos;

  const float sensitivity = 0.1f;
  xoffset *= sensitivity;
  yoffset *= sensitivity;

  yaw += xoffset;
  pitch += yoffset;

  if (pitch > 89.0f)
    pitch = 89.0f;
  if (pitch < -89.0f)
    pitch = -89.0f;

  glm::vec3 direction;
  direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
  direction.y = sin(glm::radians(pitch));
  direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
  glm::vec3 cameraFront = glm::normalize(direction);

  Camera* camera = Camera::GetCamera();
  camera->setCameraFront(cameraFront);
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
  if (key == GLFW_KEY_H && action == GLFW_PRESS) {
    int polygonMode[2];
    glGetIntegerv(GL_POLYGON_MODE, &polygonMode[0]);
    glPolygonMode(GL_FRONT_AND_BACK, polygonMode[0] == GL_FILL ? GL_LINE : GL_FILL);
  }
}

void processInput(GLFWwindow* window)
{
  Camera* camera = Camera::GetCamera();
  camera->cameraSpeed = 10.5f * deltaTime;
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
    camera->forward();
    // camera->viewVector -= camera->cameraSpeed * glm::vec3(0.0f, 0.0f, -1.0f);
  }
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
    camera->left();
    // camera->viewVector += camera->cameraSpeed * glm::vec3(1.0f, 0.0f, 0.0f);
  }
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
    camera->back();
    // camera->viewVector += camera->cameraSpeed * glm::vec3(0.0f, 0.0f, -1.0f);
  }
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
    camera->right();
    // camera->viewVector += camera->cameraSpeed * glm::vec3(-1.0f, 0.0f, 0.0f);
  }
}

int main(void) {
  GLFWwindow* window;

  if (!glfwInit()) {
    return -1;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window = glfwCreateWindow(1920, 1080, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGL()) {
    return -1;
  }

  glViewport(0, 0, 1920, 1080);
  glEnable(GL_DEPTH_TEST);
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
  glfwSetCursorPosCallback(window, mouse_callback);
  glfwSetKeyCallback(window, keyCallback);

  Cube redTrail({ glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(0.5f, 0.5f, 0.5f) });
  redTrail.setColor(glm::vec3(1.0f, 0.0f, 0.0f));

  Cube greenTrail({ glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(0.5f, 0.5f, 0.5f) });
  greenTrail.setColor(glm::vec3(0.0f, 1.0f, 0.0f));

  Cube blueTrail({ glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(0.5f, 0.5f, 0.5f) });
  blueTrail.setColor(glm::vec3(0.0f, 0.0f, 1.0f));

  Texture lois = Texture("res/textures/lois.jpg", true);
  Cube cube1({ glm::vec3(0.0f, 0.5f, 0.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(1.0f, 1.0f, 1.0f) });
  cube1.setColor(glm::vec3(0.0f, 1.0f, 0.0f));
  cube1.setTexture(&lois);
  cube1.setTrail(&redTrail);
  cube1.mass = 5e10;

  Texture nagore = Texture("res/textures/nagore.jpg", true);
  Cube cube2({ glm::vec3(2.0f, 100.5f, 0.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(1.0f, 1.0f, 1.0f) });
  cube2.setColor(glm::vec3(0.0f, 1.0f, 0.0f));
  cube2.setTexture(&nagore);
  cube2.setTrail(&greenTrail);

  Texture tobal = Texture("res/textures/tobal.jpg", true);
  Cube cube3({ glm::vec3(-2.0f, 300.5f, 0.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(1.0f, 1.0f, 1.0f) });
  cube3.setColor(glm::vec3(0.0f, 1.0f, 0.0f));
  cube3.setTexture(&tobal);


  Texture igor = Texture("res/textures/igor.jpg", true);
  Cube cube4({ glm::vec3(-4.0f, 10.5f, 0.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(1.0f, 1.0f, 1.0f) });
  cube4.setColor(glm::vec3(0.0f, 1.0f, 0.0f));

  cube4.setTexture(&igor);
  cube4.setTrail(&greenTrail);

  Texture david = Texture("res/textures/david.jpg", true);
  Cube cube5({ glm::vec3(5.0f, 0.5f, 0.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(1.0f, 1.0f, 1.0f) });
  cube5.setColor(glm::vec3(0.0f, 1.0f, 0.0f));
  cube5.setTexture(&david);
  cube5.setTrail(&blueTrail);
  cube5.mass = 5e5;
  // vector(0, sqrt(G*s.mass/mag(distance_vector(e, s))), 0)
  float distanceObjects = glm::distance(cube5.transform_.position,
    cube1.transform_.position);
  cube5.setVelocity(glm::vec3(0, (Physics::G() * cube1.mass) / (distanceObjects), 0));
  // Texture fdg = Texture("res/textures/4dg.jpg", true);
  // Plane plane({ glm::vec3(0.0f, 0.0f, 0.0f),
  //   glm::vec3(0.0f, 0.0f, 0.0f),
  //   glm::vec3(20.0f, 1.0f, 20.0f) });
  // plane.setColor(glm::vec3(1.0f, 0.5f, 0.5f));
  // plane.setTexture(&fdg);
  // plane.setFixed(true);

  Scene* scene = Scene::GetScene();
  scene->addObject(cube1);
  // scene->addObject(cube2);
  // scene->addObject(cube3);
  scene->addObject(cube4);
  // scene->addObject(cube5);
  // scene->addObject(plane);


  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // float vertices[(3 * 2) + (2 * n)];
    // int indices[n * 3];
    // generateCircleVertices(n, vertices);
    // generateCircleIndices(n, indices);
    double currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    scene->update(deltaTime);

    processInput(window);
    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}