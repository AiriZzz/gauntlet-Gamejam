#include "raylib.h"
#include "codes/unit.hpp"

int main(void)
{
    InitWindow(1366, 768, "March Forward!! I think?");
    SetTargetFPS(144);

    Unit fire("Firefighter", RED,{100,50},{80,80});

    while (!WindowShouldClose())
    {

        BeginDrawing();
            fire.Update();
            ClearBackground(RAYWHITE);
            DrawText("FIREEEEEE", 190, 200, 20, RED);
            fire.Draw();
            
        EndDrawing();
    }

    CloseWindow();

    return 0;
}