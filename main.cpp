#include "raylib.h"
#include "codes/Level.hpp"
#include <vector>

//Settings

int main(void)
{
    InitWindow(1366, 768, "March Forward!! I think?");
    SetTargetFPS(144);

    Level level;


    while (!WindowShouldClose())
    {  
        level.Update();
        BeginDrawing();

            ClearBackground(RAYWHITE);

        level.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}