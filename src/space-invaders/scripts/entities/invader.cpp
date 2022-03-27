
#include "space-invaders/scripts/entities/invader.h"

#include "space-invaders/scripts/decorations/explosion.h"
#include "space-invaders/scripts/world.h"


namespace SpaceInvaders {

    Invader::Invader(World& world, const FrameAnimation& animation, float hp, Volumatrix::Point shift):
            world(world),
            animation(animation),
            hp(hp),
            shift(shift),
            position(shift) {
    }


    void Invader::Hit(std::shared_ptr<Bullet> bullet) {
        bullet->alive = false;
        hp -= bullet->Damage();
        if (hp <= 0) {
            alive = false;
        }
    }

    void Invader::Hit(float damage) {
        hp -= damage;
        if (hp <= 0) {
            alive = false;
        }
    }



    void Invader::AddGun(Bullet&& bullet, Volumatrix::Point shift, float period, float start_time) {
        guns.push_back(InternalGun{bullet, shift, period, start_time});
    }


    Volumatrix::Point Invader::Size() const {
        const auto& frame = animation.GetFrame();
        return { frame.XSize(), frame.YSize(), frame.ZSize() };
    }

    const Volumatrix::Point& Invader::Position() const {
        return position;
    }

    void Invader::SetPosition(const Volumatrix::Point& p) {
        auto new_pos = p + shift;
        if (position == new_pos) return;
        position = new_pos;
        world.Redraw();
    }

    void Invader::Tick(float dt) {
        animation.Tick(dt);
        if (position.z + Size().z > world.player.Position().z) {
            world.Restart();
        }
        for (auto& gun: guns) {
            for (gun.time = gun.time + dt; gun.time >= gun.period; gun.time -= gun.period) {
                Bullet bullet = gun.bullet;
                bullet.SetPosition(position + gun.shift);
                world.AddBullet(std::move(bullet));
            }
        }
    }

    void Invader::Delete() {
        world.AddDecoration(std::make_shared<Explosion>(world, position + Size() / 2, Volumatrix::GridColor{20, 10, 0}, 10, 7, 100, 15, 30, 2, 0.2));
    }

    void Invader::Draw(Volumatrix::Grid& grid) const {
        animation.Draw(grid, position);
    }
}
