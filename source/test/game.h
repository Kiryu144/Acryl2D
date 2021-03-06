/* Created by David Klostermann on 22.09.2018. */
#ifndef ACRYL2D_GAME_H
#define ACRYL2D_GAME_H

#include <engine/acryl2d.h>
#include <engine/opengl/shader.h>
#include <engine/opengl/mesh.h>
#include <engine/opengl/texture.h>
#include <fstream>
#include <vector>
#include <sstream>


class Game : public AcrylGame {
private:

public:
    void start();
    void update(double delta);
};


#endif
