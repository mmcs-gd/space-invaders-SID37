#include "space-invaders/scripts/weapons/bullet.h"
#include "space-invaders/scripts/world.h"

#include "space-invaders/scripts/decorations/explosion.h"

namespace SpaceInvaders {


    Bullet::Bullet(World& world,
        Volumatrix::Point size, Volumatrix::Point position, GLubyte material,
        Volumatrix::GridColor light, float speed, float damage):
            mesh(size),
            position(position),
            size(size),
            world(world),
            damage(damage),
            light(light),
            speed(speed),
            location(position.z) {
        mesh.Fill(material);
    }


    void Bullet::SetPosition(const Volumatrix::Point& new_position) {
        position = new_position;
        location = new_position.z;
    }

    const Volumatrix::Point& Bullet::Size() const {
        return size;
    }

    const Volumatrix::Point& Bullet::Position() const {
        return position;
    }

    float Bullet::Damage() const {
        return damage;
    }

    float Bullet::Speed() const {
        return speed;
    }

    void Bullet::Delete() {
        auto size = Size();
        world.AddDecoration(std::make_shared<Explosion>(world, position + size / 2, light * 0.5, 10, std::max(size.x, std::max(size.y, size.z)), 20, 15, 30, 1, 0));
    }

    void Bullet::Tick(float dt) {
        location += dt * speed;
        if (position.z == int(location)) return;
        position.z = location;

        if (position.z < 0 || position.z + size.z >= 220) {
            alive = false;
        }
        world.Redraw();
    }

    void Bullet::Draw(Volumatrix::Grid& grid) const {
        grid.StorePoints(mesh, position);
    }

    void Bullet::Illuminate(Volumatrix::Grid& grid) const {
        grid.AddLightSource(light, position, position + size);
    }
}
