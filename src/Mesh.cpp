#include <glad/glad.h>
#include <iostream>
#include <Mesh.h>

#include <vector>

struct Layout {
  int size;
  int stride;
  int offset;
};

void Mesh::setup(float* vertices, int vertices_size, int* indices, int indices_size, int offsetTexture) {

  this->indices_size = indices_size;
  this->vertices_size = vertices_size;

  this->vbo.bufferData(vertices, vertices_size);
  this->ibo.bufferData(indices, indices_size);
  std::cout << "Mesh created: " << *vertices << "::" << vertices << std::endl;

  std::vector<Layout> layouts;

  layouts.push_back({ 3, 3, 0 });
  layouts.push_back({ 2, 2, offsetTexture });


  for (int i = 0; i < layouts.size(); i++) {
    int offset = layouts[i].offset;
    glEnableVertexAttribArray(i);

    glVertexAttribPointer(i, layouts[i].size, GL_FLOAT, GL_FALSE, sizeof(float) * layouts[i].stride, (void*)(sizeof(float) * offset));
  }

  this->ibo.unBind();
  this->vbo.unBind();
  this->vao.unBind();
}

void Mesh::draw()
{
  this->vao.bind();
  this->ibo.bind();

  glDrawElements(GL_TRIANGLES, this->indices_size / sizeof(int), GL_UNSIGNED_INT, nullptr);

  this->vao.unBind();
  this->ibo.unBind();
}