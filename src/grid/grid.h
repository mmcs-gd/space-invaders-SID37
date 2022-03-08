#pragma once

#include "grid/geometry.h"
#include "grid/vector_3.h"
#include "graphics/graphics.h"

#include <vector>


class Grid {
    Graphics& graphics;

    Vector3<GridPoint> data;
    std::vector<GridMaterial> materials;
    bool update_materials;
    bool update_grid;

public:
    Grid(Graphics& graphics);

    void Clear();

    void StorePoints(const Vector3<GLubyte>& points, const Point& point);
    void StoreLight(const Vector3<GridColor>& light, const Point& point);
    void SetMaterial(GLubyte index, GridMaterial materisal);

    void Draw();
};
