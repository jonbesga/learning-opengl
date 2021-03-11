#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Camera.h>
#include <Cube.h>
#include <Plane.h>
// #include <Shader.h>
// #include <VertexBuffer.h>
// #include <IndexBuffer.h>
// #include <VertexArray.h>
// #include <Texture.h>
// #include <Circle.h>
// #include <vector>
// #include <math.h>
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>
// #include <glm/gtx/string_cast.hpp>

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
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
    camera->viewVector -= camera->cameraSpeed * glm::vec3(0.0f, 0.0f, -1.0f);
  }
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
    camera->viewVector += camera->cameraSpeed * glm::vec3(1.0f, 0.0f, 0.0f);
  }
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
    camera->viewVector += camera->cameraSpeed * glm::vec3(0.0f, 0.0f, -1.0f);
  }
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
    camera->viewVector += camera->cameraSpeed * glm::vec3(-1.0f, 0.0f, 0.0f);
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

  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGL()) {
    return -1;
  }

  glViewport(0, 0, 640, 480);
  glEnable(GL_DEPTH_TEST);
  glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
  glfwSetKeyCallback(window, keyCallback);

  MeshPlane meshPlane;
  Cube cube2(glm::vec3(0.0f, 0.5f, 0.0f));
  Object plane({ glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(20.0f, 1.0f, 20.0f) }, meshPlane);

  // glUniform1i(glGetUniformLocation(shaderProgram.id, "tex1"), 0);
    // glUniform1i(glGetUniformLocation(shaderProgram.id, "tex2"), 1);
    // glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
    // glm::mat4 trans = glm::mat4(1.0f);
    // trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
    // vec = trans * vec;
    // std::cout << vec.x << vec.y << vec.z << std::endl;
  // float gradient = 1.0f;
  // Texture tex1 = Texture("res/textures/lois.jpg", true);
  // Texture tex2 = Texture("res/textures/awesomeface.png", true, true);

  // glActiveTexture(GL_TEXTURE0);
  // tex1.bind();
  // glActiveTexture(GL_TEXTURE1);
  // tex2.bind();

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    // float vertices[(3 * 2) + (2 * n)];
    // int indices[n * 3];
    // generateCircleVertices(n, vertices);
    // generateCircleIndices(n, indices);

    // VertexArray vao;
    // vao.bind();
    // VertexBuffer vb(vertices, sizeof(vertices));
    // vb.bind();
    // IndexBuffer ibo(indices, sizeof(indices));
    // ibo.bind();

    // std::vector<int> layouts;
    // int count = 8;

    // layouts.push_back(3);
    // layouts.push_back(3);
    // layouts.push_back(2);

    // int offset = 0;
    // for (int i = 0; i < layouts.size(); i++) {
    //   glEnableVertexAttribArray(i);
    //   glVertexAttribPointer(i, layouts[i], GL_FLOAT, GL_FALSE, sizeof(float) * count, (void*)(sizeof(float) * offset));
    //   offset += layouts[i];
    // }
    // if S
    // z =- 1 * cameraSpeed
    // glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(2.0f, 1.0f, 0.0f));

    // glm::mat4 proj = glm::perspective(glm::radians(45.0f), 640.0f / 480.0f, 5.0f, 100.0f);

    // glm::mat4 trans = proj * view * model;

    // glUniformMatrix4fv(glGetUniformLocation(shaderProgram.id, "transform"), 1, GL_FALSE, glm::value_ptr(trans));


    cube2.draw();
    plane.draw();

    processInput(window);
    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}