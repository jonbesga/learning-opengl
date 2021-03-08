
#include <math.h>

void generateCircleVertices(int n, float* vertices) {
  float radius = 1.0f;
  float angle = 2 * M_PI / n;

  vertices[0] = 0.0f;
  vertices[1] = 0.0f;
  // float vertices[(3 * 2) + (2 * n)] = {
  //   0.0f, 0.0f,
    // (radius * cos(angle * 0)), (radius * sin(angle * 0)),
    // (radius * cos(angle * 1)), (radius * sin(angle * 1)),
    // (radius * cos(angle * 2)), (radius * sin(angle * 2)),
    // (radius * cos(angle * 3)), (radius * sin(angle * 3)),
    // (radius * cos(angle * 4)), (radius * sin(angle * 4)),
    // (radius * cos(angle * 5)), (radius * sin(angle * 5)),
  // };
  int index = 2;
  for (int i = 0; i <= n; i++) {
    vertices[index++] = radius * cos(angle * i);
    vertices[index++] = radius * sin(angle * i);
  }
}

void generateCircleIndices(int n, int* indices) {
  int index = 0;

  for (int i = 1; i <= n; i++) {
    indices[index++] = 0;
    indices[index++] = i;
    indices[index++] = i + 1;
  }

}