#include "space-invaders/scripts/weapons/twix.h"
#include "space-invaders/assets/assets.h"
#include "space-invaders/scripts/world.h"
#include "space-invaders/scripts/weapons/bullet.h"


namespace SpaceInvaders {

    Twix::Twix(World& world, float period, float reserve, float recovery_speed):
            Weapon(world, Volumatrix::Vector3<GLubyte>({3, 16, 16}, Assets::twix_icon), World::COLOR_TWIX),
            period(period),
            reserve(reserve),
            recovery_speed(recovery_speed),
            current_bullets(reserve),
            time(0),
            left_gun(true),
            is_infinity(false) {
    }


    void Twix::SetInfinity(bool value) {
        Reset();
        is_infinity = value;
    }

    void Twix::Activate() {
        world.player.UpdateMesh({6, 13, 13, Assets::player_twix[0]});
        world.UpdateMaterial(World::COLOR_PLAYER, {{0.3, 0.3, 0.5}, 1});
    }

    void Twix::Shot() {
        if (time < period || current_bullets < 1) return;

        int bullet_shift = left_gun ? 2 : -2;
        int frame_number = left_gun ? 2 : 1;
        int bullet_height = 3;

        world.player.UpdateMesh({6, 13, 13, Assets::player_twix[frame_number]});
        world.AddBullet(Bullet(world,
                {1, 1, bullet_height},
                world.player.Position() + Volumatrix::Point{2, world.player.mesh_width / 2 + bullet_shift, -bullet_height},
                world.COLOR_BULLET, {0, 10, 30}, -100));

        if (!is_infinity) {
            current_bullets -= 1;
        }
        left_gun = !left_gun;
        time = 0;
        SetProgress(current_bullets / reserve);
    }


    void Twix::Reset() {
        current_bullets = reserve;
        SetProgress(1);
    }


    void Twix::Tick(float dt) {
        if (time < period) time += dt;
        if (current_bullets >= reserve) return;

        int last_progress = int(16 * current_bullets / reserve);
        current_bullets += dt * recovery_speed;
        if (current_bullets >= reserve) current_bullets = reserve;
        int current_progress = int(16 * current_bullets / reserve);
        if (last_progress != current_progress) {
            SetProgress(current_bullets / reserve);
        }
    }
}
