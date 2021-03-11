#include <glad/glad.h>
#include <Shader.h>

ShaderProgram::ShaderProgram(const std::string& filepath) {
  id = ShaderProgram::createShader(filepath);
}

void ShaderProgram::use() {
  glUseProgram(id);
}

void ShaderProgram::destroy() {
  glDeleteProgram(id);
}

int ShaderProgram::compileShader(int type, const char* src) {
  int shader = glCreateShader(type);
  glShaderSource(shader, 1, &src, nullptr);
  glCompileShader(shader);
  return shader;
}

void ShaderProgram::setVec4(const std::string& name, float value[]) {
  int location = glGetUniformLocation(id, name.c_str());
  glUniform4fv(location, 1, value);
}

void ShaderProgram::setFloat(const std::string& name, float value) {
  int location = glGetUniformLocation(id, name.c_str());
  glUniform1f(location, value);
}

int ShaderProgram::createShader(const std::string& filepath) {
  ShaderSource ss = readShaderSourceFromFile(filepath);

  int shaderProgram = glCreateProgram();
  int vShader = compileShader(GL_VERTEX_SHADER, ss.VertexSource.c_str());
  int fShader = compileShader(GL_FRAGMENT_SHADER, ss.FragmentSource.c_str());

  glAttachShader(shaderProgram, vShader);
  glAttachShader(shaderProgram, fShader);

  glLinkProgram(shaderProgram);

  glDeleteShader(vShader);
  glDeleteShader(fShader);

  return shaderProgram;
}


ShaderSource ShaderProgram::readShaderSourceFromFile(const std::string& filepath) {
  std::ifstream stream(filepath);
  std::string line;
  std::stringstream ss[2];

  enum ShaderType {
    NONE = -1,
    VERTEX = 0,
    FRAGMENT = 1,
  };

  int mode = ShaderType::NONE;
  while (getline(stream, line)) {
    if (line.find("#shader") != std::string::npos) {
      if (line.find("#shader vertex") != std::string::npos) {
        mode = ShaderType::VERTEX;
      }
      else if (line.find("#shader fragment") != std::string::npos) {
        mode = ShaderType::FRAGMENT;
      }
    }
    else {
      ss[mode] << line << "\n";
    }
  }
  return { ss[0].str(), ss[1].str() };
}