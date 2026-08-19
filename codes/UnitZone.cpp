#include "UnitZone.hpp"

void UnitZone::Draw() const {

    Color zoneColor = LIGHTGRAY;

    DrawRectangleLines(
        m_position.x, m_position.y,
        m_size.x, m_size.y,
        zoneColor
    );
}

void UnitZone::AddingUnit(Unit* unit){

    m_units.push_back(unit); // Add drawned unit in array

    UpdateSize(); //After adding, then calculate the zone size
    ArrangeUnits(); //Arrange the unit after adding in
}

void UnitZone::RemoveUnit(Unit* unit){

    auto it = std::find(m_units.begin(), m_units.end(), unit);

    if (it != m_units.end()) {
        m_units.erase(it);

        UpdateSize();
        ArrangeUnits();
    }
}

bool UnitZone::ContainUnit(Unit* unit) const{

    Vector2 unitPosition = unit->GetPosition();
    Vector2 unitSize = unit->GetSize();

    Rectangle unitRect{ 
        unitPosition.x,unitPosition.y
        ,unitSize.x,unitSize.y};

    Rectangle zoneRect{
        m_position.x, m_position.y
        ,m_size.x, m_size.y};

    
    return CheckCollisionRecs(zoneRect, unitRect);    
} //checking if the unit is being inside the zone

bool UnitZone::HasUnit(Unit* unit) const{

    for (Unit* existingUnit : m_units)
        if (existingUnit == unit) return true;
    
    return false;
} //Checking if a unit is already being added in zone via vector

void UnitZone::ArrangeUnits(){

    UpdateSize(); //Update zone size first before arraging the units

    float currentX = m_position.x + m_unitSpaces;
    float currentY = m_position.y + m_unitSpaces;

    for (Unit* unit : m_units){
            
        unit->SetPosition({currentX,currentY});

        currentX += unit->GetSize().x + m_unitSpaces;
    }
}//sets the position of the unit inside the zones

void UnitZone::UpdateSize(){

    float zoneWidth = m_unitSpaces;

    for (Unit* unit : m_units)
    {
        zoneWidth += unit->GetSize().x;
        zoneWidth += m_unitSpaces;
    }

    //if(zoneWidth > m_minWidth) m_size.x = zoneWidth; //check if the zone Width will get bigger than the default width
    m_size.x = std::max(m_minWidth, zoneWidth); //always calculate the width of the zone width.

} //This calculate the width of the zone, for every units inside it, it expands

void UnitZone::ReorderUnits(Unit* unit, float mouseX){

    auto it = std::find(m_units.begin(),m_units.end(), unit);

    if (it == m_units.end()) return; //return the end of vector

    m_units.erase(it); //must temporary erase the element inside the vector
    int insertIndex = 0;
    
        for (Unit* otherUnit : m_units)
    {
        float unitCenterX =
            otherUnit->GetPosition().x +
            otherUnit->GetSize().x / 2.0f;

        if (mouseX > unitCenterX) //compare the mouse position center where
        {
            insertIndex++;
        }
        else
        {
            break;
        }
    } // re arragement happens here

    m_units.insert(m_units.begin() + insertIndex, unit); //push on the vector array

    ArrangeUnits();
} //This method is for rearranging the unit inside the zones when picking up a unit

void UnitZone::HandleDrop(Unit* unit, float mouseX){

    if (HasUnit(unit)) //if found unit is in vector
    {
        if (ContainUnit(unit)) ReorderUnits(unit, mouseX); //reoder the unit if the unit is inside the zone
        else ArrangeUnits(); 

        return;
    }

    if (ContainUnit(unit)) AddingUnit(unit); //add the unit if its not in the vector
}//Handles the drop of unit on different situation