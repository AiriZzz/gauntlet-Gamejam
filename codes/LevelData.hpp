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
    std::string texturePath;

};

//This will be read for level creation
struct LevelData{

    std::vector<UnitData> units;
    std::vector<UnitType> solution;

    std::string LevelPopup;
    
};