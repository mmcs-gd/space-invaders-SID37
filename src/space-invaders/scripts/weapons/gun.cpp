#include "space-invaders/scripts/weapons/gun.h"
#include "space-invaders/assets/assets.h"
#include "space-invaders/scripts/world.h"
#include "space-invaders/scripts/weapons/bullet.h"


namespace SpaceInvaders {

    Gun::Gun(World& world, float reload_peroid):
            Weapon(world, Volumatrix::Vector3<GLubyte>({3, 16, 16}, Assets::gun_icon), World::COLOR_GUN),
            reload_peroid(reload_peroid),
            reload_time(0) {
    }


    void Gun::Activate() {
        world.player.UpdateMesh({6, 13, 13, Assets::player_gun[0]});
        world.UpdateMaterial(World::COLOR_PLAYER, {{0.3, 0.7, 0.0}, 1});
    }


    void Gun::Shot() {
        if (reload_time > 0) return;
        reload_time = reload_peroid;
        int bullet_height = 3;

        world.player.UpdateMesh({6, 13, 13, Assets::player_gun[1]});
        world.AddBullet(Bullet(world,
                {1, 1, bullet_height},
                world.player.Position() + Volumatrix::Point{2, world.player.mesh_width / 2, -bullet_height},
                world.COLOR_BULLET, {10, 30, 0}, -100));
    }

    void Gun::Tick(float dt) {
        if (reload_time <= 0) return;
        int last_progress = int(16 * (1 - reload_time / reload_peroid));
        reload_time -= dt;
        if (reload_time <= 0) reload_time = 0;
        int current_progress = int(16 * (1 - reload_time / reload_peroid));
        if (last_progress != current_progress) {
            SetProgress(1 - reload_time / reload_peroid);
            if (current_progress == 3) {
                world.player.UpdateMesh({6, 13, 13, Assets::player_gun[0]});
            }
        }
    }
}
