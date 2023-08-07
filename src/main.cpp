#include <tice.h>

#include "Game.h"

J7::Game game{};

int main(void)
{
    game.OnStart();

    while(game.OnStep())
    {
        game.OnDraw();
        game.Fix30FPS();
    }

    game.OnEnd();

    return 0;
}