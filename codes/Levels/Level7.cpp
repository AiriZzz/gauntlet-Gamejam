#include "Level7.hpp"

LevelData CreateLevel7(){

    LevelData level;

    level.units = {
        {
           "Firefighter", RED, {350, 540}, {180, 180},  UnitType::Firefighter, "codes/Images/Unit/Unit1.png"
        },

        {
           "Police", DARKBLUE, {450, 540}, {180, 180},  UnitType::Police, "codes/Images/Unit/Unit2.png"
        },

        {
           "Army", DARKGREEN, {550, 540}, {180, 180},  UnitType::Soldier, "codes/Images/Unit/Unit3.png"
        },

        {
           "GHOST", DARKGRAY, {650, 540}, {180, 180},  UnitType::Ghost, "codes/Images/Unit/Unit4.png"
        },

        {
           "ARTIST", DARKPURPLE, {750, 540}, {180, 180},  UnitType::Artist, "codes/Images/Unit/Unit5.png"
        },

    };

    level.solution = {
        UnitType::Artist,
        UnitType::Firefighter,
        UnitType::Ghost,
        UnitType::Police,
        UnitType::Soldier,

    };

    level.LevelPopup = "codes/Images/Levels/Level7.png";

    return level;

}