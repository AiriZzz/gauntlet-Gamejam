#include "Level6.hpp"

LevelData CreateLevel6(){

    LevelData level;

    level.units = {
        {
           "Firefighter", RED, {350, 540}, {180, 180},  UnitType::Firefighter, "codes/Images/Unit/Unit1.png"
        },

        {
           "Army", DARKGREEN, {450, 540}, {180, 180},  UnitType::Soldier, "codes/Images/Unit/Unit3.png"
        },

        {
           "Police", DARKBLUE, {550, 540}, {180, 180},  UnitType::Police, "codes/Images/Unit/Unit2.png"
        },

        {
           "GHOST", DARKGRAY, {650, 540}, {180, 180},  UnitType::Ghost, "codes/Images/Unit/Unit4.png"
        },

    };

    level.solution = {
        UnitType::Firefighter,
        UnitType::Police,
        UnitType::Soldier,
        UnitType::Ghost,

    };

    level.LevelPopup = "codes/Images/Levels/Level6.png";

    return level;

}