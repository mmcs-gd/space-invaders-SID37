#include "space-invaders/scripts/weapons/lightning.h"
#include "space-invaders/assets/assets.h"
#include "space-invaders/scripts/world.h"
#include "space-invaders/scripts/weapons/bullet.h"
#include "space-invaders/scripts/decorations/lightning_ray.h"


namespace SpaceInvaders {

    Lightning::Lightning(World& world, float reload_peroid):
            Weapon(world, Volumatrix::Vector3<GLubyte>({3, 16, 16}, Assets::lightning_icon), World::COLOR_LIGHTNING),
            reload_peroid(reload_peroid),
            reload_time(0),
            is_infinity(false) {
    }


    void Lightning::SetInfinity(bool value) {
        is_infinity = value;
        Reset();
    }

    void Lightning::Reset() {
        reload_time = 0;
        SetProgress(1);
    }


    void Lightning::Activate() {
        world.player.UpdateMesh({6, 13, 13, Assets::player_lightning[0]});
        world.UpdateMaterial(World::COLOR_PLAYER, {{0.7, 0.7, 0.7}, 1});
    }

    void Lightning::Shot() {
        if (reload_time > 0) return;
        if (!is_infinity) {
            reload_time = reload_peroid;
        }
        int bullet_height = 3;

        int max_height = 100;
        world.player.UpdateMesh({6, 13, 13, Assets::player_lightning[1]});
        auto invader = world.HitLightning();
        if (invader == nullptr) return;
        world.AddDecoration(std::make_shared<LightningRay>(world,
            Volumatrix::Point{invader->Position().x, invader->Position().y, 0},
            Volumatrix::Point{invader->Size().x, invader->Size().y, std::min(max_height, invader->Position().z)},
            Volumatrix::GridColor{100, 100, 100}));
        if (invader->Position().z <= max_height) {
            invader->Hit(3);
        }
    }

    void Lightning::Tick(float dt) {
        if (reload_time <= 0) return;
        int last_progress = int(16 * (1 - reload_time / reload_peroid));
        reload_time -= dt;
        if (reload_time <= 0) reload_time = 0;
        int current_progress = int(16 * (1 - reload_time / reload_peroid));
        if (last_progress != current_progress) {
            SetProgress(1 - reload_time / reload_peroid);
            if (current_progress == 2) {
                world.player.UpdateMesh({6, 13, 13, Assets::player_lightning[0]});
            }
        }
    }
}
