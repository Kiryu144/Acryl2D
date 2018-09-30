/* Created by David Klostermann on 30.09.2018. */
#include "mesh.h"

Mesh::Mesh(std::vector<glm::vec3> _vertices) {
    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, _vertices.size(), &_vertices.at(0), GL_STATIC_DRAW);
}

Mesh::~Mesh() {
    glDeleteBuffers(1, &id);
}

void Mesh::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, id);
}
