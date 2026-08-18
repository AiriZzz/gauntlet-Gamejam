#pragma once

#include "raylib.h"
#include "codes/unit.hpp"
#include "codes/unitZone.hpp"

#include <vector>

class Level
{
public:
    Level();

    void Update();
    void Draw();

private:
    std::vector<Unit> m_units;
    UnitZone m_zone;

    int m_draggingUnit = -1;
    bool m_puzzleSolved = false;
};