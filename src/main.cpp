#include "game.h"
#include "space-invaders/scenes/game_scene.h"
#include "space-invaders/scenes/editor_scene.h"
#include "space-invaders/scenes/test_scene.h"

#include "tools/logger.h"

#include <emscripten.h>
#include <iostream>


Game game("Space Invaders", 8, 256, 256);
auto last_time =  std::chrono::system_clock::now();

int tick_counter = 0;

void Update() {
    auto now =  std::chrono::system_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::microseconds>(now - last_time).count();
    last_time = now;
    delta = std::min(50000ll, delta);

    game.Tick(delta / 1000000.0f);
}


int main() {
    game.UpdateScene(std::make_shared<GameScene>(game));
    // game.UpdateScene(std::make_shared<EditorScene>(game));
    // game.UpdateScene(std::make_shared<TestScene>(game));

    try {
        emscripten_set_main_loop(Update, 0, 1);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
