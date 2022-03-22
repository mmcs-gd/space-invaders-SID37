#include "space-invaders/scripts/weapons/gun.h"
#include "space-invaders/assets/assets.h"
#include "space-invaders/scripts/world.h"
#include "space-invaders/scripts/weapons/bullet.h"


namespace SpaceInvaders {

    Gun::Gun(World& world, float reload_peroid):
            Weapon(world, Volumatrix::Vector3<GLubyte>({3, 16, 16}, Assets::gun_icon)),
            reload_peroid(reload_peroid),
            reload_time(0) {
    }

    void Gun::Shot() {
        if (reload_time > 0) return;
        reload_time = reload_peroid;
        int bullet_height = 3;

        world.AddBullet(Bullet(world,
                {1, 1, bullet_height},
                world.player.Position() + Volumatrix::Point{2, world.player.mesh_width / 2, -bullet_height},
                world.COLOR_BULLET, {10, 30, 0}, -100));
    }

    void Gun::Tick(float dt) {
        if (reload_time <= 0) return;
        reload_time -= dt;
        if (reload_time <= 0) reload_time = 0;
    }
}
