#include "space-invaders/scripts/decorations/cloud.h"
#include "space-invaders/scripts/world.h"

#include <random>


namespace SpaceInvaders {

    namespace{
        int sqr(int x) {
            return x * x;
        }
    }

    Cloud::Cloud(World& world, Volumatrix::Point position, Volumatrix::Point size, float speed_from, float speed_to):
            Decoration(world),
            position(position),
            mesh(size),
            location(position.y),
            speed_from(speed_from),
            speed_to(speed_to) {
        Volumatrix::Point r {(size.x) / 2, (size.y) / 2, (size.z) / 2};
        Volumatrix::Point r2 {sqr(r.x + 1), sqr(r.y + 1), sqr(r.z + 1)};
            for (int z = 0; z < size.z; ++z)
                for (int y = 0; y < size.y; ++y)
                    for (int x = 0; x < size.x; ++x) {
                    float rnd = rand() / float(RAND_MAX);
                    float comp_r = r2.x * r2.y * r2.z * (1 - rnd * rnd * rnd);
                    float dist = sqr(x - r.x) * r2.y * r2.z + sqr(y - r.y) * r2.x * r2.z + sqr(z - r.z) * r2.x * r2.y;
                    if (dist <= 0.8 * comp_r) mesh.Get(x, y, z) = world.COLOR_CLOUD;
                    else if (dist <= comp_r) mesh.Get(x, y, z) = world.COLOR_FOG;
                    else mesh.Get(x, y, z) = world.COLOR_EMPTY;
                }
    }


    void Cloud::Tick(float dt) {
        float speed = speed_from + rand() * (speed_to - speed_from) / float(RAND_MAX);
        location += speed * dt;
        if (int(location) != position.y) {
            if (int(location) + mesh.YSize() >= 256) location = 0;
            if (int(location) < 0) location = 255;
            position.y = int(location);
            world.Redraw();
        }
    }

    void Cloud::Draw(Volumatrix::Grid& grid) {
        grid.StorePoints(mesh, position);
    }
}
