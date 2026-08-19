#include "Level2.hpp"

LevelData CreateLevel2(){

    LevelData level;

    level.units = {
        {
           "Firefighter", RED, {350, 540}, {80, 80},  UnitType::Firefighter
        },

        {
           "Police", DARKBLUE, {450, 540}, {80, 80},  UnitType::Police
        },

    };

    level.solution = {
        UnitType::Police,
        UnitType::Firefighter
    };

    return level;

}