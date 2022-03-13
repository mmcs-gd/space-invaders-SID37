#pragma once

#include "geometry.h"

#include <vector>


template<typename T>
class Vector3 {
    std::vector<T> vect;
    int x_size;
    int y_size;
    int z_size;

public:
    Vector3():
            vect(0),
            x_size(0),
            y_size(0),
            z_size(0) {
    }


    Vector3(Point size, const T* data = nullptr):
            vect(size.x * size.y * size.z),
            x_size(size.x),
            y_size(size.y),
            z_size(size.z) {

        if (data == nullptr) {
            return;
        }

        for (int i = 0; i < Size(); ++i) {
            vect[i] = data[i];
        }
    }


    Vector3(int x, int y, int z, const T* data = nullptr):
            Vector3({x, y, z}, data) {
    }

    void Fill(const T& value) {
        for (int i = 0; i < Size(); ++i) {
            vect[i] = value;
        }
    }

    T* Data() { return vect.data(); }

    constexpr int Size() const { return x_size * y_size * z_size; }
    constexpr int XSize() const { return x_size; }
    constexpr int YSize() const { return y_size; }
    constexpr int ZSize() const { return z_size; }

    void Replace(const T& old_value, const T& new_value) {
        for (int i = 0; i < Size(); ++i)
            if (vect[i] == old_value)
                vect[i] = new_value;
    }


    void Resize(int x, int y, int z) {
        x_size = x;
        y_size = y;
        z_size = z;
        vect.resize(Size());
    }

    void Resize(Point p) {
        x_size = p.x;
        y_size = p.y;
        z_size = p.z;
        vect.resize(Size());
    }


    const T& Get(Point p) const {
        return vect[p.x + x_size * (p.y + y_size * p.z)];
    }

    T& Get(Point p) {
        return vect[p.x + x_size * (p.y + y_size * p.z)];
    }

    const T& Get(int x, int y, int z) const {
        return Get({x, y, z});
    }

    T& Get(int x, int y, int z) {
        return Get({x, y, z});
    }
};
