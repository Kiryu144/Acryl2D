/* Created by David Klostermann on 21.09.2018. */
#include "acryl2d.h"

void initialize(unsigned int width, unsigned int height, const char* title);
void initialize(unsigned int width, unsigned int height);
void initialize(const char* title);
void initialize();

void Acryl2D::initialize(unsigned int width, unsigned int height, const char *title) {
    Uint32 flags = SDL_WINDOW_OPENGL;
    SDL_CreateWindow(title, 0, 0, width, height, flags);
}

void Acryl2D::initialize(unsigned int width, unsigned int height) {
    initialize(width, height, "Acryl2D");
}

void Acryl2D::initialize(const char *title) {
    initialize(400, 400, title);
}

void Acryl2D::initialize() {
    initialize(400, 400, "Acryl2D");
}
