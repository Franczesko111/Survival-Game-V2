#pragma once
#include <raylib.h>
#include "player.h"

class Game
{
    public:
        void Draw();
        void Update();

    private:
        Player player;
};
