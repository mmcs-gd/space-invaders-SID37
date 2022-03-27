#pragma once

#include "volumatrix/graphics/screen.h"
#include "volumatrix/grid/grid.h"
#include "shader_program.h"

#include <algorithm>



namespace Volumatrix {

    class Graphics {
        Screen& screen;
        Grid& grid;


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


        void UpdateGrid();
        void UpdateMaterials();

    public:
        Graphics(Screen& screen, Grid& grid);

        void ScreenToGridLocation(int screen_x, int screen_y, int* grid_x, int* grid_y);

        int XSize() const;
        int YSize() const;
        int ZSize() const;

        void Draw();

        ~Graphics();
    };
}
