#ifndef ACRYL2D_ACRYL2D_H
#define ACRYL2D_ACRYL2D_H

#include <SDL2/SDL.h>

class Acryl2D {
private:

public:

    static void initialize(unsigned int width, unsigned int height, const char* title);
    static void initialize(unsigned int width, unsigned int height);
    static void initialize(const char* title);
    static void initialize();
};

#endif
