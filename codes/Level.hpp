#pragma once
#include "raylib.h"
#include "unit.hpp"
#include "unitZone.hpp"

#include <vector>
#include <memory>

class Level
{
public:
    Level();

    void Update();
    void Draw();

private:
    std::vector<std::unique_ptr<Unit>> m_units;
    UnitZone m_zones;

    int m_draggingUnit = -1;
    bool m_puzzleSolved = false;
};