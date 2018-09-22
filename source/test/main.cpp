#include <iostream>
#include <SDL2/SDL.h>

#include "engine/acryl2d.h"
#include "game.h"

int main(int argv, char** args) {
    Acryl2D::initialize(800, 400, "Acryl");

    Game game;
    Acryl2D::mainloop(game);

    return 0;
}