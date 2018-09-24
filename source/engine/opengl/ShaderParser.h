/* Created by David Klostermann on 22.09.2018. */
#ifndef ACRYL2D_SHADERPARSER_H
#define ACRYL2D_SHADERPARSER_H

#include <GLEW/glew.h>
#include <GLM/common.hpp>
#include <GLM/matrix.hpp>
#include <string>

class ShaderParser {
private:
    GLuint compile(const char* shader, GLuint type);
    GLuint link(GLuint vertex, GLuint fragment, GLuint geometry);

    GLuint programID;
public:
    ShaderParser(const char* vertex, const char* fragment, const char* geometry);

    void bind();

    GLuint getProgramId();
    int getUniformLocation(std::string uniformName);
    void setUniform(std::string uniform, float value);
    void setUniform(std::string uniform, glm::vec2 vec);
    void setUniform(std::string uniform, glm::vec3 vec);
    void setUniform(std::string uniform, glm::vec4 vec);
    void setUniform(std::string uniform, glm::mat4 mat);
    void setUniform(std::string uniform, int value);
};


#endif
