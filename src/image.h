#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

struct ImageData {
  int width;
  int height;
  unsigned char* data;
};

ImageData loadImage(char const* filepath, bool flip = false) {
  stbi_set_flip_vertically_on_load(flip);
  int width, height, nrChannels;
  unsigned char* data = stbi_load(filepath, &width, &height, &nrChannels, 0);
  return { width, height, data };
}
