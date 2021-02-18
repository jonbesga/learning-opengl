#ifndef SHADER_H
#define SHADER_H

#include <iostream>

class Shader {
public:
  unsigned int ID;

  Shader(const char* vertexPath, const char* fragmentPath);
  int createProgram(unsigned int shaders[], int sizeOfShaders) const;
  int createAndCompileShader(int shaderType, const char* shaderSource) const;
  void use() const;
  void setBool(const std::string& name, bool value) const;
  void setInt(const std::string& name, int value) const;
  void setFloat(const std::string& name, float value) const;
  void deleteShader() const;
};

#endif
