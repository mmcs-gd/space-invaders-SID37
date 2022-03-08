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


void Game::ProcessingEvents() {
    SDL_Event event;
    while (screen.PollInputEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN: scene->EventKeyDown(SDL_KeyCode(event.key.keysym.sym)); break;
            case SDL_KEYUP: scene->EventKeyUp(SDL_KeyCode(event.key.keysym.sym)); break;
            case SDL_MOUSEMOTION: scene->EventMove(event.motion.x, event.motion.y); break;
            case SDL_MOUSEBUTTONDOWN: scene->EventButtonDown(Scene::MouseButtonType(event.button.button), event.button.x, event.button.y); break;
            case SDL_MOUSEBUTTONUP: scene->EventButtonUp(Scene::MouseButtonType(event.button.button), event.button.x, event.button.y); break;
            case SDL_MOUSEWHEEL: scene->EventWheel(event.wheel.y); break;
            default: break;
        }
    }
}


void Game::Tick(float dt) {
    fps_counter.Tick();
    ProcessingEvents();
    if (scene) scene->Tick(dt);
    grid.Draw();
    graphics.Draw();
    screen.Draw();
}
