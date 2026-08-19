#pragma once
#include "raylib.h"
#include "unit.hpp"
#include <vector>
#include <string>

//Use during level creation, when deciding what Unit spawns in the level
struct UnitData{

    std::string name;
    Color color;
    Vector2 position;
    Vector2 size;
    UnitType type;

};

//This will be read for level creation
struct LevelData{

    std::vector<UnitData> units;
    std::vector<UnitType> solution;

    //Vector2 zonePosition;
    //Vector2 zoneSize;

    //std::string LevelPopup;
    
};