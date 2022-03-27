#pragma once

#include "space-invaders/scripts/base.h"
#include "space-invaders/scripts/ammunition.h"
#include "space-invaders/scripts/player.h"
#include "space-invaders/scripts/weapons/bullet.h"
#include "space-invaders/scripts/weapons/weapon.h"
#include "space-invaders/scripts/entities/behavior_box.h"
#include "space-invaders/scripts/entities/invader.h"
#include "space-invaders/scripts/decorations/decoration.h"

#include <vector>
#include <initializer_list>
#include <tuple>


namespace SpaceInvaders {

    class World {

    public:

        enum ColorIndex: GLuint {
            COLOR_EMPTY = 0,
            COLOR_PLAYER = 1,
            COLOR_BULLET = 2,

            COLOR_CLOUD = 3,
            COLOR_FOG = 4,

            COLOR_GUN = 5,
            COLOR_TWIX = 6,
            COLOR_LASER = 7,
            COLOR_LIGHTNING = 8,

            COLOR_INVADER_0 = 9,
            COLOR_INVADER_1 = 10,
            COLOR_INVADER_2 = 11,
            COLOR_INVADER_3 = 12,
        };

        Volumatrix::Grid& grid;
        std::vector<std::shared_ptr<Weapon>> weapons;
        std::vector<std::shared_ptr<Bullet>> bullets;
        std::vector<std::shared_ptr<Invader>> invaders;
        std::vector<std::shared_ptr<BehaviorBox>> behavior_boxes;
        std::vector<std::shared_ptr<Decoration>> decorations;
        Player player;

    private:
        bool require_update = true;
        bool activate_weapon = false;
        int current_weapon = 0;
        bool restarting = false;
        float pause_time = 0;
        int level = 0;

        void NextLevel();
        void HardRestart();

    public:

        World(Volumatrix::Grid& grid, int start_level = 0);

        void UpdateMaterial(ColorIndex idx, const Volumatrix::GridMaterial& material);

        void InputDirection(Direction direction);
        void InputShoot(bool value);
        void InputGun(int index);


        std::shared_ptr<Invader> HitLaser(Volumatrix::Point pos, Volumatrix::Point size);
        std::shared_ptr<Invader> HitLightning();

        void AddDecoration(std::shared_ptr<Decoration> decoration);
        std::shared_ptr<BehaviorBox> AddBehavior(BehaviorBox&& behavior);
        std::shared_ptr<Invader> AddInvader(Invader&& invader);
        std::shared_ptr<Bullet> AddBullet(Bullet&& bullet);

        void Restart();

        void Redraw();
        void Win();

        int WeaponsCount();

        void Tick(float dt);
        void Draw();
    };
}
