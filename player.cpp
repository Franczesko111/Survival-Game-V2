#include <raylib.h>
#include "player.hpp"

Player::Player()
{
    //Setup player properites
    scale = 6;
    speed = 5;
    bounds_limit_x = ((MAP_SIZE_X - 16) * 64) + 1024 - (PLAYER_WIDTH * scale) / 2;
    bounds_limit_y = ((MAP_SIZE_Y - 15) * 64) + 960 - (PLAYER_HEIGHT * scale) / 2;
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;
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

    //Player off-screen check
    if(x < (PLAYER_WIDTH * scale) / 2) x = (PLAYER_WIDTH * scale) / 2;
    if(x > bounds_limit_x) x = bounds_limit_x;
    if(y < (PLAYER_HEIGHT * scale) / 2) y = (PLAYER_HEIGHT * scale) / 2;
    if(y > bounds_limit_y) y = bounds_limit_y;

    //Update Properties
    spritesheet.source = Rectangle{(float)frame * PLAYER_WIDTH, 0, PLAYER_WIDTH, PLAYER_HEIGHT};
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
