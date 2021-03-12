#shader vertex
#version 330 core
layout (location = 0) in vec4 position;
layout (location = 1) in vec2 TexCoord;

uniform mat4 transform;
uniform vec3 in_color = vec3(1.0f);

out vec4 out_color;
out vec2 out_TexCoord;

void main()
{
  gl_Position = transform * position;
  out_color = vec4(in_color, 1.0f);
  out_TexCoord = TexCoord;
}

#shader fragment
#version 330 core

in vec4 out_color;
in vec2 out_TexCoord;

uniform int hasTexture = 0;
uniform sampler2D texture1;

out vec4 FragColor;

void main(){
  if(hasTexture == 1){
    FragColor = texture(texture1, out_TexCoord);// * out_color; 
  } else {
    FragColor = out_color;
  }
}
