#pragma once
#include <raylib.h>

typedef struct TILE_DATA
{
    int clone_x[240];
    int clone_y[240];
} TILE_DATA;

typedef struct MAP_DATA
{
    int type[16];
    float x[16];
    float y;
} MAP_DATA;

class Tile
{
    public:
        Tile();
        void Draw(int id);

        //Number 1: Y position
        //Number 2: Selected property
        //Number 3: X/Type/... position
        MAP_DATA map_data[15];

    private:
        float x, y, width, height;
        int scale;

        float fixed_x, fixed_y;
        int id_x, id_y;
        TILE_DATA tile_data;
};
