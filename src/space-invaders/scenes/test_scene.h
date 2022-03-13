#pragma once

#include "space-invaders/animation/frame_animation.h"
#include "space-invaders/entities/invader_entity.h"
#include "space-invaders/assets/assets.h"
#include "volumatrix/scene.h"
#include "volumatrix/game.h"

#include <vector>

namespace SpaceInvaders {

    class TestScene: public Volumatrix::Scene {
        Volumatrix::Game& game;
        Volumatrix::Vector3<GLubyte> invader;
        Volumatrix::Vector3<GLubyte> cloud;
        Volumatrix::Vector3<GLubyte> bullet;
        bool update = true;

    public:
        TestScene(Volumatrix::Game& game):
                game(game),
                invader(6, 14, 8, Assets::invader_3[0]),
                cloud(6, 16, 11, Assets::cloud_1[0]),
                bullet(1, 1, 4, Assets::player_bullet_1[0]) {
            game.grid.SetMaterial(0, {{0, 0, 0}, 0});
            game.grid.SetMaterial(1, {{0.5, 0.5, 0}, 1});
            game.grid.SetMaterial(2, {{0, 0, 0}, 1});
            game.grid.SetMaterial(3, {{1, 1, 1}, 0, 0.5});
            game.grid.SetMaterial(4, {{0.8, 0.8, 1.0}, 1});
            cloud.Replace(1, 3);
            bullet.Replace(1, 4);
        }

        virtual void Tick(float dt) override {
            // if (!update) return;
            update = false;
            game.grid.Clear();
            game.grid.StorePoints(invader, {1, 0, 12});
            game.grid.StorePoints(invader, {1, 20, 12});
            game.grid.StorePoints(cloud, {1, 1, 26});
            game.grid.StorePoints(cloud, {1, 17, 29});
            Volumatrix::Point bullet_location{4, 19, 26};
            game.grid.StorePoints(bullet, bullet_location);
            game.grid.AddLightSource({100, 100, 0}, bullet_location, bullet_location + Volumatrix::Point{1, 1, 4});
        }
    };
}