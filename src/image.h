#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

unsigned char* loadImage(char const* filepath) {
  int width, height, nrChannels;
  unsigned char* data = stbi_load(filepath, &width, &height, &nrChannels, 0);
  return data;
}
