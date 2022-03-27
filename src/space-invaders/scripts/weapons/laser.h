#pragma once

#include "space-invaders/scripts/weapons/weapon.h"
#include "space-invaders/animation/frame_animation.h"
#include "space-invaders/scripts/decorations/laser_ray.h"

#include <memory>

namespace SpaceInvaders {

    class Laser: public Weapon {
        std::shared_ptr<LaserRay> ray;
        float damage;
        float reserve_time;
        float recovery_speed;
        float current_time;
        bool shot;

        float animation_time = 0;
        int animation_frame = 0;
        bool last_shot = false;
        bool activated = false;
        bool is_infinity = false;

    public:
        Laser(World& world, float damage, float reserve_time, float recovery_speed);

        virtual void SetInfinity(bool value) override;
        virtual void Reset() override;
        virtual void Activate() override;
        virtual void Disactivate() override;
        virtual void Shot() override;
        virtual void Tick(float dt) override;
    };
}
