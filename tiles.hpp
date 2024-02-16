#pragma once
#include <raylib.h>
#include "data.hpp"

typedef struct TILE_DATA
{
    int clone_x[380];
    int clone_y[380];
} TILE_DATA;

typedef struct MAP_DATA
{
    int type[MAP_SIZE_X];
    float x[MAP_SIZE_X];
    float y;
} MAP_DATA;

typedef struct TILE_SPRITESHEET
{
    Texture2D texture;
    Rectangle source;
    Rectangle dest;
    Vector2 origin;
} TILE_SPRITESHEET;

class Tile
{
    public:
        Tile();
        void Draw(int id);
        void Update(int id, Vector2 camera);

        //Number 1: Y position
        //+ selected property (example: .x, .type)
        //Number 2: X/Type/... position
        MAP_DATA map_data[MAP_SIZE_Y];

    private:
        float x, y;
        int scale;

        Vector2 fixed_pos;
        int id_x, id_y;
        TILE_DATA tile_data;

        TILE_SPRITESHEET spritesheet;

        void SpritesheetUpdate(Vector2 position);
        Vector2 GetFixedTilePosition(int id);
};
