#include <glad/glad.h>
#include <iostream>
#include <Texture.h>
#include <image.h>

Texture::Texture(char const* filepath, bool flip, bool hasAlpha) {
  ImageData imageData = loadImage(filepath, flip);
  glGenTextures(1, &id);
  glBindTexture(GL_TEXTURE_2D, id);
  // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  if (imageData.data)
  {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageData.width, imageData.height, 0, hasAlpha ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, imageData.data);
    glGenerateMipmap(GL_TEXTURE_2D);
  }
  else
  {
    std::cout << "Failed to load texture" << std::endl;
  }

  stbi_image_free(imageData.data);
}

void Texture::bind() {
  glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::unBind() {
  glBindTexture(GL_TEXTURE_2D, 0);
}