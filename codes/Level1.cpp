#include "Level1.hpp"

LevelData CreateLevel1(){

    LevelData level;

    level.units = {
        {
           "Firefighter", RED, {350, 540}, {80, 80},  UnitType::Firefighter
        },

    };

    level.solution = {
        UnitType::Firefighter,
    };

    level.zonePosition = {840, 300};
    level.zoneSize = {400, 150};

    return level;

}