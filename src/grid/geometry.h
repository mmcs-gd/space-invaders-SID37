#pragma once

#include <cstdlib>


struct Point {
    int x;
    int y;
    int z;

    Point operator-(const Point& p) const {
        return {x - p.x, y - p.y, z - p.z};
    }

    Point operator+(const Point& p) const {
        return {x + p.x, y + p.y, z + p.z};
    }
};
