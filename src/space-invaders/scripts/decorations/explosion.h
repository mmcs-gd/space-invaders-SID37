#pragma once

#include "space-invaders/scripts/decorations/decoration.h"

#include <vector>


namespace SpaceInvaders {

    class Explosion: public Decoration {
        struct Trajectory {
            float vx;
            float vy;
            float vz;
        };

        Volumatrix::Point position;
        Volumatrix::Vector3<GLubyte> mesh;
        Volumatrix::GridColor color;
        std::vector<Trajectory> trajectoryes;
        float acceleration;
        float ttl;
        float time;
        int size;

        bool init = true;

        Volumatrix::Point GetPosition(const Trajectory& t);

    public:
        Explosion(World& world, Volumatrix::Point position, Volumatrix::GridColor color, int particle_count, int size, float acceleration, float speed_from, float speed_to, float ttl, float start_time);

        virtual void Tick(float dt) override;
        virtual void Draw(Volumatrix::Grid& grid) override;
        virtual void Illuminate(Volumatrix::Grid& grid) override;
    };
}
