#pragma once
#include <raylib.h>
#include "data.hpp"

typedef struct INVENTORY_DATA
{
    float x;
    float y;
    int id;
} INVENTORY_DATA;

typedef struct INVENTORY_SPRITESHEET
{
    Texture2D texture;
    Rectangle source;
    Rectangle dest;
    Vector2 origin;
} INVENTORY_SPRITESHEET;

class Inventory
{
    public:
        Inventory();
        ~Inventory();
        void Draw();
        void Update();

    private:
        float x, y;
        int scale;

        void Setup(int boxes);
        void SpritesheetUpdate(float x, float y);

        INVENTORY_DATA data[INVENTORY_BOXES];
        INVENTORY_SPRITESHEET spritesheet;
};
