#include "Level.hpp"

Level::Level() : m_zones(
        {200, 300},
        {400, 150},
        {
            //The Solution
            UnitType::Firefighter,
            UnitType::Police,
            UnitType::Ghost
        }) {

    //UNIT CLASS
    m_units.push_back(
    std::make_unique<Unit>("Firefighters", RED, Vector2{100, 540}, Vector2{80, 80}, UnitType::Firefighter));
    m_units.push_back(
    std::make_unique<Unit>("Polices", DARKBLUE, Vector2{200, 540}, Vector2{80, 80}, UnitType::Police));
    m_units.push_back(
    std::make_unique<Unit>("Soldiers", DARKGREEN, Vector2{300, 540}, Vector2{80, 80}, UnitType::Soldier));
    m_units.push_back(
    std::make_unique<Unit>("Ghosts", DARKGRAY, Vector2{400, 540}, Vector2{80, 80}, UnitType::Ghost));
    m_units.push_back(
    std::make_unique<Unit>("Animals", DARKBROWN, Vector2{500, 540}, Vector2{80, 80}, UnitType::Animal));
}

void Level::Update(){

    Vector2 mousePosition = GetMousePosition(); //get the position of mouse

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        //std::cout << mousePosition.x << " " << mousePosition.y << "\n" ;
        for (int i = m_units.size() - 1; i >= 0; i--) //check for unit inside units, backwards
        {
            if (m_units[i]->IsMouseOver(mousePosition)) //found the unit that overlaps with mouse
            {
                m_draggingUnit = i;
                m_units[i]->StartDragging(mousePosition); //start draggin the unit that the mouse found

                break; //stop checking when dragging starts
            }

        }
    }

        if (m_draggingUnit != -1) //if unit is being dragged
    {
        m_units[m_draggingUnit]->UpdateDragging(mousePosition); //update position to mouse posiiton
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        if (m_draggingUnit != -1)
        {
            Unit* releasedUnit = m_units[m_draggingUnit].get();
            if (m_zones.ContainUnit(releasedUnit) && !m_zones.HasUnit(releasedUnit))
            {
                m_zones.AddingUnit(releasedUnit);
            } //Check if the zone contain unit and if it doesn't has the unit, then add into a vector
    
            m_units[m_draggingUnit]->StopDragging();//stops dragging the unit
            m_zones.HandleDrop(releasedUnit,mousePosition.x);//UnitZone handle what to do with the Unit
            m_draggingUnit = -1; //reset what unit is being drag.

            
            if (m_zones.isPuzzleSolved()){
                //std::cout << "Puzzle Solved!" << std::endl;
                m_puzzleSolved = true;
            }

            m_draggingUnit = -1;
        }
    }
}

void Level::Draw(){

    Vector2 mousePosition = GetMousePosition();
    DrawText("UNIT ZONE", 190, 200, 20, BLACK);
    
    m_zones.Draw(mousePosition); //Draw the zones where the unit can be ordered.
    
    for (const auto& unit : m_units) unit->Draw();     //Draw unit from vector
    if (m_puzzleSolved){
        DrawText("PUZZLE SOLVED!",280,100,30,GREEN);

        DrawText("Great job!",330,140,20,DARKGREEN);
    }
}