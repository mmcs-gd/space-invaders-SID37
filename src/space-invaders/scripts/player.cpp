
#include "space-invaders/scripts/player.h"

#include "space-invaders/assets/assets.h"
#include "space-invaders/scripts/world.h"


namespace SpaceInvaders {

    Player::Player(World& world, Volumatrix::Point start_point):
            world(world),
            mesh(),
            position(start_point),
            location(start_point.y) {
        world.UpdateMaterial(World::COLOR_PLAYER, {{0.3, 0.7, 0.0}, 1});
        UpdateMesh({6, 13, 13, Assets::player_gun[0]});
    }


    Volumatrix::Point Player::Size() const {
        return { mesh.XSize(), mesh.YSize(), mesh.ZSize() };
    }

    void Player::SetDirection(Direction d) {
        direction = d;
    }


    void Player::Hit(std::shared_ptr<Bullet> bullet) {
        bullet->alive = false;
        world.Restart();
    }


    const Volumatrix::Point& Player::Position() const {
        return position;
    }


    void Player::UpdateMesh(Volumatrix::Vector3<GLubyte>&& new_mesh) {
        mesh = new_mesh;
        new_mesh.Replace(1, world.COLOR_PLAYER);
        world.Redraw();
    }

    void Player::Tick(float dt) {

        int k = direction == RIGHT_DIRECTION ? 1 : direction == LEFT_DIRECTION ? -1 : 0;

        location += k * speed * dt;
        if (location < 0) location = 0;
        if (location >= 256 - mesh_width) location = 256 - mesh_width;

        int i_location = int(location);
        if (i_location == position.y) return;
        position.y = i_location;
        world.Redraw();
    }


    void Player::Draw(Volumatrix::Grid& grid) const {
        grid.StorePoints(mesh, position);
    }
}
