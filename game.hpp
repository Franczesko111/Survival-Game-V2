//INFINITE TERRAIN
#pragma once
#include <raylib.h>

#include "player.hpp"
#include "tiles.hpp"
#include "data.hpp"

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

        float bounds_limit_x, bounds_limit_y;

        void UpdateCameraOutOfBounds();
};
