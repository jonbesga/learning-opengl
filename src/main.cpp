#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <main.h>
#include <shader.h>

const int WIDTH = 800;
const int HEIGHT = 600;
int currentMode = GL_FILL;


unsigned int VBO;
unsigned int VBO2;
unsigned int chosenVBO;
unsigned int VAO;
unsigned int VAO2;
unsigned int chosenVAO;

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
  };

  float vertices2[] = {
    0.0f,  0.0f, 0.0f,
    1.0f,  0.0f, 0.0f,
    0.5f, 0.5f, 0.0f
  };

  Shader ourShader("shaders/shader.vs", "shaders/shader.fs");
  Shader ourYellowShader("shaders/shader.vs", "shaders/shader_yellow.fs");

  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  // unsigned int VBO;
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

  glEnableVertexAttribArray(0);

  glGenBuffers(1, &VBO2);
  glBindBuffer(GL_ARRAY_BUFFER, VBO2);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

  glEnableVertexAttribArray(1);


  // glGenVertexArrays(1, &VAO2);
  // glBindVertexArray(VAO2);

  // unsigned int VBO2;


  // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  // glEnableVertexAttribArray(0);
  // unsigned int EBO;
  // glGenBuffers(1, &EBO);
  // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  while (!glfwWindowShouldClose(window))
  {
    processInput(window);

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);


    glPolygonMode(GL_FRONT_AND_BACK, currentMode);
    glBindVertexArray(VAO);
    ourShader.use();

    glDrawArrays(GL_TRIANGLES, 0, 3);
    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    // glBindVertexArray(VAO2);
    // ourYellowShader.use();
    // glDrawArrays(GL_TRIANGLES, 0, 3);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  // glDeleteBuffers(1, &EBO);
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
  if (key == GLFW_KEY_S && action == GLFW_PRESS) {
    if (currentMode == GL_LINE) {
      currentMode = GL_FILL;
    }
    else {
      currentMode = GL_LINE;
    }
  }
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
  if (key == GLFW_KEY_R && action == GLFW_PRESS) {
    chosenVAO = VAO;
  }
  if (key == GLFW_KEY_D && action == GLFW_PRESS) {
    chosenVAO = VAO2;
  }


}