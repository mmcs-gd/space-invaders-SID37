#include "grid/grid.h"

#include <cstring>


Grid::Grid(Graphics& graphics):
        graphics(graphics),
        data(graphics.XSize(), graphics.YSize(), graphics.ZSize()),
        materials(16),
        update_materials(true) {
}


void Grid::Clear() {
    memset(data.Data(), 0, data.Size() * sizeof(GridPoint));
}


void Grid::StorePoints(const Vector3<GLubyte>& points, const Point& shift) {
    Point size{ points.XSize(), points.YSize(), points.ZSize() };
    for (int z = 0; z < size.z; ++z)
        for (int y = 0; y < size.y; ++y)
            for (int x = 0; x < size.x; ++x)
                data.Get(shift.x + x, shift.y + y, shift.z + z).material = points.Get(x, y, z);
}


void Grid::StoreLight(const Vector3<GridColor>& light, const Point& point) {
    Point size{ light.XSize(), light.YSize(), light.ZSize() };
    for (int z = 0; z < size.z; ++z)
        for (int y = 0; y < size.y; ++y)
            for (int x = 0; x < size.x; ++x)
                data.Get(point.x + x, point.y + y, point.z + z).light = light.Get(x, y, z);
}


void Grid::SetMaterial(GLubyte index, GridMaterial material) {
    materials[index] = material;
    update_materials = true;
}



void Grid::Draw() {
    if (update_materials) {
        graphics.UpdateMaterials(materials.data());
        update_materials = false;
    }
    graphics.UpdateGrid(data.Data());
}
