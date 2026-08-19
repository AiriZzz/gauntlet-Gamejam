#include "Level1.hpp"

LevelData CreateLevel1(){

    LevelData level;

    level.units = {
        {
           "Firefighter", RED, {280, 550}, {80, 80},  UnitType::Firefighter
        },

    };

    level.solution = {
        UnitType::Firefighter,
    };

    return level;

}