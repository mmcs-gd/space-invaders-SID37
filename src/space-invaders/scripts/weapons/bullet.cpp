#include "space-invaders/scripts/weapons/bullet.h"
#include "space-invaders/scripts/world.h"


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


    void Bullet::Tick(float dt) {
        location += dt * speed;
        if (position.z == int(location)) return;
        position.z = location;

        if (position.z < 0 || position.z + size.z >= 256) {
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
