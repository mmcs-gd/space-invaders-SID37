#include "space-invaders/scripts/world.h"

#include "space-invaders/scripts/weapons/weapon.h"
#include "space-invaders/scripts/weapons/gun.h"
#include "space-invaders/scripts/levels/levels.h"
#include "space-invaders/scripts/decorations/cloud.h"

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
                std::make_shared<Gun>(*this, 1.5)
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

    void World::AddBullet(Bullet&& bullet) {
        bullets.push_back(std::make_shared<Bullet>(bullet));
        Redraw();
    }

    void World::AddBehavior(BehaviorBox&& behavior) {
        behavior_boxes.push_back(std::make_shared<BehaviorBox>(behavior));
        Redraw();
    }

    std::shared_ptr<Invader> World::MakeInvader(FrameAnimation&& animation, float hp,  std::initializer_list<std::tuple<GLubyte, ColorIndex>> colors) {
        for (const auto& c: colors) {
            animation.Replace(std::get<0>(c), std::get<1>(c));
        }
        auto ptr = std::make_shared<Invader>(*this, animation, hp);
        invaders.push_back(ptr);
        Redraw();
        return ptr;
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

        level = 0;
        Levels::Init(*this, level);
        restarting = false;
        Redraw();
    }

    void World::Restart() {
        restarting = true;
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
            vect.pop_back();
        }
    }


    void World::Tick(float dt) {
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
        for (auto decoration: decorations) {
            decoration->Tick(dt);
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
                i == current_weapon ? 0 : 4,
                i * Weapon::icon_width,
                230
            };
            grid.StorePoints(weapons[i]->GetIcon(), p);
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
    }
}
