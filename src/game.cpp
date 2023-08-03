#include "game.h"

#include <graphx.h>
#include <tice.h>

#include "appvar.h"
#include "input.h"

namespace J7
{
    void Game::start()
    {
        load_sprites();

        gfx_SetDrawBuffer();
        kb_SetMode(MODE_3_CONTINUOUS);  
    }

    void Game::end()
    {
        free_sprites();
    }

    bool Game::step()
    {
        key_state_t pressed_clear = input.GetKey(kb_KeyClear);
        input.UpdateInput();

        /* break from game loop if [CLEAR] is pressed*/
        if (pressed_clear != NONE) { return false; }

        return true;
    }

    void Game::draw()
    {
        
        gfx_SwapDraw();  // Queue the buffered frame to be displayed
    }
}