/* Created by David Klostermann on 22.09.2018. */
#include <stdexcept>
#include "ShaderParser.h"

ShaderParser::ShaderParser(const char *vertex, const char *fragment, const char *geometry) {
    GLuint vertexID, fragmentID, geometryID;

    if(vertex != nullptr){
        vertexID = compile(vertex, GL_VERTEX_SHADER);
    }

    if(fragment != nullptr){
        fragmentID = compile(vertex, GL_VERTEX_SHADER);
    }

    if(geometry != nullptr){
        geometryID = compile(vertex, GL_VERTEX_SHADER);
    }

    programID = link(vertexID, fragmentID, geometryID);
}

GLuint ShaderParser::compile(const char *shader, GLuint type) {
    GLuint shaderID = glCreateShader(type);
    glShaderSource(type, 1, &shader, nullptr);
    glCompileShader(shaderID);

    int success = GL_FALSE;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if(success == GL_FALSE){
        throw std::logic_error("Invalid Syntax!");
    }

    return shaderID;
}

GLuint ShaderParser::link(GLuint vertex, GLuint fragment, GLuint geometry) {
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

void ShaderParser::bind() {
    glUseProgram(programID);
}

int ShaderParser::getUniformLocation(std::string uniformName) {
    return glGetUniformLocation(this->programID, uniformName.c_str());
}

void ShaderParser::setUniform(std::string uniform, float value) {
    glUniform1f(getUniformLocation(uniform), value);
}

void ShaderParser::setUniform(std::string uniform, glm::vec2 vec) {
    glUniform2f(getUniformLocation(uniform), vec.x, vec.y);
}

void ShaderParser::setUniform(std::string uniform, glm::vec3 vec) {
    glUniform3f(getUniformLocation(uniform), vec.x, vec.y, vec.z);
}

void ShaderParser::setUniform(std::string uniform, glm::vec4 vec) {
    glUniform4f(getUniformLocation(uniform), vec.r, vec.g, vec.b, vec.a);
}

void ShaderParser::setUniform(std::string uniform, glm::mat4 mat) {
    glUniformMatrix4fv(getUniformLocation(uniform), 1, GL_FALSE, &mat[0][0]);
}

void ShaderParser::setUniform(std::string uniform, int value) {
    glUniform1i(getUniformLocation(uniform), 0);
}

GLuint ShaderParser::getProgramId() {
    return programID;
}

