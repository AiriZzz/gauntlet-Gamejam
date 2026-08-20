#include "raylib.h"
#include "codes/Level.hpp"
#include "codes/LevelManager.hpp"
#include <vector>

//Settings

int main(void)
{
    InitWindow(1920, 1080, "Will it Parade?");
    SetTargetFPS(144);

    InitAudioDevice();
    
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