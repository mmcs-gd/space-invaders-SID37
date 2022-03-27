#include "space-invaders/scripts/world.h"

#include "space-invaders/scripts/weapons/weapon.h"
#include "space-invaders/scripts/weapons/gun.h"
#include "space-invaders/scripts/weapons/twix.h"
#include "space-invaders/scripts/weapons/laser.h"
#include "space-invaders/scripts/weapons/lightning.h"
#include "space-invaders/scripts/levels/levels.h"
#include "space-invaders/scripts/decorations/cloud.h"
#include "space-invaders/scripts/decorations/explosion.h"

#include <algorithm>


namespace SpaceInvaders {

    namespace {
        bool CollideBoxes(
            const Volumatrix::Point& point1, const Volumatrix::Point& size1,
            const Volumatrix::Point& point2, const Volumatrix::Point& size2) {
            return
                point1.x < point2.x + size2.x &&
                point2.x < point1.x + size1.x &&
                point1.y < point2.y + size2.y &&
                point2.y < point1.y + size1.y &&
                point1.z < point2.z + size2.z &&
                point2.z < point1.z + size1.z;
        }
    }

    World::World(Volumatrix::Grid& grid, int start_level):
            grid(grid),
            level(start_level),
            weapons({
                std::make_shared<Gun>(*this, 1.5),
                std::make_shared<Twix>(*this, 0.2, 10, 0.1),
                std::make_shared<Laser>(*this, 2, 5, 0.2),
                std::make_shared<Lightning>(*this, 20),
            }),
            bullets(),
            invaders(),
            decorations(),
            behavior_boxes(),
            player(*this, {1, 128, 200}){
        UpdateMaterial(COLOR_EMPTY, {{0, 0, 0}, 0});
        UpdateMaterial(COLOR_BULLET, {{1, 1, 1}, 0.5, 1});
        UpdateMaterial(COLOR_CLOUD, {{1, 1, 1}, 0.1, 0.5});
        UpdateMaterial(COLOR_FOG, {{1, 1, 1}, 0, 0.3});

        UpdateMaterial(COLOR_GUN, {{0.3, 0.5, 0}, 0.7, 0.5});
        UpdateMaterial(COLOR_TWIX, {{0.3, 0.3, 0.5}, 0.7, 0.5});
        UpdateMaterial(COLOR_LASER, {{0.6, 0, 0}, 0.7, 0.5});
        UpdateMaterial(COLOR_LIGHTNING, {{0.7, 0.7, 0.7}, 0.7, 0.5});

        Levels::Init(*this, level);
        for (int i = 0; i < 50; ++i) {
            float z = rand() / float(RAND_MAX);
            AddDecoration(std::make_shared<Cloud>(*this,
            Volumatrix::Point{rand() % 4, rand() % 256, int(z * z * 40) },
            Volumatrix::Point{5, 30 + rand() % 30 , 10 + rand() % 20}, 0, 3));
        }
    }


    void World::InputDirection(Direction direction) {
        player.SetDirection(direction);
    }


    void World::InputShoot(bool value) {
        activate_weapon = value;
    }

    void World::UpdateMaterial(ColorIndex idx, const Volumatrix::GridMaterial& material) {
        grid.SetMaterial(idx, material);
    }

    void World::InputGun(int index) {
        if (index < 0 || index >= weapons.size() || current_weapon == index)
            return;
        weapons[current_weapon]->Disactivate();
        weapons[index]->Activate();
        current_weapon = index;
        Redraw();
    }


    void World::AddDecoration(std::shared_ptr<Decoration> decoration) {
        decorations.push_back(decoration);
        Redraw();
    }


    std::shared_ptr<BehaviorBox> World::AddBehavior(BehaviorBox&& behavior) {
        behavior_boxes.push_back(std::make_shared<BehaviorBox>(behavior));
        Redraw();
        return behavior_boxes.back();
    }

    std::shared_ptr<Invader> World::AddInvader(Invader&& invader) {
        invaders.push_back(std::make_shared<Invader>(invader));
        Redraw();
        return invaders.back();
    }

    std::shared_ptr<Bullet> World::AddBullet(Bullet&& bullet) {
        bullets.push_back(std::make_shared<Bullet>(bullet));
        Redraw();
        return bullets.back();
    }


    void World::NextLevel() {
        behavior_boxes.clear();
        ++level;
        Levels::Init(*this, level);
        Redraw();
    }

    void World::HardRestart() {
        behavior_boxes.clear();
        bullets.clear();
        invaders.clear();

        for (auto weapon: weapons) {
            weapon->Reset();
        }

        level = 0;
        Levels::Init(*this, level);
        restarting = false;
        Redraw();
    }

    void World::Restart() {
        Volumatrix::Point pos = player.Position() + player.Size() / 2;
        AddDecoration(std::make_shared<Explosion>(*this, pos, Volumatrix::GridColor{40, 20, 0}, 10, 5, 100, 30, 50, 3, 0));
        restarting = true;
        pause_time = 0.5;
    }


    int World::WeaponsCount() {
        return weapons.size();
    }


    void World::Redraw() {
        require_update = true;
    }

    void World::Win() {
        Volumatrix::Logger::Log("World", "Win!!!");
    }


    std::shared_ptr<Invader> World::HitLaser(Volumatrix::Point pos, Volumatrix::Point size) {
        int last_distance = -1;
        std::shared_ptr<Invader> result = nullptr;
        for (auto invader: invaders) {
            if (CollideBoxes(pos, size, invader->Position(), invader->Size())) {
                int distance = invader->Position().z + invader->Size().z;
                if (distance > last_distance) result = invader;
            }
        }
        return result;
    }


    std::shared_ptr<Invader> World::HitLightning() {
        int last_distance = 256;
        std::shared_ptr<Invader> result = nullptr;
        for (auto invader: invaders) {
            int distance = invader->Position().z;
            if (distance < last_distance) {
                last_distance = distance;
                result = invader;
            }
        }
        return result;
    }


    template<typename T>
    void DeleteNotAlive(std::vector<std::shared_ptr<T>>& vect) {
        int count = 0;
        for (auto value: vect)
            if (!value->alive)
                count += 1;

        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < vect.size() - 1; ++j) {
                if (!vect[j]->alive) {
                    std::swap(vect[j], vect[j + 1]);
                }
            }
            vect.back()->Delete();
            vect.pop_back();
        }
    }


    void World::Tick(float dt) {
        for (auto decoration: decorations) {
            decoration->Tick(dt);
        }

        if (pause_time > 0) {
            pause_time -= dt;
            return;
        }

        for (auto bullet: bullets) {
            auto pos = bullet->Position();
            auto size = bullet->Size();
            if (CollideBoxes(pos, size, player.Position(), player.Size())) {
                player.Hit(bullet);
            }
            for (auto invader: invaders) {
                if (CollideBoxes(pos, size, invader->Position(), invader->Size())) {
                    invader->Hit(bullet);
                }
            }
        }

        if (invaders.size() == 0) {
            NextLevel();
        }
        if (restarting) {
            HardRestart();
        }

        player.Tick(dt);
        for (auto weapon: weapons) {
            weapon->Tick(dt);
        }
        if (activate_weapon) {
            weapons[current_weapon]->Shot();
        }
        for (auto bullet: bullets) {
            bullet->Tick(dt);
        }
        for (auto behavior: behavior_boxes) {
            behavior->Tick(dt);
        }
        for (auto invader: invaders) {
            invader->Tick(dt);
        }
        DeleteNotAlive(bullets);
        DeleteNotAlive(invaders);
        DeleteNotAlive(decorations);
    }

    void World::Draw() {
        if (!require_update) return;
        require_update = false;

        grid.Clear();

        // Draw

        for (auto decoterion: decorations) {
            decoterion->Draw(grid);
        }

        player.Draw(grid);
        for (int i = 0; i < weapons.size(); ++i) {
            Volumatrix::Point p {
                i == current_weapon ? 1 : 4,
                i * Weapon::icon_width,
                230
            };
            weapons[i]->Draw(grid, p);
        }

        for (auto bullet: bullets) {
            bullet->Draw(grid);
        }

        for (auto invader: invaders) {
            invader->Draw(grid);
        }

        // Illuminate

        for (auto decoterion: decorations) {
            decoterion->Illuminate(grid);
        }

        for (auto bullet: bullets) {
            bullet->Illuminate(grid);
        }

        Volumatrix::Point current_veapo_point = { 0, current_weapon * Weapon::icon_width, 230};
        grid.AddLightSource({5, 5, 5}, current_veapo_point, current_veapo_point + Volumatrix::Point{ 3, Weapon::icon_width, 16});
    }
}
