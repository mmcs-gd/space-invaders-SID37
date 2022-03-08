#pragma once

#include "graphics/screen.h"
#include "graphics/graphics.h"
#include "grid/grid.h"
#include "tools/fps_counter.h"
#include "scene.h"

#include <memory>


class Game {
    FpsCounter fps_counter;

    void ProcessingEvents();

public:
    Screen screen;
    Graphics graphics;
    Grid grid;
    std::shared_ptr<Scene> scene;


    Game(const char* title, int x_size, int y_size, int z_size);

    void UpdateScene(std::shared_ptr<Scene> new_scene);
    void Tick(float dt);
};
