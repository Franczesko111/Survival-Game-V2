#include <iostream>
#include <raylib.h>
#include "inventory.hpp"
using namespace std;

Inventory::Inventory()
{
    scale = 4;
    spritesheet.texture = LoadTexture("Images/inventory.png");
    Setup(INVENTORY_BOXES);
}

Inventory::~Inventory()
{
    UnloadTexture(spritesheet.texture);
}

void Inventory::Draw()
{
    DrawTexturePro(spritesheet.texture, spritesheet.source, spritesheet.dest, spritesheet.origin, 0, WHITE);
}

void Inventory::Update()
{
    //WIP
}

void Inventory::Setup(int boxes)
{
    //WIP
}

void Inventory::SpritesheetUpdate(float x, float y)
{
    spritesheet.source = Rectangle{0, 0, INVENTORY_SIZE, INVENTORY_SIZE};
    spritesheet.dest = Rectangle{x, y, spritesheet.source.width * scale, spritesheet.source.height * scale};
    spritesheet.origin = Vector2{spritesheet.dest.width / 2, spritesheet.dest.height / 2};
}
