#include <iostream>
#include <SDL2/SDL.h>

#include "engine/os/acryl2d.h"

int main(int argv, char** args) {
    Acryl2D::initialize(800, 400, "Acryl");

    return 0;
}