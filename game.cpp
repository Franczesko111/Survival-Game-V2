#include <iostream>
#include <raylib.h>
#include "game.hpp"

Game::Game()
{
    //Calculate out of bounds code to offset the camera
    bounds_limit_x = ((MAP_SIZE_X - 16) * 64) + 512;
    bounds_limit_y = ((MAP_SIZE_Y - 15) * 64) + 480;

    //Add Camera (+ set properties)
    camera.target = player.GetPlayerPosition();
    camera.offset = Vector2{(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2};
    camera.rotation = 0;
    camera.zoom = 1;

    //Create Map
    for(int iy = 0; iy < MAP_SIZE_Y; iy++)
    {
        tile.map_data[iy].y = iy * 64 + 32;
        for(int ix = 0; ix < MAP_SIZE_X; ix++)
        {
            tile.map_data[iy].x[ix] = ix * 64 + 32;
            tile.map_data[iy].type[ix] = 0;
        }
    }
}

void Game::Draw()
{
    BeginMode2D(camera);

    for(int i = 0; i < 380; i++) tile.Draw(i);
    player.Draw();

    EndMode2D();

    inventory.Draw();
}

void Game::Update()
{
    for(int i = 0; i < 380; i++) tile.Update(i, camera.target);
    player.Update();
    camera.target = player.GetPlayerPosition();
    UpdateCameraOutOfBounds();
}

void Game::UpdateCameraOutOfBounds()
{
    if(camera.target.x < 512) camera.target.x = 512;
    if(camera.target.x > bounds_limit_x) camera.target.x = bounds_limit_x;
    if(camera.target.y < 480) camera.target.y = 480;
    if(camera.target.y > bounds_limit_y) camera.target.y = bounds_limit_y;
}
