#pragma once

class Scene {
public:
    virtual void Tick(float dt) = 0;
    virtual ~Scene() {}
};
