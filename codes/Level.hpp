#pragma once
#include "raylib.h"
#include "unit.hpp"
#include "unitZone.hpp"
#include "LevelData.hpp"

#include <vector>
#include <memory>

class Level
{
public:
    Level(const LevelData& levelData);

    void Update();
    void Draw();

private:
    std::vector<std::unique_ptr<Unit>> m_units;
    UnitZone m_zones;

    Unit* m_draggingUnit = nullptr;
    bool m_puzzleSolved = false;
};