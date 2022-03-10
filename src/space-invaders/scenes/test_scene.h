#pragma once

#include "space-invaders/animation/frame_animation.h"
#include "space-invaders/entities/invader_entity.h"
#include "space-invaders/assets/assets.h"
#include "scene.h"
#include "game.h"

#include <vector>

class TestScene: public Scene {
    Game& game;
    Vector3<GLubyte> result;
    bool update = true;

public:
    TestScene(Game& game):
            game(game),
            result(6, 14, 8, Assets::invader_3[0]) {
        game.grid.SetMaterial(0, {{0, 0, 0}, 0});
        game.grid.SetMaterial(1, {{0.2, 0.7, 0}, 0, 0.5});
        game.grid.SetMaterial(2, {{0, 0, 0}, 1});
        game.grid.SetMaterial(3, {{1, 0, 0}, 1, 0.5});
    }

    virtual void Tick(float dt) override {
        // if (!update) return;
        update = false;
        game.grid.Clear();
        game.grid.StorePoints(result, {1, 3, 12});
    }
};
