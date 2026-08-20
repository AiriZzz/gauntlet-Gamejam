#include "Level1.hpp"

LevelData CreateLevel1(){

    LevelData level;

    level.units = {
        {
           "Firefighter", RED, {280, 550}, {180, 180},  UnitType::Firefighter, "codes/Images/Unit/Unit1.png"
        },

    };

    level.solution = {
        UnitType::Firefighter,
    };

    level.LevelPopup = "codes/Images/Levels/Level1.png";

    return level;

}