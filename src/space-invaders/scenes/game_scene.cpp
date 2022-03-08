#include "space-invaders/scenes/game_scene.h"
#include "space-invaders/assets/assets.h"




GameScene::GameScene(Game& game):
        game(game) {

    game.grid.SetMaterial(0, {{0, 0, 0, 0}});
    game.grid.SetMaterial(1, {{0.5, 0.5, 0, 1}});
    game.grid.SetMaterial(2, {{0, 0, 0, 1}});

    animations.push_back(FrameAnimation::Create(Assets::invader_1, 6, 8, 8, 0.5f));
    for (size_t j = 0; j < 5; ++j) {
        for (size_t i = 0; i < 11; ++i) {
            invaders.push_back(InvaderEntity({1, i * 16, j * 16 + 30}, animations[0]));
        }
    }
}

void GameScene::Tick(float dt) {
    last_time += dt;
    const float step = 0.1;
    while (last_time > 0.1) {
        if (current_invader == invaders.size()) {
            invaders_location += direction;
            if (direction > 0 && invaders_location >= 256 - 11 * 16 || direction < 0 && invaders_location <= 0) {
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

    bool required_update = false;
    for (FrameAnimation& animation: animations) {
        animation.Tick(dt);
        required_update |= animation.UpdateRequired();
    }

    if (required_update) {
        game.grid.Clear();
        for (InvaderEntity& invader: invaders) {
            invader.Draw(game.grid);
        }
    }
}
