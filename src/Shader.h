#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

struct ShaderSource {
  std::string VertexSource;
  std::string FragmentSource;
};

class ShaderProgram {
public:
  int id;
  ShaderProgram(const std::string& filepath);
  void use();
  void destroy();
  void setVec4(const std::string& name, float value[]);
  void setFloat(const std::string& name, float value);
private:
  int createShader(const std::string& filepath);
  int compileShader(int type, const char* src);
  ShaderSource readShaderSourceFromFile(const std::string& filepath);
};
