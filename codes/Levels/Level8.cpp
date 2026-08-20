#include "Level8.hpp"

LevelData CreateLevel8(){

    LevelData level;

    level.units = {
                
        {
           "ARTIST", DARKPURPLE, {350, 540}, {180, 180},  UnitType::Artist, "codes/Images/Unit/Unit5.png"
        },
        
        {
           "Firefighter", RED, {450, 540}, {180, 180},  UnitType::Firefighter, "codes/Images/Unit/Unit1.png"
        },

        {
           "GHOST", DARKGRAY, {550, 540}, {180, 180},  UnitType::Ghost, "codes/Images/Unit/Unit4.png"
        },

        {
           "Police", DARKBLUE, {650, 540}, {180, 180},  UnitType::Police, "codes/Images/Unit/Unit2.png"
        },

        {
           "Army", DARKGREEN, {750, 540}, {180, 180},  UnitType::Soldier, "codes/Images/Unit/Unit3.png"
        },

    };

    level.solution = {
        UnitType::Artist,
        UnitType::Police,
        UnitType::Ghost,
        UnitType::Firefighter,
        UnitType::Soldier,

    };

    level.LevelPopup = "codes/Images/Levels/Level8.png";

    return level;

}