//INFINITE TERRAIN
#pragma once
#include <raylib.h>
#include "data.hpp"

typedef struct PLAYER_SPRITESHEET
{
    Texture2D texture;
    Rectangle source;
    Rectangle dest;
    Vector2 origin;
} PLAYER_SPRITESHEET;

class Player
{
    public:
        Player();
        ~Player();
        void Draw();
        void Update();

        Vector2 GetPlayerPosition();

    private:
        float x, y, rotation, timer;
        int scale, speed, frame;
        int input_x, input_y, bounds_limit_x, bounds_limit_y;

        PLAYER_SPRITESHEET spritesheet;

        void Animation(float timeleft, int startframe, int endframe);
};
