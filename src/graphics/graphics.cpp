#include "GLES3/gl3.h"

#include "graphics/graphics.h"
#include "graphics/shaders.h"
#include "graphics/gl_helper.h"
#include "tools/logger.h"


namespace {
    struct Vertex {
        GLfloat x;
        GLfloat y;
    };
}


Graphics::Graphics(Screen& screen):
        screen(screen),
        background_shader(Shaders::vertex_shader, Shaders::background_fragment_shader) {

    background_vertex_attrib = background_shader.GetAttribLocation("coord");

    Logger::Log("Graphics", "creating background buffer...");
    glGenBuffers(1, &background_buffer_object);

    Vertex background_triangle[] = {
        {-1, -1}, {-1,  1}, { 1,  1},
        { 1,  1}, { 1, -1}, {-1, -1},
    };

    glBindBuffer(GL_ARRAY_BUFFER, background_buffer_object);
    glBufferData(GL_ARRAY_BUFFER, sizeof(background_triangle), background_triangle, GL_STATIC_DRAW);


    glFlush();
    checkOpenGLerror();
}


void Graphics::Draw() {
    glClear(GL_COLOR_BUFFER_BIT);


    background_shader.Use();

    glEnableVertexAttribArray(background_vertex_attrib);

    glBindBuffer(GL_ARRAY_BUFFER, background_buffer_object);
    glVertexAttribPointer(background_vertex_attrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(background_vertex_attrib);


    glUseProgram(0);
    checkOpenGLerror();
}
