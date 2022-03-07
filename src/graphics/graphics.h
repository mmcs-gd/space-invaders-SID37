#pragma once

#include "graphics/screen.h"
#include "shader_program.h"


struct GridColor {
    GLubyte r;
    GLubyte g;
    GLubyte b;
};


struct GlslVec4 {
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat w;
};


struct GridPoint {
    GridColor light;
    GLubyte material;
};


struct GridMaterial {
    GlslVec4 color;
};


class Graphics {
    Screen& screen;


    ShaderProgram background_shader;

    GLuint background_buffer_object;
    GLint background_vertex_attrib;


    ShaderProgram scene_shader;

    GLuint scene_buffer_object;
    GLuint scene_grid_texture_object;
    GLuint scene_materials_block_buffer;

    GLint scene_vertex_attrib;
    GLint scene_screen_size_uniform;
    GLint scene_grid_size_uniform;
    GLint scene_grid_texture_uniform;
    GLint scene_materials_uniform_block;


    int grid_x_size;
    int grid_y_size;
    int grid_z_size;

    Graphics(const Graphics&);
    Graphics(Graphics&&);
    Graphics& operator=(const Graphics&);
    Graphics& operator=(Graphics&&);

public:
    Graphics(Screen& screen, int x_size, int y_size, int z_size);

    void UpdateGrid(const GridPoint* grid);
    void UpdateMaterials(const GridMaterial* matrials);

    int XSize() const;
    int YSize() const;
    int ZSize() const;

    void Draw();

    ~Graphics();
};
