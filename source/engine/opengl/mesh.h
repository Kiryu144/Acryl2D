/* Created by David Klostermann on 30.09.2018. */
#ifndef ACRYL2D_MESH_H
#define ACRYL2D_MESH_H

#include <vector>
#include <glm/common.hpp>
#include <GLEW/glew.h>

class Mesh {
private:
    GLuint id;
public:
    Mesh(std::vector<glm::vec3> _vertices);
    ~Mesh();

    void bind();
};


#endif
