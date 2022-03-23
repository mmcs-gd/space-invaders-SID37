#include "space-invaders/scripts/decorations/lightning_ray.h"

#include "space-invaders/scripts/world.h"


namespace SpaceInvaders {

    LightningRay::LightningRay(World& world, Volumatrix::Point position, Volumatrix::Point size, Volumatrix::GridColor light):
            Decoration(world),
            position(position),
            mesh(size),
            light(light) {
        for (int z = 0; z < size.z; ++z)
            for (int y = 0; y < size.y; ++y)
                for (int x = 0; x < size.x; ++x)
                    mesh.Get(x, y, z) = world.COLOR_EMPTY;
        Volumatrix::Point p { rand() % size.x, rand() % size.y, 0};
        for (p.z = 0; p.z < size.z; ++p.z) {
            p.x = std::max(0, std::min(size.x, p.x + (rand() > RAND_MAX / 2 ? -1 : 1)));
            p.y = std::max(0, std::min(size.y, p.y + (rand() > RAND_MAX / 2 ? -1 : 1)));
            mesh.Get(p) = world.COLOR_BULLET;
        }
    }

    void LightningRay::Tick(float dt) {
        if (kill) alive = false;
        kill = true;
    }

    void LightningRay::Draw(Volumatrix::Grid& grid) {
        grid.StorePoints(mesh, position);
    }

    void LightningRay::Illuminate(Volumatrix::Grid& grid) {
        grid.AddLightSource(light, position, position + Volumatrix::Point{mesh.XSize(), mesh.YSize(), mesh.ZSize()});
    }
}
