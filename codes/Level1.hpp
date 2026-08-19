#pragma once

#include "LevelData.hpp"

LevelData CreateLevel1(){

    LevelData level;

    level.units = {
        {
           "Firefighter", RED, {820, 540}, {80, 80},  UnitType::Firefighter
        },

        {
            "Polices", DARKBLUE, Vector2{920, 540}, Vector2{80, 80}, UnitType::Police
        },

        {
            "Soldiers", DARKGREEN, Vector2{1020, 540}, Vector2{80, 80}, UnitType::Soldier
        },

        {
            "Ghosts", DARKGRAY, Vector2{1120, 540}, Vector2{80, 80}, UnitType::Ghost
        },

        {
            "Animals", DARKBROWN, Vector2{1220, 540}, Vector2{80, 80}, UnitType::Animal
        },


    };

    level.solution = {
        UnitType::Police,
        UnitType::Firefighter,
    };

    level.zonePosition = {840, 300};
    level.zoneSize = {400, 150};

    return level;

}