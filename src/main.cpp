#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Shader.h>
#include <VertexBuffer.h>
#include <IndexBuffer.h>
#include <Texture.h>

#include <math.h>

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
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

  glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
  glfwSetKeyCallback(window, keyCallback);

  float vertices[] = {
    -0.5f, -0.5f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f,
    -0.5f, 0.5f,    0.0f, 1.0f, 0.0f,   0.0f, 1.0f,
    0.5f, -0.5f,    0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
    0.5f, 0.5f,     0.0f, 0.0f, 1.0f,   1.0f, 1.0f
  };

  int indices[] = {
    0, 2, 3,
    0, 3, 1
  };

  unsigned int vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  glBindVertexArray(vao);

  VertexBuffer vb(vertices, sizeof(vertices));
  vb.bind();

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 7, 0);

  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)(sizeof(float) * 2));

  glEnableVertexAttribArray(2);
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)(sizeof(float) * 5));

  IndexBuffer ib(indices, sizeof(indices));
  ib.bind();

  ShaderProgram shaderProgram = ShaderProgram("res/shaders/basic.shader");
  shaderProgram.use();

  glUniform1i(glGetUniformLocation(shaderProgram.id, "tex1"), 0);
  glUniform1i(glGetUniformLocation(shaderProgram.id, "tex2"), 1);

  Texture tex1 = Texture("res/textures/wall.jpg", true);
  Texture tex2 = Texture("res/textures/awesomeface.png", true, true);

  glActiveTexture(GL_TEXTURE0);
  tex1.bind();
  glActiveTexture(GL_TEXTURE1);
  tex2.bind();

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    float gradient = (sin(glfwGetTime()) / 2.0f) + 0.5f;
    shaderProgram.setFloat("gradient", gradient);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  shaderProgram.destroy();

  glfwTerminate();
  return 0;
}