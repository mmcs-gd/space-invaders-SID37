
#include "space-invaders/scripts/entities/invader.h"

#include "space-invaders/scripts/decorations/explosion.h"
#include "space-invaders/scripts/world.h"


namespace SpaceInvaders {

    Invader::Invader(World& world, const FrameAnimation& animation, float hp, Volumatrix::Point position):
            world(world),
            animation(animation),
            hp(hp),
            position(position) {
    }


    void Invader::Hit(std::shared_ptr<Bullet> bullet) {
        bullet->alive = false;
        hp -= bullet->Damage();
        if (hp <= 0) {
            world.AddDecoration(std::make_shared<Explosion>(world, position + Size() / 2, Volumatrix::GridColor{20, 10, 0}, 10, 7, 100, 15, 30, 2, 0.2));
            alive = false;
        }
    }


    Volumatrix::Point Invader::Size() const {
        const auto& frame = animation.GetFrame();
        return { frame.XSize(), frame.YSize(), frame.ZSize() };
    }

    const Volumatrix::Point& Invader::Position() const {
        return position;
    }

    void Invader::SetPosition(const Volumatrix::Point& p) {
        if (position == p) return;
        position = p;
        if (position.z + Size().z > world.player.Position().z) {
            world.Restart();
        }
        world.Redraw();
    }

    void Invader::Tick(float dt) {
        animation.Tick(dt);
    }

    void Invader::Draw(Volumatrix::Grid& grid) const {
        animation.Draw(grid, position);
    }
}
