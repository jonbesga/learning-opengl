#include <glad/glad.h>

#include <fstream>
#include <sstream>

#include <shader.h>

Shader::Shader(const char* vertexPath, const char* fragmentPath) {
  std::string vertexCode;
  std::string fragmentCode;
  std::ifstream vShaderFile;
  std::ifstream fShaderFile;

  vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try
  {
    // open files
    vShaderFile.open(vertexPath);
    fShaderFile.open(fragmentPath);
    std::stringstream vShaderStream, fShaderStream;
    // read file's buffer contents into streams
    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();
    // close file handlers
    vShaderFile.close();
    fShaderFile.close();
    // convert stream into string
    vertexCode = vShaderStream.str();
    fragmentCode = fShaderStream.str();
  }
  catch (std::ifstream::failure e)
  {
    std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
  }

  const char* vShaderCode = vertexCode.c_str();
  const char* fShaderCode = fragmentCode.c_str();

  unsigned int vertexShader = createAndCompileShader(GL_VERTEX_SHADER, vShaderCode);
  unsigned int fragmentShader = createAndCompileShader(GL_FRAGMENT_SHADER, fShaderCode);

  unsigned int shaders[] = { vertexShader, fragmentShader };

  ID = createProgram(shaders, sizeof(shaders) / sizeof(shaders[0]));

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

int Shader::createProgram(unsigned int shaders[], int sizeOfShaders) const {
  // int createProgram(unsigned int shaders[], unsigned int vertexShader, unsigned int fragmentShader) {
  int success;
  char infoLog[512];
  unsigned int shaderProgram;

  shaderProgram = glCreateProgram();
  for (int i = 0; i < sizeOfShaders; i++) {
    glAttachShader(shaderProgram, shaders[i]);
  }

  glLinkProgram(shaderProgram);

  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    return -1;
  }
  return shaderProgram;
}

int Shader::createAndCompileShader(int shaderType, const char* shaderSource) const {
  int success;
  char infoLog[512];
  int shader;

  shader = glCreateShader(shaderType);
  glShaderSource(shader, 1, &shaderSource, NULL);
  glCompileShader(shader);
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(shader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    return -1;
  }
  return shader;

}

void Shader::use() const {
  glUseProgram(ID);
}

void Shader::setBool(const std::string& name, bool value) const
{
  glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, int value) const
{
  glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const
{
  glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::deleteShader() const {
  glDeleteProgram(ID);
}
