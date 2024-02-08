#include <raylib.h>
#include "game.hpp

void Game::Draw()
{
    player.Draw();
}

void Game::Update()
{
    player.Update();
}
