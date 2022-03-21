#pragma once

#include "space-invaders/animation/frame_animation.h"
#include "space-invaders/assets/assets.h"
#include "volumatrix/scene.h"
#include "volumatrix/game.h"

#include <vector>

namespace SpaceInvaders {

    class TestScene2: public Volumatrix::Scene {
        Volumatrix::Game& game;
        Volumatrix::Vector3<GLubyte> bullet;
        Volumatrix::Vector3<GLubyte> cloud;
        Volumatrix::Vector3<GLubyte> cube;
        Volumatrix::Vector3<GLubyte> plane;
        Volumatrix::Vector3<GLubyte> luja;
        Volumatrix::Vector3<GLubyte> cuplya;

        Volumatrix::Point bullet_location{10, 15, 10};
        float counter;
        bool update = true;

    public:
        TestScene2(Volumatrix::Game& game):
                game(game),
                bullet(1, 1, 4, Assets::player_bullet_1[0]),
                cloud(6, 16, 11, Assets::cloud_1[0]),
                luja(10, 10, 1),
                cuplya(1, 1, 2),
                plane(20, 20, 2),
                cube(3, 3, 3) {
            game.grid.SetMaterial(0, {{0, 0, 0}, 0});
            game.grid.SetMaterial(1, {{0.4, 0.4, 0.4}, 1});
            game.grid.SetMaterial(2, {{1, 1, 1}, 0, 0.5});
            game.grid.SetMaterial(3, {{0, 0.2, 1}, 0.5, 0.2});
            game.grid.SetMaterial(4, {{0.8, 0.8, 1.0}, 1});
            game.grid.SetMaterial(5, {{0.1, 0.4, 0.3}, 1});
            plane.Fill(5);
            cube.Fill(1);
            luja.Fill(3);
            cuplya.Fill(3);
            cloud.Replace(1, 2);
            bullet.Replace(1, 4);
        }

        virtual void Tick(float dt) override {
            // counter += dt;
            // float period = 0.1f;
            // while (counter > period) {
            //     counter -= period;
            //     bullet_location.y = (bullet_location.y + 1) % 20;
            //     update = true;
            // }
            if (!update) return;
            update = false;
            game.grid.Clear();

            game.grid.StorePoints(plane, {0, 0, 18});
            game.grid.StorePoints(cube, {7, 4, 15});

            game.grid.StorePoints(luja, {9, 8, 18});
            game.grid.StorePoints(cuplya, {11, 3, 12});
            game.grid.StorePoints(cuplya, {13, 8, 10});
            game.grid.StorePoints(cuplya, {10, 13, 13});

            game.grid.StorePoints(cloud, {10, 0, 0});
            game.grid.StorePoints(bullet, bullet_location);
            game.grid.AddLightSource({100, 100, 0}, bullet_location, bullet_location + Volumatrix::Point{1, 1, 4});
        }
    };
}