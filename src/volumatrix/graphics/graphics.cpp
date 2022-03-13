#include "volumatrix/graphics/graphics.h"
#include "volumatrix/graphics/shaders.h"
#include "volumatrix/graphics/gl_helper.h"
#include "volumatrix/tools/logger.h"


#include <GLES3/gl3.h>
#include <algorithm>
#include <regex>

namespace Volumatrix {

    namespace {
        struct Vertex {
            GLfloat x;
            GLfloat y;
        };
    }


    Graphics::Graphics(Screen& screen, Grid& grid):
            screen(screen),
            grid(grid),
            background_shader(Shaders::vertex_shader, Shaders::background_fragment_shader),
            scene_shader(Shaders::vertex_shader, std::regex_replace(
                Shaders::scene_fragment_shader,
                std::regex("<GRID_X_SIZE>"),
                std::to_string(grid.XSize())
            ).c_str()),
            grid_x_size(grid.XSize()),
            grid_y_size(grid.YSize()),
            grid_z_size(grid.ZSize()) {

        Logger::Log("Graphics", "creating background buffer...");
        glGenBuffers(1, &background_buffer_object);

        Vertex background_triangle[] = {
            {-1, -1}, {-1,  1}, { 1,  1},
            { 1,  1}, { 1, -1}, {-1, -1},
        };

        glBindBuffer(GL_ARRAY_BUFFER, background_buffer_object);
        glBufferData(GL_ARRAY_BUFFER, sizeof(background_triangle), background_triangle, GL_STATIC_DRAW);

        background_vertex_attrib = background_shader.GetAttribLocation("coord");


        Logger::Log("Graphics", "creating scene buffer...");
        glGenBuffers(1, &scene_buffer_object);

        float min_direction = float(std::min(screen.Width(), screen.Height()));
        float x_pos = min_direction / screen.Width();
        float y_pos = min_direction / screen.Height();
        Vertex scene_triangle[] = {
            {-x_pos, -y_pos}, {-x_pos,  y_pos}, { x_pos,  y_pos},
            { x_pos,  y_pos}, { x_pos, -y_pos}, {-x_pos, -y_pos}
        };

        glBindBuffer(GL_ARRAY_BUFFER, scene_buffer_object);
        glBufferData(GL_ARRAY_BUFFER, sizeof(scene_triangle), scene_triangle, GL_STATIC_DRAW);


        Logger::Log("Graphics", "creating grid texture buffer...");
        glGenTextures(1, &scene_grid_texture_object);

        glBindTexture(GL_TEXTURE_3D, scene_grid_texture_object);
        glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA8UI, grid_x_size, grid_y_size, grid_z_size, 0,
            GL_RGBA_INTEGER, GL_UNSIGNED_BYTE, nullptr);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


        Logger::Log("Graphics", "creating scene materials buffer block...");
        glGenBuffers(1, &scene_materials_block_buffer);


        scene_vertex_attrib = scene_shader.GetAttribLocation("coord");
        scene_screen_size_uniform = scene_shader.GetUniform("screen_size");
        scene_grid_size_uniform = scene_shader.GetUniform("grid_size");
        scene_grid_texture_uniform = scene_shader.GetUniform("grid_texture");
        scene_materials_uniform_block = scene_shader.GetUnifBlock("materials_block");


        glFlush();
        checkOpenGLerror();
    }


    void Graphics::ScreenToGridLocation(int screen_x, int screen_y, int* grid_y, int* grid_z) {
        int min_direction = std::min(screen.Width(), screen.Height());
        int delta_x = (screen.Width() - min_direction) / 2;
        int delta_y = (screen.Height() - min_direction) / 2;
        *grid_y = (screen_x - delta_x) * grid_y_size / min_direction;
        *grid_z = (screen_y - delta_y) * grid_z_size / min_direction;
    }

    int Graphics::XSize() const {
        return grid_x_size;
    }

    int Graphics::YSize() const {
        return grid_y_size;
    }

    int Graphics::ZSize() const {
        return grid_z_size;
    }


    void Graphics::UpdateGrid() {
        glBindTexture(GL_TEXTURE_3D, scene_grid_texture_object);
        glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA8UI, grid_x_size, grid_y_size, grid_z_size, 0,
            GL_RGBA_INTEGER, GL_UNSIGNED_BYTE, grid.Data().Data());
        checkOpenGLerror();
        glFlush();
    }


    void Graphics::UpdateMaterials() {
        Logger::Log("Graphics", "Materials updating...");
        glBindBuffer(GL_UNIFORM_BUFFER, scene_materials_block_buffer);
        glBufferData(GL_UNIFORM_BUFFER, sizeof(GridMaterial) * 16, grid.Materials().data(), GL_STATIC_DRAW);
        checkOpenGLerror();
        glFlush();
    }


    void Graphics::Draw() {
        if (grid.RequireUpdateMaterials()) {
            UpdateMaterials();
            grid.UpdateMaterials();
        }

        if (!grid.RequireUpdateGrid()) return;
        UpdateGrid();
        grid.UpdateGrid();


        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


        background_shader.Use();
        glEnableVertexAttribArray(background_vertex_attrib);

        glBindBuffer(GL_ARRAY_BUFFER, background_buffer_object);
        glVertexAttribPointer(background_vertex_attrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glDrawArrays(GL_TRIANGLES, 0, 6);

        glDisableVertexAttribArray(background_vertex_attrib);



        scene_shader.Use();
        glEnableVertexAttribArray(scene_vertex_attrib);
        glUniform2f(scene_screen_size_uniform, screen.Width(), screen.Height());
        glUniform3f(scene_grid_size_uniform, grid_x_size, grid_y_size, grid_z_size);
        glBindBufferBase(GL_UNIFORM_BUFFER, scene_materials_uniform_block, scene_materials_block_buffer);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_3D, scene_grid_texture_object);
        glUniform1i(scene_grid_texture_uniform, 0);

        glBindBuffer(GL_ARRAY_BUFFER, scene_buffer_object);
        glVertexAttribPointer(scene_vertex_attrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glDrawArrays(GL_TRIANGLES, 0, 6);

        glDisableVertexAttribArray(scene_vertex_attrib);


        glUseProgram(0);
        checkOpenGLerror();
    }


    Graphics::~Graphics() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDeleteBuffers(1, &background_buffer_object);
        glDeleteBuffers(1, &scene_buffer_object);
        glDeleteBuffers(1, &scene_materials_block_buffer);

        glDeleteTextures(1, &scene_grid_texture_object);
    }
}
