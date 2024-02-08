#include <raylib.h>
#include "player.h"

#define PLAYER_WIDTH 9
#define PLAYER_HEIGHT 13

Player::Player()
{
    scale = 6;
    speed = 5;
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;

    texture = LoadTexture("Images/player.png");
    rotation = 0;
}

Player::~Player()
{
    UnloadTexture(texture);
}

void Player::Draw()
{
    DrawTexturePro(texture, source, dest, origin, rotation, WHITE);
}

void Player::Update()
{
    //Movement
    input_x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    input_y = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);
    x += input_x * speed;
    y += input_y * speed;

    //Update Properties
    source = Rectangle{frame * PLAYER_WIDTH, 0, PLAYER_WIDTH, PLAYER_HEIGHT};
    dest = Rectangle{x, y, source.width * scale, source.height * scale};
    origin = Vector2{dest.width / 2, dest.height / 2};

    //Animation Handler
    if(input_x != 0 || input_y != 0)
        Animation(0.25, 1, 3);
    else
        timer = frame = 0;
}

void Player::Animation(float timeleft, int startframe, int endframe)
{
    if(timer == 0)
    {
        timer = timeleft;
        frame = startframe;
    }
    timer -= GetFrameTime();
    if(timer < 0)
    {
        timer = timeleft;
        frame++;
        if(frame == endframe) frame = startframe;
    }
}
