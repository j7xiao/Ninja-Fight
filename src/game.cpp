#include "Game.h"

#include <graphx.h>
#include <tice.h>

#include "AnimationController.h"
#include "appvar.h"
#include "Input.h"

namespace J7
{
    AnimationController animContr {TILES_NINJA_IDLE, 6, &ninja_r_sprites[0]};

    void
    Game::start()
    {
        timer_Control = (TIMER1_ENABLE | TIMER1_32K | TIMER1_UP);
        
        kb_SetMode(MODE_3_CONTINUOUS);

        gfx_Begin();
        gfx_SetDrawBuffer();

        load_sprites();
    }

    void
    Game::end()
    {
        gfx_End();
        free_sprites();
    }

    bool
    Game::step()
    {
        input.OnUpdate();
        animContr.OnUpdate();

        /* break from game loop if [CLEAR] is pressed*/
        if (input.IsKeyDown(kb_KeyClear)) { return false; }

        return true;
    }

    void
    Game::draw()
    {
        gfx_ZeroScreen(); // clear screen

        gfx_RLETSprite_NoClip(animContr.GetSprite(), 0, 0);
        gfx_SwapDraw();  // Queue the buffered frame to be displayed
    }

    void
    Game::fix30FPS()
    {
        while(timer_1_Counter < (CLOCK_FREQ / FRAMERATE));

        m_frametime = timer_1_Counter;
        timer_1_Counter = 0;
    }
}