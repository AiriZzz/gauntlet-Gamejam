#pragma once

#include "LevelData.hpp"

LevelData CreateLevel1(){

    LevelData level;

    level.units = {
        {
           "Firefighter", RED, {100, 540}, {80, 80},  UnitType::Firefighter
        },

        {
            "Polices", DARKBLUE, Vector2{200, 540}, Vector2{80, 80}, UnitType::Police
        },

        {
            "Soldiers", DARKGREEN, Vector2{300, 540}, Vector2{80, 80}, UnitType::Soldier
        },

        {
            "Ghosts", DARKGRAY, Vector2{400, 540}, Vector2{80, 80}, UnitType::Ghost
        },

        {
            "Animals", DARKBROWN, Vector2{500, 540}, Vector2{80, 80}, UnitType::Animal
        },


    };

    level.solution = {
        UnitType::Police,
        UnitType::Firefighter,
    };

    level.zonePosition = {200, 300};
    level.zoneSize = {400, 150};

    return level;

}