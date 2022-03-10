#include "space-invaders/scenes/game_scene.h"
#include "space-invaders/assets/assets.h"

#include <cmath>
namespace {
    template <typename T>
    T sqr(T v) { return v * v; }
}


GameScene::GameScene(Game& game):
        game(game),
        bullet_light(7, 15, 18) {

    game.grid.SetMaterial(0, {{0, 0, 0}, 0});
    game.grid.SetMaterial(1, {{0.5, 0.5, 0}, 1});
    game.grid.SetMaterial(2, {{0, 0, 0}, 1});
    game.grid.SetMaterial(3, {{0, 0.5, 0.5}, 1});
    game.grid.SetMaterial(4, {{0, 0.7, 0}, 1});
    game.grid.SetMaterial(5, {{0.8, 0.8, 1.0}, 1});
    game.grid.SetMaterial(6, {{0.7, 0.4, 0}, 1});
    game.grid.SetMaterial(7, {{1, 1, 1}, 0, 0.3});

    GLubyte empty_animation[1][1] = {0};
    animations.push_back(FrameAnimation::Create(Assets::invader_1, 6, 8, 8, 0.5f));
    animations.push_back(FrameAnimation::Create(Assets::invader_2, 5, 11, 8, 0.5f));
    animations.push_back(FrameAnimation::Create(Assets::player_1, 5, 13, 7, 0.5f));
    animations.push_back(FrameAnimation::Create(Assets::player_bullet_1, 1, 1, 4, 0.5f));
    animations.push_back(FrameAnimation::Create(empty_animation, 1, 1, 1, 0.5f));
    animations.push_back(FrameAnimation::Create(Assets::invader_3, 6, 14, 8, 0.5f));
    animations.push_back(FrameAnimation::Create(Assets::cloud_1, 6, 16, 11, 0.5f));

    animations[1].Replace(1, 3);
    animations[2].Replace(1, 4);
    animations[3].Replace(1, 5);
    animations[5].Replace(1, 6);
    animations[6].Replace(1, 7);

    player = std::make_shared<InvaderEntity>(Point{1, size_t(player_location), 200}, &animations[2]);
    player_bullet = std::make_shared<InvaderEntity>(Point{4, 10, 200 - 10}, &animations[3]);

    for (int z = 0; z < bullet_light.ZSize(); ++z)
        for (int y = 0; y < bullet_light.YSize(); ++y)
            for (int x = 0; x < bullet_light.XSize(); ++x) {
                float result = 0;
                for (int i = 0; i < 4; ++i)
                    result += 250 / (sqr(x - 4) + sqr(y - 7) + sqr(z - (7 + i)) + 0.001);
                GLubyte value = (GLubyte)result;
                GLubyte value_8_8 = (GLubyte)(result * 0.8);
                bullet_light.Get(x, y, z) = {value_8_8, value_8_8, value};
            }

    for (size_t i = 0; i < 40; ++i) {
        decorations.push_back(InvaderEntity({size_t(rand() % 3), size_t(rand() % 240), size_t(130 + rand() % 50)}, &animations[6]));
    }

    for (size_t j = 0; j < 2; ++j) {
        for (size_t i = 0; i < 11; ++i) {
            invaders.push_back(InvaderEntity({2, i * 16, j * 16 + 30}, &animations[0]));
            invaders_count += 1;
        }
    }
    for (size_t j = 0; j < 2; ++j) {
        for (size_t i = 0; i < 11; ++i) {
            invaders.push_back(InvaderEntity({2, i * 16, (j + 2) * 16 + 30}, &animations[1]));
            invaders_count += 1;
        }
    }
    for (size_t j = 0; j < 1; ++j) {
        for (size_t i = 0; i < 11; ++i) {
            invaders.push_back(InvaderEntity({2, i * 16, (j + 4) * 16 + 30}, &animations[5]));
            invaders_count += 1;
        }
    }
}


void GameScene::EventKeyDown(SDL_KeyCode key) {
    if (key == SDLK_LEFT || key == SDLK_a) move_direction = -100;
    if (key == SDLK_RIGHT || key == SDLK_d) move_direction = 100;
    if (key == SDLK_SPACE) {
        if (bullet_location > 0) return;
        bullet_location = player->location.z - 4;
        player_bullet->location = {
            player_bullet->location.x,
            player->location.y + 6,
            size_t(bullet_location)};
    };
}

void GameScene::EventKeyUp(SDL_KeyCode key) {
    if ((key == SDLK_LEFT || key == SDLK_a) && move_direction < 0) move_direction = 0;
    if ((key == SDLK_RIGHT || key == SDLK_d) && move_direction > 0) move_direction = 0;
}


void GameScene::EventButtonDown(MouseButtonType button, int x, int y) {
    if (button != MouseButtonType::BUTTON_LEFT) return;
    int fragment = game.screen.Width() / 4;
    if (x < fragment) EventKeyDown(SDLK_LEFT);
    else if (x > 3 * fragment) EventKeyDown(SDLK_RIGHT);
    else EventKeyDown(SDLK_SPACE);
}


void GameScene::EventButtonUp(MouseButtonType button, int x, int y) {
    if (button != MouseButtonType::BUTTON_LEFT) return;
    int fragment = game.screen.Width() / 4;
    if (x < fragment) EventKeyUp(SDLK_LEFT);
    else if (x > 3 * fragment) EventKeyUp(SDLK_RIGHT);
    else EventKeyUp(SDLK_SPACE);
}


void GameScene::Tick(float dt) {

    last_time += dt;
    const float step = 0.0001 * invaders_count;
    while (last_time > step) {
        if (current_invader == invaders.size()) {
            invaders_location += direction;
            if (direction > 0 && invaders_location >= 256 - 11 * 16 || direction < 0 && invaders_location <= 0) {
                for (int i = 0; i < invaders.size(); ++i) {
                    invaders[i].location.z += 3;
                    if (invaders[i].animation != &animations[4] && invaders[i].location.z > player->location.z - 10) {
                        game.UpdateScene(std::make_shared<GameScene>(game));
                        return;
                    }
                }
                direction = -direction;
            }
            current_invader = 0;
            continue;
        }
        else {
            invaders[current_invader].location.y += direction;
        }
        current_invader += 1;
        last_time -= step;
    }

    if (move_direction != 0) {
        player_location += move_direction * dt;
        if (player_location < 0) player_location = 0;
        if (player_location > 240) player_location = 240;
        player->location.y = (int)player_location;
    }

    if (bullet_location > 0) {
        bullet_location -= dt * 100;
        player_bullet->location.z = std::max(int(bullet_location), 0);
        for (int i = 0; i < invaders.size(); ++i) {
            auto& frame = invaders[i].animation->GetFrame();
            if (frame.Size() > 1 &&
                    player_bullet->location.y >= invaders[i].location.y &&
                    player_bullet->location.y < invaders[i].location.y + frame.YSize() &&
                    player_bullet->location.z >= invaders[i].location.z &&
                    player_bullet->location.z < invaders[i].location.z + frame.ZSize()) {
                bullet_location = 0;
                invaders[i].animation = &animations[4];
                invaders_count -= 1;
                if (invaders_count == 0) {
                    game.UpdateScene(std::make_shared<GameScene>(game));
                }
            }
        }
    }

    for (FrameAnimation& animation: animations) {
        animation.Tick(dt);
    }

    for (InvaderEntity& decoration: decorations) {
        if (rand() % 10 == 0) {
            decoration.location.y = (decoration.location.y + 1) % 240;
        }
    }


    game.grid.Clear();
    for (InvaderEntity& decoration: decorations) {
        decoration.Draw(game.grid);
    }
    for (InvaderEntity& invader: invaders) {
        invader.Draw(game.grid);
    }
    player->Draw(game.grid);
    if (bullet_location > 0) {
        player_bullet->Draw(game.grid);
        if (player_bullet->location.z > 7)
            game.grid.StoreLight(bullet_light, player_bullet->location - Point{4, 7, 7});
    }
}
