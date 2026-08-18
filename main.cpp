#include "raylib.h"
#include "codes/unit.hpp"
#include "codes/unitZone.hpp"
#include <vector>

//Settings

int main(void)
{
    InitWindow(1366, 768, "March Forward!! I think?");
    SetTargetFPS(144);

    //Units
    std::vector<Unit> units;

    //UNIT CLASS
    Unit firefighter("Firefighters", RED,{100,50},{80,80}, UnitType::Firefighter);
    Unit police("Polices", DARKBLUE, {200,50}, {80,80}, UnitType::Police);
    Unit soldier("Soldiers", DARKGREEN, {300,50}, {80,80}, UnitType::Soldier);
    Unit ghost("Ghost", DARKGRAY, {400,50},{80,80}, UnitType::Ghost);
    Unit animal("Animals", DARKBROWN, {500,50} , {80,80}, UnitType::Animal);

    units.push_back(firefighter);
    units.push_back(police);
    units.push_back(soldier);
    units.push_back(ghost);
    units.push_back(animal);

    //ZONES sOLUTION
    std::vector<UnitType> solution{UnitType::Police, UnitType::Firefighter, UnitType::Ghost};

    //UNIT ZONE CLASS
    UnitZone zones({200, 300}, {400, 150}, solution);

    int draggingUnit = -1; //Default no unit is being selected

    while (!WindowShouldClose())
    {  

        Vector2 mousePosition = GetMousePosition(); //get the position of mouse

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            for (int i = units.size() - 1; i >= 0; i--) //check for unit inside units, backwards
            {
                if (units[i].IsMouseOver(mousePosition)) //found the unit that overlaps with mouse
                {
                    draggingUnit = i;
                    units[i].StartDragging(mousePosition); //start draggin the unit that the mouse found

                    break; //stop checking when dragging starts
                }

            }
        }

        if (draggingUnit != -1) //if unit is being dragged
        {
            units[draggingUnit].UpdateDragging(mousePosition); //update position to mouse posiiton
        }

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            if (draggingUnit != -1)
            {
                Unit* releasedUnit = &units[draggingUnit];
                if (zones.ContainUnit(releasedUnit) && !zones.HasUnit(releasedUnit))
                {
                    zones.AddingUnit(releasedUnit);
                } //Check if the zone contain unit and if it doesn't has the unit, then add into a vector
        
                units[draggingUnit].StopDragging();//stops dragging the unit
                zones.HandleDrop(releasedUnit,mousePosition.x);//UnitZone handle what to do with the Unit
                draggingUnit = -1; //reset what unit is being drag.
            }
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawText("UNIT ZONE", 190, 200, 20, BLACK);
            zones.Draw(mousePosition); //Draw the zones where the unit can be ordered.
            for (Unit& unit : units) unit.Draw();     //Draw unit from vector
            
        EndDrawing();
    }

    CloseWindow();

    return 0;
}