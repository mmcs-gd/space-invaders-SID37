#include "space-invaders/scripts/weapons/laser.h"
#include "space-invaders/assets/assets.h"
#include "space-invaders/scripts/world.h"
#include "space-invaders/scripts/weapons/bullet.h"
#include "space-invaders/scripts/decorations/explosion.h"


namespace SpaceInvaders {

    Laser::Laser(World& world, float damage, float reserve_time, float recovery_speed):
            Weapon(world, Volumatrix::Vector3<GLubyte>({3, 16, 16}, Assets::laser_icon), World::COLOR_LASER),
            ray(nullptr),
            damage(damage),
            reserve_time(reserve_time),
            recovery_speed(recovery_speed),
            current_time(reserve_time),
            shot(false) {
        ray->Update(0);
    }


    void Laser::Reset() {
        current_time = reserve_time;
        SetProgress(1);
    }


    void Laser::Activate() {
        if (ray == nullptr) {
            ray = std::make_shared<LaserRay>(world, world.player.Position().z + 5, (GLubyte)world.COLOR_BULLET, Volumatrix::GridColor{15, 0, 0});
            world.AddDecoration(ray);
        }
        world.player.UpdateMesh({6, 13, 13, Assets::player_laser[0]});
        world.UpdateMaterial(World::COLOR_PLAYER, {{0.6, 0.6, 0.7}, 1});
        activated = true;
    }


     void Laser::Disactivate() {
        ray->Update(0);
        activated = false;
     }


    void Laser::Shot() {
        if (current_time < 1) return;
        shot = true;
    }

    void Laser::Tick(float dt) {
        int last_progress = int(16 * current_time / reserve_time);
        if (shot) {
            current_time -= dt;
            animation_time += dt;
            auto pos = world.player.Position();
            auto size = world.player.Size();
            auto invader = world.HitLaser({pos.x + size.x / 2, pos.y + size.y / 2, 0}, {1, 1, pos.z});
            Volumatrix::Point hit_point = {pos.x + size.x / 2, pos.y + size.y / 2, invader == nullptr ? 0 : invader->Position().z + invader->Size().z};

            ray->SetPosition({hit_point.x, hit_point.y, 0});
            if (invader == nullptr) {
                ray->Update(ray->MaxLEngth());
            }
            else {
                ray->Update(ray->MaxLEngth() - invader->Position().z - invader->Size().z);
                invader->Hit(dt * damage);
            }
            while (animation_time > 0.3) {
                animation_frame = (animation_frame + 1) % 2;
                world.player.UpdateMesh({6, 13, 13, Assets::player_laser[animation_frame + 1]});
                animation_time -= 0.3;
                world.AddDecoration(std::make_shared<Explosion>(world, hit_point, Volumatrix::GridColor{15, 0, 0}, 3, 4, 100, 20, 30, 0.3, 0));
            }
            last_shot = true;
            shot = false;
        }
        else if (last_shot) {
            ray->Update(0);
            last_shot = false;
            if (activated) {
            world.player.UpdateMesh({6, 13, 13, Assets::player_laser[0]});
            }
        }

        if (current_time >= reserve_time) return;
        current_time += dt * recovery_speed;
        if (current_time >= reserve_time) current_time = reserve_time;
        int current_progress = int(16 * current_time / reserve_time);
        if (last_progress != current_progress) {
            SetProgress(current_time / reserve_time);
        }
    }
}
