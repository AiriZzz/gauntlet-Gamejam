#include "unitZone.hpp"

void UnitZone::Draw(){

    DrawRectangleLines(
        static_cast<int>(m_position.x),
        static_cast<int>(m_position.y),
        static_cast<int>(m_size.x),
        static_cast<int>(m_size.y),
        DARKGRAY
    );
}

void UnitZone::AddingUnit(Unit* unit){

    m_units.push_back(unit);
}