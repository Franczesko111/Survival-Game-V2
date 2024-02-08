#pragma once
#include <raylib.h>
#include "player.hpp"

class Game
{
    public:
        void Draw();
        void Update();

    private:
        Player player;
};
