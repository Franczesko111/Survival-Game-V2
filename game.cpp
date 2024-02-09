#include <raylib.h>
#include "game.hpp"

Game::Game()
{
    camera.target = player.GetPlayerPosition();
    camera.offset = Vector2{(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2};
    camera.rotation = 0;
    camera.zoom = 1;

    for(int iy = 0; iy < 15; iy++)
    {
        tile.map_data[iy].y = iy * 64;
        for(int ix = 0; ix < 16; ix++)
        {
            tile.map_data[iy].x[ix] = ix * 64;
            tile.map_data[iy].type[ix] = 0;
        }
    }
}

void Game::Draw()
{
    BeginMode2D(camera);

    player.Draw();

    EndMode2D();
}

void Game::Update()
{
    for(int i = 0; i < 240; i++) tile.Draw(i);
    player.Update();
    //camera.target = player.GetPlayerPosition();
}
