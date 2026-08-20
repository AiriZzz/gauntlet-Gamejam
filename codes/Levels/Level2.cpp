#include "Level2.hpp"

LevelData CreateLevel2(){

    LevelData level;

    level.units = {
        {
           "Firefighter", RED, {350, 540}, {180, 180},  UnitType::Firefighter, "codes/Images/Unit/Unit1.png"
        },

        {
           "Police", DARKBLUE, {450, 540}, {180, 180},  UnitType::Police, "codes/Images/Unit/Unit2.png"
        },

    };

    level.solution = {
        UnitType::Police,
        UnitType::Firefighter
    };

    level.LevelPopup = "codes/Images/Levels/Level2.png";

    return level;

}