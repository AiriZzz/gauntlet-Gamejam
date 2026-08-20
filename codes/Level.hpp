#pragma once
#include "raylib.h"
#include "unit.hpp"
#include "MarchingZone.hpp"
#include "UnitZone.hpp"
#include "LevelData.hpp"

#include <vector>
#include <memory>
#include <iostream>

class Level
{
public:
    Level(const LevelData& levelData);
    ~Level();

    void Update();
    void Draw();

    bool CheckPuzzle();

private:
    std::vector<std::unique_ptr<Unit>> m_units;
    UnitZone m_unitZones;
    MarchingZone m_marchingZones;

    Unit* m_draggingUnit = nullptr;
    bool m_draggedUnitZone = false; //is Unit dragged from the Unitzone
    bool m_puzzleSolved = false;

    Texture2D m_levelPopup;

};