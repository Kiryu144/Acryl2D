#ifndef ACRYL2D_ACRYL2D_H
#define ACRYL2D_ACRYL2D_H

#include <SDL2/SDL.h>
#include <GLEW/glew.h>
#include "acrylgame.h"

class Acryl2D {
private:
    static SDL_Window* sdlWindow;
    static void (*loop)(double);
public:
    static void initialize(unsigned int width, unsigned int height, const char* title);
    static void initialize(unsigned int width, unsigned int height);
    static void initialize(const char* title);
    static void initialize();

    static void mainloop(AcrylGame& game);

    static void quit();
};

#endif
