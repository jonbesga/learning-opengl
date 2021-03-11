#include <glad/glad.h>
#include <iostream>
#include <Mesh.h>

#include <vector>

Mesh::Mesh(float vertices[], int vertices_size, int indices[], int indices_size) :
  vertices(vertices),
  indices(indices),
  indices_size(indices_size),
  vbo(vertices, vertices_size),
  ibo(indices, indices_size) {

  std::cout << "Mesh created: " << *vertices << "::" << vertices << std::endl;
  std::vector<int> layouts;
  int count = 8;

  layouts.push_back(3);
  layouts.push_back(3);
  layouts.push_back(2);

  int offset = 0;
  for (int i = 0; i < layouts.size(); i++) {
    glEnableVertexAttribArray(i);
    glVertexAttribPointer(i, layouts[i], GL_FLOAT, GL_FALSE, sizeof(float) * count, (void*)(sizeof(float) * offset));
    offset += layouts[i];
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