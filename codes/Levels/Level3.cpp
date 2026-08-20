#include "Level3.hpp"

LevelData CreateLevel3(){

    LevelData level;

    level.units = {
        
        {
           "Police", DARKBLUE, {350, 540}, {180, 180},  UnitType::Police, "codes/Images/Unit/Unit2.png"
        },

        {
           "Firefighter", RED, {450, 540}, {180, 180},  UnitType::Firefighter, "codes/Images/Unit/Unit1.png"
        },
        
        {
           "Army", DARKGREEN, {550, 540}, {180, 180},  UnitType::Soldier, "codes/Images/Unit/Unit3.png"
        },

    };

    level.solution = {
        UnitType::Soldier,
        UnitType::Firefighter,
        UnitType::Police,

    };

    level.LevelPopup = "codes/Images/Levels/Level3.png";

    return level;

}