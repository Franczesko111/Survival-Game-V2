#pragma once
#include <raylib.h>

class Player
{
    public:
        Player();
        ~Player();
        void Draw();
        void Update();

    private:
        float x, y, rotation, timer;
        int scale, speed, frame;
        int input_x, input_y;

        Texture2D texture;
        Rectangle source;
        Rectangle dest;
        Vector2 origin;

        void Animation(float timeleft, int startframe, int endframe);
};
