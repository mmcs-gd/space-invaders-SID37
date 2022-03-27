#pragma once

#include "space-invaders/scripts/weapons/weapon.h"
#include "space-invaders/animation/frame_animation.h"


namespace SpaceInvaders {

    class Lightning: public Weapon {
        float reload_peroid;
        float reload_time;

    public:
        Lightning(World& world, float reload_peroid);

        virtual void Reset() override;
        virtual void Activate() override;
        virtual void Shot() override;
        virtual void Tick(float dt) override;
    };
}
