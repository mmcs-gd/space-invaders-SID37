#include "game.h"


Game::Game(const char* title, int x_size, int y_size, int z_size):
        fps_counter(50),
        screen(title),
        graphics(screen, x_size, y_size, z_size),
        grid(graphics) {
    fps_counter.Restart();
}


void Game::UpdateScene(std::shared_ptr<Scene> new_scene) {
    scene = new_scene;
}


void Game::Tick(float dt) {
    fps_counter.Tick();
    screen.ProcessingEvents();
    if (scene) scene->Tick(dt);
    grid.Draw();
    graphics.Draw();
    screen.Draw();
}
