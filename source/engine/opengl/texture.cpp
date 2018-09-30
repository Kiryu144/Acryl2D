/* Created by David Klostermann on 27.09.2018. */
#include <stdexcept>
#include "texture.h"

Texture::Texture(const unsigned char *file, size_t size) {
    if(size == 0 || file == nullptr){
        throw std::invalid_argument("Image data is empty!");
    }

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    float color[] = { 0.0f, 0.0f, 0.0f, 0.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
    glGenerateMipmap(GL_TEXTURE_2D);

    std::vector<unsigned char> decoded;
    unsigned long width, height;
    int error = decodePNG(decoded, width, height, file, size);

    if(error != 0){
        throw(std::logic_error("Invalid file format! Error code: " + std::to_string(error)));
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (int)width, (int)height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &decoded.at(0));
}

Texture::~Texture() {
    glDeleteTextures(1, &textureID);
}

void Texture::bind() {
    glBindTexture(GL_TEXTURE_2D, textureID);
}
