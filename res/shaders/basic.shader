#shader vertex
#version 330 core
layout (location = 0) in vec4 position;
layout (location = 1) in vec4 in_color;
layout (location = 2) in vec2 aTexCoord;

out vec4 o_color;
out vec2 TexCoord;

void main()
{
  gl_Position = position;
  o_color = in_color;
  TexCoord = aTexCoord;
}

#shader fragment
#version 330 core

in vec4 o_color;
in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D tex1;
uniform sampler2D tex2;
uniform float gradient;

void main()
{
  FragColor = mix(texture(tex1, TexCoord), texture(tex2, TexCoord), gradient);
}
