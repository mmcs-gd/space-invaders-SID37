#include "space-invaders/scenes/game_scene.h"



namespace SpaceInvaders {

    GameScene::GameScene(Volumatrix::Game& game):
            game(game),
            world(game.grid, 0) {
    }


    void GameScene::EventKeyDown(SDL_KeyCode key) {
        int num = -1;
        switch (key) {
            case SDL_KeyCode::SDLK_a:
            case SDL_KeyCode::SDLK_LEFT:
                keys.left = true;
                world.InputDirection(Direction::LEFT_DIRECTION);
            break;
            case SDL_KeyCode::SDLK_d:
            case SDL_KeyCode::SDLK_RIGHT:
                keys.right = true;
                world.InputDirection(Direction::RIGHT_DIRECTION);
            break;
            case SDL_KeyCode::SDLK_SPACE:
            case SDL_KeyCode::SDLK_KP_ENTER:
                keys.shoot = true;
                world.InputShoot(true);
            break;
            case SDL_KeyCode::SDLK_1: num = 1; break;
            case SDL_KeyCode::SDLK_2: num = 2; break;
            case SDL_KeyCode::SDLK_3: num = 3; break;
            case SDL_KeyCode::SDLK_4: num = 4; break;
            case SDL_KeyCode::SDLK_5: num = 5; break;
            case SDL_KeyCode::SDLK_6: num = 6; break;
            case SDL_KeyCode::SDLK_7: num = 7; break;
            case SDL_KeyCode::SDLK_8: num = 8; break;
            case SDL_KeyCode::SDLK_9: num = 9; break;
            default: break;
        }
        if (num > 0 && num <= world.WeaponsCount()) {
            keys.weapon = num;
            world.InputGun(num - 1);
        }
    }


    void GameScene::EventKeyUp(SDL_KeyCode key) {
        switch (key) {
            case SDL_KeyCode::SDLK_a:
            case SDL_KeyCode::SDLK_LEFT:
                keys.left = false;
                world.InputDirection(keys.right ? RIGHT_DIRECTION : NONE_DIRECTION);
            break;
            case SDL_KeyCode::SDLK_d:
            case SDL_KeyCode::SDLK_RIGHT:
                keys.right = false;
                world.InputDirection(keys.left ? LEFT_DIRECTION : NONE_DIRECTION);
            break;
            case SDL_KeyCode::SDLK_SPACE:
                keys.shoot = false;
                world.InputShoot(false);
            break;
            default: break;
        }
    }


    void GameScene::EventButtonDown(MouseButtonType button, int x, int y) {
        if (button == MouseButtonType::BUTTON_LEFT) {
            EventKeyDown(SDL_KeyCode::SDLK_SPACE);
        }
    }


    void GameScene::EventButtonUp(MouseButtonType button, int x, int y) {
        if (button == MouseButtonType::BUTTON_LEFT) {
            EventKeyUp(SDL_KeyCode::SDLK_SPACE);
        }
    }


    void GameScene::EventWheel(int delta) {
        int new_weapon = keys.weapon + delta;
        if (new_weapon > 0 && new_weapon <= world.WeaponsCount()) {
            keys.weapon = new_weapon;
            world.InputGun(new_weapon - 1);
        }
    }


    void GameScene::Tick(float dt) {
        world.Tick(dt);
        world.Draw();
    }
}
