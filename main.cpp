#include <raylib.h>
#include "game.h"

//Configuration variables
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 960;
const int GAME_FPS = 60;
const char* GAME_TITLE = "Survival Game Test - V2";

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
    SetTargetFPS(GAME_FPS);

    Game game;

    while(WindowShouldClose() == false)
    {
        BeginDrawing();

        game.Update();

        ClearBackground(LIGHTGRAY);

        game.Draw();
        DrawFPS(0, 0);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
