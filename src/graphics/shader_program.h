#pragma once
#include <GLES3/gl3.h>


class ShaderProgram {
    GLuint program;

    ShaderProgram(const ShaderProgram&) = delete;
    ShaderProgram(ShaderProgram&&) = delete;
    ShaderProgram& operator=(const ShaderProgram&) = delete;
    ShaderProgram& operator=(ShaderProgram&&) = delete;

    void ShaderLog(GLuint shader) const;

public:
    ShaderProgram(const char* vertex_shader, const char* fragment_shader);

    GLint GetAttribLocation(const char* name) const;
    GLint GetUniform(const char* name) const;
    GLuint GetUnifBlock(const char* name) const;

    void Use();

    ~ShaderProgram();
};
