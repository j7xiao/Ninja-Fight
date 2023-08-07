#include "Game.h"

#include <graphx.h>
#include <tice.h>

#include "AnimationController.h"
#include "appvar.h"
#include "Input.h"
#include "Ninja.h"

namespace J7
{
    J7::Ninja player{ 0, 176, &ninja_r_sprites[0] };

    void
    Game::OnStart()
    {
        timer_Control = (TIMER1_ENABLE | TIMER1_32K | TIMER1_UP);
        
        kb_SetMode(MODE_3_CONTINUOUS);

        gfx_Begin();
        gfx_SetDrawBuffer();

        load_sprites();        
    }

    void
    Game::OnEnd()
    {
        gfx_End();
        free_sprites();
    }

    bool
    Game::OnStep()
    {
        input.OnUpdate();
        player.OnUpdate();

        /* break from game loop if [CLEAR] is pressed*/
        if (input.IsKeyDown(kb_KeyClear)) { return false; }

        return true;
    }

    void
    Game::OnDraw()
    {
        gfx_ZeroScreen(); // clear screen

        uint16_t player_x = player.GetRelXPos();
        uint8_t player_y = player.GetRelYPos();
        gfx_RLETSprite_NoClip(player.GetSprite(), player_x, player_y);
        
        gfx_SwapDraw();  // Queue the buffered frame to be displayed
    }

    void
    Game::Fix30FPS()
    {
        while(timer_1_Counter < (CLOCK_FREQ / FRAMERATE));

        m_frametime = timer_1_Counter;
        timer_1_Counter = 0;
    }
}