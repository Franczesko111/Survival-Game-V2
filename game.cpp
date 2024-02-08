#include <raylib.h>
#include "game.h"

void Game::Draw()
{
    player.Draw();
}

void Game::Update()
{
    player.Update();
}
