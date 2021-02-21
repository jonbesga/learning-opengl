#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <main.h>
#include <shader.h>
#include <math.h>

const int WIDTH = 800;
const int HEIGHT = 600;
int currentMode = GL_FILL;
float moveX = 0.0f;
float moveY = 0.0f;

int main() {
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  glViewport(0, 0, WIDTH, HEIGHT);

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  glfwSetKeyCallback(window, key_callback);

  float vertices[] = {
    -1.0f,  0.0f, 0.0f,
    -0.5f, 0.5f, 0.0f,
    0.0f,  0.0f, 0.0f,
    1.0f,  0.0f, 0.0f,
    0.5f, 0.5f, 0.0f,
    0.0f, -1.0f, 0.0f
  };

  unsigned int indices[] = {
    0, 1, 2,
    2, 3, 4,
    0, 5, 3
  };

  Shader ourShader("shaders/shader.vs", "shaders/shader.fs");
  Shader ourYellowShader("shaders/shader.vs", "shaders/shader_yellow.fs");

  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  GLuint vbo;
  glGenBuffers(1, &vbo);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  GLuint EBO;
  glGenBuffers(1, &EBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  while (!glfwWindowShouldClose(window)) {
    processInput(window);

    glClear(GL_COLOR_BUFFER_BIT);

    // enable/disable wireframe mode
    glPolygonMode(GL_FRONT_AND_BACK, currentMode);

    glBindVertexArray(vao);
    float timeValue = glfwGetTime();
    float colors[] = { (sin(timeValue) / 2.0f) + 0.5f, 0.0f, 0.0f, 1.0f };
    float translation[] = { moveX, moveY, 0, 0.0f };
    ourShader.setVec4("ourColor", colors);
    ourShader.setVec4("translation", translation);
    ourShader.use();
    glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteVertexArrays(1, &vao);
  glDeleteBuffers(1, &vbo);
  glDeleteBuffers(1, &EBO);
  ourShader.deleteShader();
  ourYellowShader.deleteShader();


  glfwTerminate();
  return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_F && action == GLFW_PRESS) {
    currentMode = (currentMode == GL_LINE) ? GL_FILL : GL_LINE;
  }
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
  if (key == GLFW_KEY_D) {
    moveX += 0.1f;
  }
  if (key == GLFW_KEY_A) {
    moveX -= 0.1f;
  }
  if (key == GLFW_KEY_W) {
    moveY += 0.1f;
  }
  if (key == GLFW_KEY_S) {
    moveY -= 0.1f;
  }
}
