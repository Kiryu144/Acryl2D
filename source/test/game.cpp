/* Created by David Klostermann on 22.09.2018. */
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
    std::vector<glm::vec3> vertices;
    vertices.push_back(glm::vec3(0, 0, 0));
    vertices.push_back(glm::vec3(1, 0, 0));
    vertices.push_back(glm::vec3(0, 1, 0));
    vertices.push_back(glm::vec3(0, 1, 0));
    vertices.push_back(glm::vec3(1, 1, 0));
    vertices.push_back(glm::vec3(1, 0, 0));

    readFile("compile_test.vert", vertex);
    readFile("compile_test.frag", fragment);
    readFile("Image1.png", image1);
    readFile("Image2.png", image2);

    Shader* parser = new Shader(vertex.c_str(), fragment.c_str(), nullptr);
    Texture* texture = new Texture(reinterpret_cast<const unsigned char*>(image1.c_str()), image1.size());
    Mesh* mesh = new Mesh(vertices);
}

void Game::update(double delta) {

}

