#include "raylib.h"
#include "codes/Level.hpp"
#include "codes/Level1.hpp"
#include "codes/LevelManager.hpp"
#include <vector>

//Settings

int main(void)
{
    InitWindow(1366, 768, "Will it Parade?");
    SetTargetFPS(144);

    LevelManager levelManager;


    while (!WindowShouldClose())
    {  
        levelManager.Update();
        BeginDrawing();

            ClearBackground(RAYWHITE);

        levelManager.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}