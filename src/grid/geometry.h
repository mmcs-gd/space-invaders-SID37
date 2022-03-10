#pragma once

#include <cstdlib>


struct Point {
    size_t x;
    size_t y;
    size_t z;

    Point operator-(const Point& p) {
        return {x - p.x, y - p.y, z - p.z};
    }
};
