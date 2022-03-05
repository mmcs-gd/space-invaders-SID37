#pragma once

#include "graphics/screen.h"
#include "shader_program.h"


class Graphics {
    Screen& screen;

    ShaderProgram background_shader;
    GLuint background_buffer_object;
    GLint background_vertex_attrib;


    Graphics(const Graphics&);
    Graphics(Graphics&&);
    Graphics& operator=(const Graphics&);
    Graphics& operator=(Graphics&&);

public:
    Graphics(Screen& screen);

    void Draw();
};
