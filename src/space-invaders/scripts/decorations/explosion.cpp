#include "space-invaders/scripts/decorations/explosion.h"
#include "space-invaders/scripts/world.h"


namespace SpaceInvaders {

    namespace{
        int sqr(int x) {
            return x * x;
        }

        float sqr(float x) {
            return x * x;
        }
    }


    Explosion::Explosion(World& world, Volumatrix::Point position, Volumatrix::GridColor color, int particle_count, int size, float acceleration, float speed_from, float speed_to, float ttl, float start_time):
            Decoration(world),
            position(position),
            acceleration(acceleration),
            trajectoryes(),
            ttl(ttl),
            color(color),
            time(start_time),
            size(size),
            mesh(size, size, size) {
        if (size > 10 || size < 0) {
            Volumatrix::Logger::Log("Explosion", "Hm...");
        }
        for (int i = 0; i < particle_count; ++i) {
            trajectoryes.push_back({
                (rand() > RAND_MAX / 2 ? 1 : -1) * (speed_from + rand() * (speed_to - speed_from) / float(RAND_MAX)),
                (rand() > RAND_MAX / 2 ? 1 : -1) * (speed_from + rand() * (speed_to - speed_from) / float(RAND_MAX)),
                (rand() > RAND_MAX / 2 ? 1 : -1) * (speed_from + rand() * (speed_to - speed_from) / float(RAND_MAX)),
            });
        }
        Tick(0);
    }

    void Explosion::Tick(float dt) {
        time += dt;
        if (time >= ttl) {
            alive = false;
        }

        int r = size / 2;
        float r2 = r * r * sqr(1 - time / ttl);
        for (int z = 0; z < size; ++z)
            for (int y = 0; y < size; ++y)
                for (int x = 0; x < size; ++x) {
                    int dist = sqr(x - r) + sqr(y - r) + sqr(z - r);
                    if (dist <= r2 * sqr(0.7f)) mesh.Get(x, y, z) = world.COLOR_CLOUD;
                    if (dist <= r2 * sqr(1.2f)) mesh.Get(x, y, z) = world.COLOR_FOG;
                    else mesh.Get(x, y, z) = world.COLOR_EMPTY;
                }
    }


    Volumatrix::Point Explosion::GetPosition(const Trajectory& t) {
        return {
            std::max(size / 2, std::min(8 - size / 2, int(position.x + t.vx * time))),
            std::max(size / 2, std::min(255 - size / 2, int(position.y + t.vy * time))),
            std::max(size / 2, std::min(255 - size / 2, int(position.z + t.vz * time + acceleration * time * time / 2))),
        };
    }


    void Explosion::Draw(Volumatrix::Grid& grid) {
        Volumatrix::Point r {size / 2, size / 2, size / 2};
        for (const auto& t: trajectoryes) {
            grid.StorePoints(mesh, GetPosition(t) - r);
        }
    }

    void Explosion::Illuminate(Volumatrix::Grid& grid) {
        Volumatrix::GridColor current_color = color * (1 - time / ttl);
        for (const auto& t: trajectoryes) {
            Volumatrix::Point p = GetPosition(t);
            grid.AddLightSource(current_color, p, p + Volumatrix::Point{1, 1, 1});
        }

        if (!init) return;
        init = false;
        Volumatrix::Point r {size / 2, size / 2, size / 2};
        grid.AddLightSource(color, position - r, position + r + Volumatrix::Point{1, 1, 1});
    }
}
