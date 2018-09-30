/* Created by David Klostermann on 27.09.2018. */
#ifndef ACRYL2D_TEXTURE_H
#define ACRYL2D_TEXTURE_H

#include <GLEW/glew.h>
#include <PICOPNG/Picopng.h>
#include <GLM/common.hpp>

class Texture {
private:
    GLuint textureID;
public:
    Texture(const unsigned char* file, size_t size);
    ~Texture();

    void bind();
};


#endif
