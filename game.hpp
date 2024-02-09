#pragma once
#include <raylib.h>

#include "player.hpp"
#include "tiles.hpp"

class Game
{
    public:
        Game();
        void Draw();
        void Update();

    private:
        Player player;
        Tile tile;
        Camera2D camera;
};
