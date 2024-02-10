//INFINITE TERRAIN
#include <iostream>
#include <raylib.h>
#include "tiles.hpp"
using namespace std;

Tile::Tile()
{
    //Setup properties
    scale = 4;
    spritesheet.texture = LoadTexture("Images/tiles.png");

    //Grid generation
    for(int i = 0; i < 380; i++)
    {
        tile_data.clone_x[i] = i%20;
        tile_data.clone_y[i] = i/20;
    }
}

void Tile::Draw(int id)
{
    fixed_pos = GetFixedTilePosition(id);
    id_x = (int)fixed_pos.x / (scale * 16);
    id_y = (int)fixed_pos.y / (scale * 16);

    SpritesheetUpdate(fixed_pos);

    DrawTexturePro(spritesheet.texture, spritesheet.source, spritesheet.dest, spritesheet.origin, 0, WHITE);
    DrawText(TextFormat("%d", id_x), fixed_pos.x - (scale / 2) * 16, fixed_pos.y - (scale / 2) * 16, 30, RED);
    DrawText(TextFormat("%d", id_y), fixed_pos.x - (scale / 2) * 16, fixed_pos.y, 30, BLUE);
}

void Tile::Update(int id, Vector2 camera)
{
    fixed_pos = GetFixedTilePosition(id);

    if(camera.x - fixed_pos.x > 736 && tile_data.clone_x[id] + 20 < MAP_SIZE_X) tile_data.clone_x[id] += 20;
    if(camera.x - fixed_pos.x < -736) tile_data.clone_x[id] -= 20;
    if(camera.y - fixed_pos.y > 704) tile_data.clone_y[id] += 19;
    if(camera.y - fixed_pos.y < -704) tile_data.clone_y[id] -= 19;
}

void Tile::SpritesheetUpdate(Vector2 position)
{
    spritesheet.source = Rectangle{0, 0, TILE_SIZE, TILE_SIZE};
    spritesheet.dest = Rectangle{position.x, position.y, spritesheet.source.width * scale, spritesheet.source.height * scale};
    spritesheet.origin = Vector2{spritesheet.dest.width / 2, spritesheet.dest.height / 2};
}

Vector2 Tile::GetFixedTilePosition(int id) {return Vector2{map_data[tile_data.clone_y[id]].x[tile_data.clone_x[id]], map_data[tile_data.clone_y[id]].y};}
