#pragma once

#include "volumatrix/graphics/screen.h"
#include "volumatrix/graphics/graphics.h"
#include "volumatrix/grid/grid.h"
#include "volumatrix/tools/fps_counter.h"
#include "volumatrix/scene.h"

#include <memory>


namespace Volumatrix {

    class Game {
        FpsCounter fps_counter;

        void ProcessingEvents();

    public:
        Screen screen;
        Grid grid;
        Graphics graphics;
        std::shared_ptr<Scene> scene;


        Game(const char* title, int x_size, int y_size, int z_size);

        void UpdateScene(std::shared_ptr<Scene> new_scene);
        void Tick(float dt);
    };
}
