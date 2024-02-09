#include <iostream>
#include <raylib.h>
#include "tiles.hpp"
using namespace std;

#define TILE_SIZE 16


Tile::Tile()
{
    scale = 4;

    for(int i = 0; i < 240; i++)
    {
        tile_data.clone_x[i] = i%16;
        tile_data.clone_y[i] = i/16;
    }
}

void Tile::Draw(int id)
{
    fixed_x = map_data[tile_data.clone_y[id]].x[tile_data.clone_x[id]];
    fixed_y = map_data[tile_data.clone_y[id]].y;
    id_x = (int)fixed_x / 64;
    id_y = (int)fixed_y / 64;
    DrawRectangle(fixed_x, fixed_y, TILE_SIZE * scale, TILE_SIZE * scale, GREEN);
    DrawText(TextFormat("%d", id_x), fixed_x, fixed_y, 30, RED);
    DrawText(TextFormat("%d", id_y), fixed_x, fixed_y + 32, 30, BLUE);
}
