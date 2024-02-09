#pragma once
#include <raylib.h>

typedef struct Spritesheet
{
    Texture2D texture;
    Rectangle source;
    Rectangle dest;
    Vector2 origin;
} Spritesheet;

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
        int input_x, input_y;

        Spritesheet spritesheet;

        void Animation(float timeleft, int startframe, int endframe);
};
