/* Created by David Klostermann on 21.09.2018. */
#include "acryl2d.h"

SDL_Window* Acryl2D::sdlWindow = nullptr;

void initialize(unsigned int width, unsigned int height, const char* title);
void initialize(unsigned int width, unsigned int height);
void initialize(const char* title);
void initialize();

void Acryl2D::initialize(unsigned int width, unsigned int height, const char *title) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

    Uint32 windowFlags = SDL_WINDOW_OPENGL;
    sdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, windowFlags);

    SDL_GL_CreateContext(sdlWindow);

    glewExperimental = GL_TRUE;
    glewInit();

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

void Acryl2D::mainloop(AcrylGame& game) {
    game.start();
    double lastTime = SDL_GetTicks();
    while(!SDL_QuitRequested()){
        double deltaTime = SDL_GetTicks() - lastTime;
        game.update(deltaTime);
    }
}

void Acryl2D::quit() {
    SDL_DestroyWindow(sdlWindow);
    SDL_Quit();
}


