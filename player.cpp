#include <raylib.h>
#include "player.hpp"

#define PLAYER_WIDTH 9
#define PLAYER_HEIGHT 13

Player::Player()
{
    scale = 6;
    speed = 5;
    x = GetScreenWidth() / 2 + 128;
    y = GetScreenHeight() / 2 + 128;

    spritesheet.texture = LoadTexture("Images/player.png");
    rotation = 0;
}

Player::~Player()
{
    UnloadTexture(spritesheet.texture);
}

void Player::Draw()
{
    DrawTexturePro(spritesheet.texture, spritesheet.source, spritesheet.dest, spritesheet.origin, rotation, WHITE);
}

void Player::Update()
{
    //Movement
    input_x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    input_y = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);
    x += input_x * speed;
    y += input_y * speed;

    //Update Properties
    spritesheet.source = Rectangle{frame * PLAYER_WIDTH, 0, PLAYER_WIDTH, PLAYER_HEIGHT};
    spritesheet.dest = Rectangle{x, y, spritesheet.source.width * scale, spritesheet.source.height * scale};
    spritesheet.origin = Vector2{spritesheet.dest.width / 2, spritesheet.dest.height / 2};

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

Vector2 Player::GetPlayerPosition() {return Vector2{x, y};}
