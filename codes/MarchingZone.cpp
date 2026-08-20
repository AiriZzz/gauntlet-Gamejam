#include "MarchingZone.hpp"

void MarchingZone::Draw(Vector2 mousePosition, bool isDragging)const{

    Rectangle zoneRect{
        m_position.x,m_position.y,
        m_size.x, m_size.y,};

    Color zoneColor = BLANK;

        if ( isDragging || CheckCollisionPointRec(mousePosition, zoneRect))
    {
        zoneColor = BLANK;
    } //Change the color of the zone into blue if dragging unit and hovering on top of the zone

    DrawRectangleLines(
        m_position.x, m_position.y,
        m_size.x, m_size.y,
        zoneColor
    );
}

void MarchingZone::AddingUnit(Unit* unit){

    m_units.push_back(unit); // Add drawned unit in array

    UpdateSize(); //After adding, then calculate the zone size
    ArrangeUnits(); //Arrange the unit after adding in
}

void MarchingZone::RemoveUnit(Unit* unit){

    auto it = std::find(m_units.begin(), m_units.end(), unit);

    if (it != m_units.end()) {
        m_units.erase(it);

        UpdateSize();
        ArrangeUnits();
    }
}

bool MarchingZone::ContainUnit(Unit* unit) const{

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

bool MarchingZone::HasUnit(Unit* unit) const{

    for (Unit* existingUnit : m_units)
        if (existingUnit == unit) return true;
    
    return false;
} //Checking if a unit is already being added in zone via vector

void MarchingZone::ArrangeUnits(){

    UpdateSize(); //Update zone size first before arraging the units

    float currentX = m_position.x + m_unitSpaces;
    float currentY = m_position.y + (m_size.y/2) - 50; //hard coded to make Unit be at the centre of y of the marching zone

    for (Unit* unit : m_units){
            
        unit->SetPosition({currentX,currentY});

        currentX += unit->GetSize().x + m_unitSpaces;
    }
}//sets the position of the unit inside the zones

void MarchingZone::UpdateSize(){

    float zoneWidth = m_unitSpaces;

    for (Unit* unit : m_units)
    {
        zoneWidth += unit->GetSize().x;
        zoneWidth += m_unitSpaces;
    }

    //if(zoneWidth > m_minWidth) m_size.x = zoneWidth; //check if the zone Width will get bigger than the default width
    m_size.x = std::max(m_minWidth, zoneWidth); //always calculate the width of the zone width.

} //This calculate the width of the zone, for every units inside it, it expands

void MarchingZone::ReorderUnits(Unit* unit, float mouseX){

    auto it = std::find(m_units.begin(),m_units.end(), unit);

    if (it == m_units.end()) return; //return the end of vector

    m_units.erase(it); //must temporary erase the element inside the vector
    int insertIndex = 0;
    
        for (Unit* otherUnit : m_units)
    {
        float unitCenterX =
            otherUnit->GetPosition().x +
            otherUnit->GetSize().x / 2.0f;

        if (mouseX > unitCenterX) //compare the mouse position center unit
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
} //This method is for ordering the unit inside the zones when picking up a unit

void MarchingZone::HandleDrop(Unit* unit, float mouseX){

    if (HasUnit(unit)) //if found unit is in vector
    {
        if (ContainUnit(unit)) ReorderUnits(unit, mouseX); //reoder the unit if the unit is inside the zone
        else ArrangeUnits(); 

        return;
    }

    if (ContainUnit(unit)) AddingUnit(unit); //add the unit if its not in the vector
}//Handles the drop of unit on different situation

bool MarchingZone::IsMouseOver(Vector2 mousePosition) const{
    Rectangle zoneRect{
        m_position.x,m_position.y,
        m_size.x,m_size.y};

    return CheckCollisionPointRec(mousePosition, zoneRect);
}

bool MarchingZone::isPuzzleSolved() const{

    if(m_units.size() != m_puzzleSolution.size()) return false; //if the zone vector is not the same with solution vector

    for(std::size_t i = 0; i < m_units.size(); i++) //if the size same
    {
        if (m_units[i]->GetType() != m_puzzleSolution[i]) return false; //check if the the vector same as solution
    }

    return true;
} //Check if the Puzzle is solved or not