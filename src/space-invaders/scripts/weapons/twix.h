#pragma once

#include "space-invaders/scripts/weapons/weapon.h"
#include "space-invaders/animation/frame_animation.h"


namespace SpaceInvaders {

    class Twix: public Weapon {
        float period;
        float reserve;
        float recovery_speed;
        float current_bullets;
        float time;
        bool left_gun;

    public:
        Twix(World& world, float period, float reserve, float recovery_speed);

        virtual void Reset() override;
        virtual void Activate() override;
        virtual void Shot() override;
        virtual void Tick(float dt) override;
    };
}
