#include "unitZone.hpp"

void UnitZone::Draw(){

    DrawRectangleLines(
        m_position.x,
        m_position.y,
        m_size.x,
        m_size.y,
        DARKGRAY
    );
}

void UnitZone::AddingUnit(Unit* unit){

    m_units.push_back(unit); // Add drawned unit in array
}

bool UnitZone::ContainUnit(Unit* unit){

    Vector2 unitPosition = unit->GetPosition();
    Vector2 unitSize = unit->GetSize();

    Rectangle unitRect{ 
        unitPosition.x,unitPosition.y
        ,unitSize.x,unitSize.y};

    Rectangle zoneRect{
        m_position.x, m_position.y
        ,m_size.x, m_size.y};

    
    return CheckCollisionRecs(zoneRect, unitRect);    
}

bool UnitZone::HasUnit(Unit* unit){

    for (Unit* existingUnit : m_units)
        if (existingUnit == unit) return true;
    
    return false;
} //Checking if a unit is already being contained in zone

