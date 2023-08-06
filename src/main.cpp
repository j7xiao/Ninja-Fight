#include <tice.h>

#include "Game.h"

J7::Game game{}; 

int main(void)
{
    game.start();

    while(game.step())
    {
        game.draw();
        game.fix30FPS();
    }

    game.end();

    return 0;
}