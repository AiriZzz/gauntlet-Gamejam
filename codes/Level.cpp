#include "codes/Level.hpp"

Level::Level() : m_zone(
        {200, 300},
        {400, 150},
        {
            UnitType::Firefighter,
            UnitType::Police,
            UnitType::Ghost
        }
    ) {}