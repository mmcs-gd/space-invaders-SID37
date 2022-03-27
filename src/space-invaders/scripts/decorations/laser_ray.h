#pragma once

#include "space-invaders/scripts/decorations/decoration.h"



namespace SpaceInvaders {

    class LaserRay: public Decoration {
        Volumatrix::Vector3<GLubyte> mesh;
        Volumatrix::Point position;
        Volumatrix::GridColor light;
        GLubyte material;
        int length;

    public:
        LaserRay(World& world, int max_length, GLubyte material, Volumatrix::GridColor light);

        void Update(int new_length);
        void SetPosition(const Volumatrix::Point& point);
        int MaxLEngth();

        virtual void Draw(Volumatrix::Grid& grid) override;
        virtual void Illuminate(Volumatrix::Grid& grid) override;
    };
}
