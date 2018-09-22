#ifndef ACRYL2D_ACRYL2D_H
#define ACRYL2D_ACRYL2D_H

#include <SDL2/SDL.h>

class Acryl2D {
private:
    static SDL_Window* sdlWindow;
    static void (*loop)(double);
public:
    static void initialize(unsigned int width, unsigned int height, const char* title);
    static void initialize(unsigned int width, unsigned int height);
    static void initialize(const char* title);
    static void initialize();

    static void mainloop(void (*func)(double));

    static void quit();
};

#endif
