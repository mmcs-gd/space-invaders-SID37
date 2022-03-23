#include "space-invaders/scripts/decorations/laser_ray.h"
#include "space-invaders/scripts/world.h"


namespace SpaceInvaders {

    LaserRay::LaserRay(World& world, int max_length, GLubyte material, Volumatrix::GridColor light):
            Decoration(world),
            mesh(1, 1, max_length),
            light(light),
            material(material) {
        
    }

    void LaserRay::Update(int new_length) {
        length = new_length;
        for (int i = 0; i < mesh.ZSize() - length; ++i) {
            mesh.Get(0, 0, i) = world.COLOR_EMPTY;
        }
        for (int i = mesh.ZSize() - length; i < mesh.ZSize(); ++i) {
            mesh.Get(0, 0, i) = material;
        }
    }

    int LaserRay::MaxLEngth() {
        return mesh.ZSize();
    }


    void LaserRay::SetPosition(const Volumatrix::Point& point) {
        position = point;
    }

    void LaserRay::Draw(Volumatrix::Grid& grid) {
        if (length == 0) return;
        grid.StorePoints(mesh, position);
    }

    void LaserRay::Illuminate(Volumatrix::Grid& grid) {
        if (length == 0) return;
        grid.AddLightSource(light, position + Volumatrix::Point{1, 1, mesh.ZSize() - length}, position + Volumatrix::Point{1, 1, mesh.ZSize()});
    }
}
