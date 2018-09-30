/* Created by David Klostermann on 22.09.2018. */
#include <iostream>
#include <engine/opengl/texture.h>
#include "game.h"

void readFile(std::string path, std::string& data){
    std::ifstream f(path.c_str(), std::ios::binary);
    data.assign((std::istreambuf_iterator<char>(f)),
                (std::istreambuf_iterator<char>()));
}

void Game::start() {
    std::string vertex;
    std::string fragment;
    std::string image1;
    std::string image2;

    readFile("compile_test.vert", vertex);
    readFile("compile_test.frag", fragment);
    readFile("Image1.png", image1);
    readFile("Image2.png", image2);

    Shader* parser = new Shader(vertex.c_str(), fragment.c_str(), nullptr);
    Texture* texture = new Texture(reinterpret_cast<const unsigned char*>(image1.c_str()), image1.size());
}

void Game::update(double delta) {

}

