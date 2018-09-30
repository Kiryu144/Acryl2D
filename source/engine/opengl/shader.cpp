/* Created by David Klostermann on 22.09.2018. */
#include <stdexcept>
#include "shader.h"

Shader::Shader(const char *vertex, const char *fragment, const char *geometry) {
    GLuint vertexID, fragmentID, geometryID;

    if(vertex != nullptr){
        vertexID = compile(vertex, GL_VERTEX_SHADER);
    }

    if(fragment != nullptr){
        fragmentID = compile(fragment, GL_FRAGMENT_SHADER);
    }

    if(geometry != nullptr){
        geometryID = compile(geometry, GL_GEOMETRY_SHADER);
    }

    programID = link(vertexID, fragmentID, geometryID);
}

GLuint Shader::compile(const char *shader, GLuint type) {
    GLuint shaderID = glCreateShader(type);
    glShaderSource(shaderID, 1, &shader, nullptr);
    glCompileShader(shaderID);

    int success = GL_FALSE;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if(success == GL_FALSE){
        GLint logLenght;
        char* log;

        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLenght);
        glGetShaderInfoLog(shaderID, logLenght, &logLenght, log);

        throw std::logic_error("Cannot compile shader! Error: " + std::string(log));
    }

    return shaderID;
}

GLuint Shader::link(GLuint vertex, GLuint fragment, GLuint geometry) {
    GLuint programID = glCreateProgram();

    if(vertex != 0){
        glAttachShader(programID, vertex);
    }

    if(fragment != 0){
        glAttachShader(programID, fragment);
    }

    if(geometry != 0){
        glAttachShader(programID, geometry);
    }

    glLinkProgram(programID);

    glDetachShader(programID, vertex);
    glDetachShader(programID, fragment);
    glDetachShader(programID, geometry);

    return programID;
}

void Shader::bind() {
    glUseProgram(programID);
}

int Shader::getUniformLocation(std::string uniformName) {
    return glGetUniformLocation(this->programID, uniformName.c_str());
}

void Shader::setUniform(std::string uniform, float value) {
    glUniform1f(getUniformLocation(uniform), value);
}

void Shader::setUniform(std::string uniform, glm::vec2 vec) {
    glUniform2f(getUniformLocation(uniform), vec.x, vec.y);
}

void Shader::setUniform(std::string uniform, glm::vec3 vec) {
    glUniform3f(getUniformLocation(uniform), vec.x, vec.y, vec.z);
}

void Shader::setUniform(std::string uniform, glm::vec4 vec) {
    glUniform4f(getUniformLocation(uniform), vec.r, vec.g, vec.b, vec.a);
}

void Shader::setUniform(std::string uniform, glm::mat4 mat) {
    glUniformMatrix4fv(getUniformLocation(uniform), 1, GL_FALSE, &mat[0][0]);
}

void Shader::setUniform(std::string uniform, int value) {
    glUniform1i(getUniformLocation(uniform), 0);
}

GLuint Shader::getProgramId() {
    return programID;
}

