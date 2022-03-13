#pragma once

#include "grid/geometry.h"
#include "grid/vector_3.h"
#include "graphics/graphics.h"

#include <vector>


class Grid {
    Graphics& graphics;

    Vector3<GridPoint> data;
    Vector3<float> light_buffer;
    std::vector<GridMaterial> materials;
    bool update_materials;
    bool update_grid;

    void DrowLightLayer(const Point& from, const Point& buffer_size,
                const Point& layer_p1, const Point& layer_p2,
                const Point& buffer_p1, const Point& buffer_p2);


public:
    Grid(Graphics& graphics);

    void Clear();

    void StorePoints(const Vector3<GLubyte>& points, const Point& point);
    void StoreLight(const Vector3<GridColor>& light, const Point& point);
    void AddLightSource(GridColor color, Point p1, Point p2);
    void SetMaterial(GLubyte index, GridMaterial materisal);

    void Draw();
};
