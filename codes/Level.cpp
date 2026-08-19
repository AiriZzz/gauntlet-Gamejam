#include "Level.hpp"

Level::Level(const LevelData& levelData) 
: m_zones(levelData.zonePosition, levelData.zoneSize, levelData.solution){

    m_levelPopup = LoadTexture("codes/Images/Level1.png");
    for (const UnitData& unitData : levelData.units)
    {
        m_units.push_back(std::make_unique<Unit>(unitData.name, unitData.color, unitData.position, unitData.size, unitData.type));
    }
}


void Level::Update(){

    Vector2 mousePosition = GetMousePosition(); //get the position of mouse

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        std::cout << mousePosition.x << " " << mousePosition.y << "\n" ;
        for (int i = m_units.size() - 1; i >= 0; i--) //check for unit inside units, backwards
        {
            if (m_units[i]->IsMouseOver(mousePosition)) //found the unit that overlaps with mouse
            {
                m_draggingUnit = m_units[i].get();
                m_draggingUnit->StartDragging(mousePosition); //start draggin the unit that the mouse found

                break; //stop checking when dragging starts
            }

        }
    }

        if (m_draggingUnit != nullptr) //if unit is being dragged
    {
        m_draggingUnit->UpdateDragging(mousePosition); //update position to mouse posiiton
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        if (m_draggingUnit != nullptr)
        {
            Unit* releasedUnit = m_draggingUnit;
            if (m_zones.ContainUnit(releasedUnit) && !m_zones.HasUnit(releasedUnit))
            {
                m_zones.AddingUnit(releasedUnit);
            } //Check if the zone contain unit and if it doesn't has the unit, then add into a vector
    
            m_draggingUnit->StopDragging();//stops dragging the unit
            m_zones.HandleDrop(releasedUnit,mousePosition.x);//UnitZone handle what to do with the Unit
            m_draggingUnit = nullptr; //reset what unit is being drag.

            m_draggingUnit = nullptr;
        }
    }

    Rectangle checkButton{
    1020, 500,
    150, 50
    };

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        if (CheckCollisionPointRec(mousePosition,checkButton))
        {
            if(m_zones.isPuzzleSolved()) m_puzzleSolved = true;
        }
        
    }

}

void Level::Draw(){

    Vector2 mousePosition = GetMousePosition();
    DrawText("UNIT ZONE", 190, 200, 20, BLACK);
    
    bool isDraggin = m_draggingUnit != nullptr;
    m_zones.Draw(mousePosition, isDraggin); //Draw the zones where the unit can be ordered.
    
    for (const auto& unit : m_units) unit->Draw();     //Draw unit from vector
    
    if (m_puzzleSolved){
        DrawText("PUZZLE SOLVED!",880,100,30,GREEN);

        DrawText("Great job!",830,140,20,DARKGREEN);
    } //When puzzle is solved, write a simple text

    DrawTextureEx(
        m_levelPopup,
        {120,80}, 0, 0.4,
        WHITE
    ); //Draw Image texture

    Rectangle checkButton{
    1020, 500,
    150, 50
    };

    DrawRectangleRec(
    checkButton,
    ORANGE
    );

    DrawText(
    "CHECK",
    1060, 615, 20,
    BLACK
    ); //Adding a check button for the solution to be checked
}