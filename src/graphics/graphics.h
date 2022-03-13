#pragma once

#include "graphics/screen.h"
#include "shader_program.h"

#include <algorithm>


struct GridColor {
    GLubyte r;
    GLubyte g;
    GLubyte b;

    GridColor& operator+=(const GridColor& c) {
        r += c.r; g += c.g; b += c.b;
        return *this;
    }

    GridColor operator*(float v) {
        return {
            GLubyte(std::min(r * v, 255.0f)),
            GLubyte(std::min(g * v, 255.0f)),
            GLubyte(std::min(b * v, 255.0f))
        };
    }
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
    struct Color { GLfloat r, g, b; };

    GlslVec4 color;
    GlslVec4 options;

    GridMaterial(Color color = { 0, 0, 0 }, GLfloat reflection = 0, GLfloat density = 0):
        color { color.r, color.g, color.b, 1 },
        options { reflection, density, 0, 0 } {
    }

    GLfloat Reflection() const {
        return options.x;
    }

    GLfloat Density() const {
        return options.y;
    }
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

    void ScreenToGridLocation(int screen_x, int screen_y, int* grid_x, int* grid_y);

    int XSize() const;
    int YSize() const;
    int ZSize() const;

    void Draw();

    ~Graphics();
};
