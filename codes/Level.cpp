#include "Level.hpp"

Level::Level(const LevelData& levelData) 
: m_unitZones ({390, 790}, {400, 250}), 
    m_marchingZones({850, 430}, {1000, 300}, levelData.solution){

    m_levelPopup = LoadTexture(levelData.LevelPopup.c_str());
    
    for (const UnitData& unitData : levelData.units)
    {
        m_units.push_back(std::make_unique<Unit>(unitData.name, unitData.color, unitData.position, unitData.size, unitData.type, unitData.texturePath));

        m_unitZones.AddingUnit(m_units.back().get());
    }
}

Level::~Level(){

    UnloadTexture(m_levelPopup);
}

void Level::Update(){

    Vector2 mousePosition = GetMousePosition(); //get the position of mouse

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        std::cout << mousePosition.x << " " << mousePosition.y << "\n" ; //JUST MOUSE COORDINATION
        
        for (int i = m_units.size() - 1; i >= 0; i--) //check for unit inside units, backwards
        {
            if (m_units[i]->IsMouseOver(mousePosition)) //found the unit that overlaps with mouse
            {
                m_draggingUnit = m_units[i].get();

                if(m_unitZones.HasUnit(m_draggingUnit))
                {
                    m_draggedUnitZone = true;
                }
                else m_draggedUnitZone = false;

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

            releasedUnit->StopDragging(); 

            if (m_marchingZones.ContainUnit(releasedUnit)) //check the marching zone contain unit
            {
                if(m_draggedUnitZone){

                    m_unitZones.RemoveUnit(releasedUnit);
                }

                m_marchingZones.HandleDrop(releasedUnit, mousePosition.x); //deal where the drop happens
            }
             
            else if (m_unitZones.ContainUnit(releasedUnit)) //check the unitzone contain unit
            {
                if(!m_draggedUnitZone){
                    
                    m_marchingZones.RemoveUnit(releasedUnit);
                }
 
                m_unitZones.HandleDrop(releasedUnit, mousePosition.x); //deal where the drop happens
            }
    

            m_draggingUnit = nullptr;   //reset what unit is being drag.
        }
    }
    
    Rectangle checkButton{
    1400, 830,
    400, 200
    };

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        if (CheckCollisionPointRec(mousePosition,checkButton))
        {
            if(m_marchingZones.isPuzzleSolved()) m_puzzleSolved = true;
        }
        
    }

}

void Level::Draw(){

    Vector2 mousePosition = GetMousePosition();
    //DrawText("UNIT ZONE", 190, 200, 20, BLACK);
    
    bool isDraggin = m_draggingUnit != nullptr;
    m_marchingZones.Draw(mousePosition, isDraggin); //Draw the Marching zones

    m_unitZones.Draw(); //Draw the Unit Zones
    
    for (const auto& unit : m_units) unit->Draw();     //Draw unit from vector

    DrawTextureEx(
        m_levelPopup,
        {65,90}, 0, 0.5,
        WHITE
    ); //Draw Image texture

}

bool Level::CheckPuzzle(){

    return m_puzzleSolved;
}