#shader vertex
#version 330 core
layout (location = 0) in vec4 position;

void main()
{
  gl_Position = position;
}

#shader fragment
#version 330 core

out vec4 glColor;
uniform float redColor;

void main()
{
  glColor = vec4(redColor, 0, 1, 1);
}
