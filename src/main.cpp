#include "graphics/screen.h"
#include "graphics/graphics.h"
#include "tools/fps_counter.h"

#include <emscripten.h>
#include <iostream>
#include <stdexcept>


class Game {
    Screen screen;
    Graphics graphics{screen};
    FpsCounter fps_counter{100};

public:
    Game():
            screen("Gray Screen"),
            graphics(screen),
            fps_counter(100) {
        fps_counter.Restart();
    }

    void Update() {
        screen.ProcessingEvents();
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
