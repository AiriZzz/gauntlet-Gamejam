#include "Level4.hpp"

LevelData CreateLevel4(){

    LevelData level;

    level.units = {
        
        {
           "Army", DARKGREEN, {350, 540}, {180, 180},  UnitType::Soldier, "codes/Images/Unit/Unit3.png"
        },
        
        {
           "Firefighter", RED, {450, 540}, {180, 180},  UnitType::Firefighter, "codes/Images/Unit/Unit1.png"
        },

        {
           "Police", DARKBLUE, {550, 540}, {180, 180},  UnitType::Police, "codes/Images/Unit/Unit2.png"
        },

    };

    level.solution = {
        
        UnitType::Firefighter,
        UnitType::Soldier,
        UnitType::Police,

    };

    level.LevelPopup = "codes/Images/Levels/Level4.png";

    return level;

}