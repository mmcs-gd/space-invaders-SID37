#include "graphics/screen.h"
#include "graphics/graphics.h"
#include "grid/grid.h"
#include "tools/fps_counter.h"

#include <emscripten.h>
#include <iostream>
#include <stdexcept>
#include <vector>



GLubyte invader[2][6 * 8 * 8] {
    {
        0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  2, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  2, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,  0, 1, 0, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 0, 1, 0,  0, 0, 1, 0, 1, 0,  0, 0, 0, 0, 0, 0,  0, 1, 0, 1, 0, 0,  0, 0, 0, 0, 0, 0,
        0, 1, 0, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 0, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 0, 1, 0,  0, 0, 0, 0, 0, 0,  0, 1, 0, 1, 0, 0,
    },
    {
        0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  2, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  2, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
    }
};


class Game {
    Screen screen;
    Graphics graphics;
    Grid grid;
    FpsCounter fps_counter;

    Vector3<GLubyte> invader_frame_1;
    Vector3<GLubyte> invader_frame_2;
    Point invader_location;
    int screen_counter = 0;

public:
    Game():
            screen("Invader in space"),
            graphics(screen, 8, 20, 20),
            fps_counter(100),
            grid(graphics),
            invader_frame_1(6, 8, 8, invader[0]),
            invader_frame_2(6, 8, 8, invader[1]),
            invader_location{0, 0, 0} {
        fps_counter.Restart();
        grid.SetMaterial(0, {{0, 0, 0, 0}});
        grid.SetMaterial(1, {{0.5, 0.5, 0, 1}});
        grid.SetMaterial(2, {{0, 0, 0, 1}});
    }

    void Update() {
        ++screen_counter;
        if (screen_counter % 40 > 20)  grid.StorePoints(invader_frame_1, invader_location);
        else grid.StorePoints(invader_frame_2, invader_location);

        screen.ProcessingEvents();
        grid.Draw();
        graphics.Draw();
        screen.Draw();
        fps_counter.Tick();
    }
};

Game game;

void Update() {
    game.Update();
}


int main() {
    try {
        emscripten_set_main_loop(Update, 0, 1);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
