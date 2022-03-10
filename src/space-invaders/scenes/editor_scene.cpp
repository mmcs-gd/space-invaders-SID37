#include "space-invaders/scenes/editor_scene.h"

#include <string>
#include <iostream>


EditorScene::EditorScene(Game& game):
        game(game),
        result(game.graphics.XSize(), game.graphics.YSize(), game.graphics.ZSize()),
        depth(0),
        update_grid(true),
        location_x(0),
        location_y(0) {

    game.grid.SetMaterial(0, {{0, 0, 0}, 0});
    game.grid.SetMaterial(1, {{0.5, 0.5, 0}, 0.5, 0.5});
    game.grid.SetMaterial(2, {{0.2, 0.2, 0.2}, 0.5});
    game.grid.SetMaterial(3, {{0.5, 0, 0}, 0.5});
}


void EditorScene::EventKeyDown(SDL_KeyCode key) {

    if (key == SDL_KeyCode::SDLK_UP) EventWheel(1);
    if (key == SDL_KeyCode::SDLK_DOWN) EventWheel(-1);

    if (key == SDL_KeyCode::SDLK_SPACE) {
        std::string line;
        for (int z = 0; z < result.ZSize(); ++z) {
            for (int y = 0; y < result.YSize(); ++y) {
                for (int x = 0; x < result.XSize(); ++x) {
                    line += std::to_string(result.Get(x, y, z)) + ", ";
                }
                line += " ";
            }
            std::cout << line << std::endl;
            line.clear();
        }
    }
}

void EditorScene::EventWheel(int delta) {
    if (delta == 0) return;

    if (result.Get(depth, location_x, location_y) > 1) {
        result.Get(depth, location_x, location_y) -= 2;
    }

    if (delta > 0 && depth < result.XSize() - 1) {
        depth += 1;
    }
    if (delta < 0 && depth > 0) {
        depth -= 1;
    }

    update_grid = true;
    result.Get(depth, location_x, location_y) += 2;
}


void EditorScene::EventButtonDown(MouseButtonType button, int x, int y) {
    if (button == MouseButtonType::BUTTON_LEFT) {
        if (result.Get(depth, location_x, location_y) % 2 == 0) {
            result.Get(depth, location_x, location_y) = 1;
        }
        else {
            result.Get(depth, location_x, location_y) = 0;
        }
        update_grid = true;
    }
}


void EditorScene::EventMove(int x, int y) {
    if (result.Get(depth, location_x, location_y) > 1) {
        result.Get(depth, location_x, location_y) -= 2;
    }

    int grid_y;
    int grid_z;
    game.graphics.ScreenToGridLocation(x, y, &grid_y, &grid_z);
    if (grid_y >= 0 && grid_y < result.YSize() && grid_z >= 0 && grid_z < result.ZSize()) {
        location_x = grid_y;
        location_y = grid_z;
    }

    result.Get(depth, location_x, location_y) += 2;
    update_grid = true;
}


void EditorScene::Tick(float dt) {
    if (!update_grid) return;
    game.grid.Clear();
    game.grid.StorePoints(result, { 0, 0, 0 });
    update_grid = false;
}
