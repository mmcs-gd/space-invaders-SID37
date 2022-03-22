#include "volumatrix/grid/grid.h"

#include <cstring>
#include <cmath>


namespace Volumatrix {

    Grid::Grid(size_t x_size, size_t y_size, size_t z_size):
            data(x_size, y_size, z_size),
            materials(16),
            update_materials(true),
            update_grid(true) {
    }


    void Grid::Clear() {
        memset(data.Data(), 0, data.Size() * sizeof(GridPoint));
        update_grid = true;
    }


    void Grid::StorePoints(const Vector3<GLubyte>& points, const Point& shift) {
        Point size{ points.XSize(), points.YSize(), points.ZSize() };
        Point from{
            shift.x < 0 ? -shift.x : 0,
            shift.y < 0 ? -shift.y : 0,
            shift.z < 0 ? -shift.z : 0,
        };
        Point to{
            shift.x + size.x >= data.XSize() ? data.XSize() - shift.x : size.x,
            shift.y + size.y >= data.YSize() ? data.YSize() - shift.y : size.y,
            shift.z + size.z >= data.ZSize() ? data.ZSize() - shift.z : size.z,
        };
        for (int z = from.z; z < to.z; ++z)
            for (int y = from.y; y < to.y; ++y)
                for (int x = from.x; x < to.x; ++x) {
                    GLubyte value = points.Get(x, y, z);
                    if (value != 0) {
                        data.Get(shift.x + x, shift.y + y, shift.z + z).material = value;
                    }
                }
        update_grid = true;
    }


    void Grid::StoreLight(const Vector3<GridColor>& light, const Point& point) {
        Point size{ light.XSize(), light.YSize(), light.ZSize() };
        for (int z = 0; z < size.z; ++z)
            for (int y = 0; y < size.y; ++y)
                for (int x = 0; x < size.x; ++x)
                    data.Get(point.x + x, point.y + y, point.z + z).light += light.Get(x, y, z);
        update_grid = true;
    }


    namespace {
        int CutLength(int from, int to, int x) {
            if (x < from) return int(x) - from;
            if (x > to) return int(x) - to;
            return 0;
        }
    }

    void Grid::DrowLightLayer(const Point& from, const Point& buffer_size,
                const Point& layer_p1, const Point& layer_p2,
                const Point& buffer_p1, const Point& buffer_p2) {
        for (int z = std::max(layer_p1.z, 0); z < std::min(layer_p2.z, buffer_size.z); ++z)
            for (int y = std::max(layer_p1.y, 0); y < std::min(layer_p2.y, buffer_size.y); ++y)
                for (int x = std::max(layer_p1.x, 0); x < std::min(layer_p2.x, buffer_size.x); ++x) {
                    Point p {x, y, z};
                    Point cut {
                        CutLength(buffer_p1.x, buffer_p2.x - 1, x),
                        CutLength(buffer_p1.y, buffer_p2.y - 1, y),
                        CutLength(buffer_p1.z, buffer_p2.z - 1, z),
                    };
                    int max = std::max(std::abs(cut.x), std::max(std::abs(cut.y), std::abs(cut.z)));
                    Point delta = {
                        (cut.x > 0 ? 1 : -1) * ((std::abs(cut.x) * 2) / (max + 1)),
                        (cut.y > 0 ? 1 : -1) * ((std::abs(cut.y) * 2) / (max + 1)),
                        (cut.z > 0 ? 1 : -1) * ((std::abs(cut.z) * 2) / (max + 1)),
                    };
                    float last_light = light_buffer.Get(p - delta);
                    const GridMaterial& material = materials[data.Get(from + p).material];
                    light_buffer.Get(x, y, z) = last_light * (1.0 - material.Reflection()) * (1.0 - material.Density());
                }
    }


    void Grid::AddLightSource(GridColor color, Point p1, Point p2) {
        p1 = { std::max(p1.x, 0), std::max(p1.y, 0), std::max(p1.z, 0)};
        p2 = { std::min(p2.x, data.XSize()), std::min(p2.y, data.YSize()), std::min(p2.z, data.ZSize())};
        int max_distance = (int)std::sqrt(std::max(std::max(color.r, color.g), color.b)) * 2;
        Point from {
            std::max(p1.x - max_distance, 0),
            std::max(p1.y - max_distance, 0),
            std::max(p1.z - max_distance, 0)
        };
        Point to {
            std::min(p2.x + max_distance, (int)data.XSize()),
            std::min(p2.y + max_distance, (int)data.YSize()),
            std::min(p2.z + max_distance, (int)data.ZSize())
        };
        Point buffer_size = to - from;
        light_buffer.Resize(buffer_size);

        Point light_size = p2 - p1;
        Point buffer_p1 = p1 - from;
        Point buffer_p2 = p2 - from;
        for (int z = 0; z < light_size.z; ++z)
            for (int y = 0; y < light_size.y; ++y)
                for (int x = 0; x < light_size.x; ++x)
                    light_buffer.Get(buffer_p1 + Point{x, y, z}) = 1;

        for (int i = 1; i <= max_distance; ++i) {
            Point layer_p1 = buffer_p1 - Point{i, i, i};
            Point layer_p2 = buffer_p2 + Point{i, i, i};

            DrowLightLayer(from, buffer_size, layer_p1, { layer_p1.x + 1, layer_p2.y, layer_p2.z }, buffer_p1, buffer_p2);
            DrowLightLayer(from, buffer_size, { layer_p2.x - 1, layer_p1.y, layer_p1.z }, layer_p2, buffer_p1, buffer_p2);
            layer_p2.x -= 1; layer_p1.x += 1;
            DrowLightLayer(from, buffer_size, layer_p1, { layer_p2.x, layer_p1.y + 1, layer_p2.z }, buffer_p1, buffer_p2);
            DrowLightLayer(from, buffer_size, { layer_p1.x, layer_p2.y - 1, layer_p1.z }, layer_p2, buffer_p1, buffer_p2);
            layer_p2.y -= 1; layer_p1.y += 1;
            DrowLightLayer(from, buffer_size, layer_p1, { layer_p2.x, layer_p2.y, layer_p1.z + 1 }, buffer_p1, buffer_p2);
            DrowLightLayer(from, buffer_size, { layer_p1.x, layer_p1.y, layer_p2.z - 1 }, layer_p2, buffer_p1, buffer_p2);
        }

        for (int z = 0; z < buffer_size.z; ++z)
            for (int y = 0; y < buffer_size.y; ++y)
                for (int x = 0; x < buffer_size.x; ++x) {
                    Point cut {
                        CutLength(buffer_p1.x, buffer_p2.x - 1, x),
                        CutLength(buffer_p1.y, buffer_p2.y - 1, y),
                        CutLength(buffer_p1.z, buffer_p2.z - 1, z),
                    };

                    if (cut.x == 0 && cut.y == 0 && cut.z == 0 ) {
                        data.Get(from.x + x, from.y + y, from.z + z).light += color * 20;
                        continue;
                    }
                    int dist = std::sqrt(cut.x * cut.x + cut.y * cut.y + cut.z * cut.z);
                    data.Get(from.x + x, from.y + y, from.z + z).light += color * (20 * light_buffer.Get(x, y, z) / (dist * dist));
                }
        update_grid = true;
    }


    void Grid::SetMaterial(GLubyte index, GridMaterial material) {
        materials[index] = material;
        update_materials = true;
    }


    const Vector3<GridPoint>& Grid::Data() const {
        return data;
    }

    const std::vector<GridMaterial>& Grid::Materials() const {
        return materials;
    }


    int Grid::XSize() {
        return data.XSize();
    }

    int Grid::YSize() {
        return data.YSize();
    }

    int Grid::ZSize() {
        return data.ZSize();
    }



    bool Grid::RequireUpdateMaterials() {
        return update_materials;
    }

    bool Grid::RequireUpdateGrid() {
        return update_grid;
    }

    void Grid::UpdateMaterials() {
        update_materials = false;
    }

    void Grid::UpdateGrid() {
        update_grid = false;
    }
}
