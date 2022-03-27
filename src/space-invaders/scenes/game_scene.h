#pragma once

#include "space-invaders/scripts/world.h"
#include "volumatrix/scene.h"
#include "volumatrix/game.h"

#include <vector>


namespace SpaceInvaders {

    class GameScene : public Volumatrix::Scene {
        Volumatrix::Game& game;
        World world;

        struct PressedKeys {
            int weapon = 0;
            bool left = false;
            bool right = false;
            bool shoot = false;
        } keys;


    public:
        GameScene(Volumatrix::Game& game);

        virtual void EventKeyDown(SDL_KeyCode key) override;
        virtual void EventKeyUp(SDL_KeyCode key) override;
        virtual void EventButtonDown(MouseButtonType button, int x, int y) override;
        virtual void EventButtonUp(MouseButtonType button, int x, int y) override;
        virtual void EventWheel(int delta) override;

        virtual void Tick(float dt) override;
    };
}
