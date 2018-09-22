#include <iostream>
#include <SDL2/SDL.h>

#include "engine/acryl2d.h"

void loop(double delta){

}

int main(int argv, char** args) {
    Acryl2D::initialize(800, 400, "Acryl");
    Acryl2D::mainloop(loop);

    return 0;
}