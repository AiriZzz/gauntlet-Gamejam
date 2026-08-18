#include "raylib.h"
#include "codes/Level.hpp"
#include "codes/Level1.hpp"
#include <vector>

//Settings

int main(void)
{
    InitWindow(1366, 768, "March Forward!! I think?");
    SetTargetFPS(144);

    LevelData levelData = CreateLevel1(); //store the data of createlevel1 to the leveldata
    Level level(levelData); //load the level with the level data


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