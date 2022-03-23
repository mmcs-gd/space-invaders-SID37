#include "space-invaders/scripts/weapons/weapon.h"
#include "space-invaders/scripts/world.h"


namespace SpaceInvaders {

    Weapon::Weapon(World& world, const Volumatrix::Vector3<GLubyte>& icon, GLubyte material):
            world(world),
            icon(icon),
            progress_bar(4, 4, 16),
            material(material) {
        this->icon.Replace(1, material);
        this->icon.Replace(2, world.COLOR_CLOUD);
        SetProgress(1);
    };

    void Weapon::SetProgress(float value) {
        for (int z = 0; z < progress_bar.ZSize(); ++z) {
            GLubyte current_material = z + 1 > progress_bar.ZSize() * (1 - value) ? material : world.COLOR_FOG;
            for (int y = 0; y < progress_bar.YSize(); ++y)
                for (int x = 0; x < progress_bar.XSize(); ++x) {
                    progress_bar.Get(x, y, z) = current_material;
                }
        }
        world.Redraw();
    }

    void Weapon::Activate() { };
    void Weapon::Disactivate() { };
    void Weapon::Shot() { };
    void Weapon::Tick(float dt) { };

    void Weapon::Draw(Volumatrix::Grid& grid, const Volumatrix::Point& position) {
        grid.StorePoints(icon, position);
        grid.StorePoints(progress_bar, position + Volumatrix::Point{ 0, 20, 0 });
    }

    Weapon::~Weapon() { }
}
