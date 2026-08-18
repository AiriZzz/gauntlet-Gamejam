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

    UpdateSize(); //After adding, then calculate the zone size
    ArrangeUnits(); //Arrange the unit after adding in
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

void UnitZone::ArrangeUnits(){

    float currentX = m_position.x + m_unitSpaces;
    float currentY = m_position.y + m_unitSpaces;

    for (Unit* unit : m_units){
            
        unit->SetPosition({currentX,currentY});

        currentX += unit->GetSize().x + m_unitSpaces;
    }
}

void UnitZone::UpdateSize(){

    float zoneWidth = m_unitSpaces;

    for (Unit* unit : m_units)
    {
        zoneWidth += unit->GetSize().x;
        zoneWidth += m_unitSpaces;
    }

    if(zoneWidth > m_minWidth) m_size.x = zoneWidth; //check if the zone Width will get bigger than the default width
} //This calculate the width of the zone, for every units inside it, it expands