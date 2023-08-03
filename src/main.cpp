#include <graphx.h>

#include "game.h"
#include "input.h"

J7::Game game{}; 

int main(void)
{
    game.start();
    gfx_Begin();

    while(game.step())
    {
        game.draw();
    }

    gfx_End();
    game.end();

    return 0;
}