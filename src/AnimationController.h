#pragma once

#include <graphx.h>
#include <stdint.h>

#include "appvar.h"

namespace J7
{
    class AnimationController
    {        
    private:
        uint8_t m_currentTile { 0 };
        uint8_t m_totalTiles;
        uint8_t m_currentDelay { 0 };
        uint8_t m_delayCount;

    public:
        gfx_rletsprite_t** m_spritePath;
    
        AnimationController(uint8_t totalTiles, uint8_t delayCount
                          , gfx_rletsprite_t** spritePath);
        
        void OnUpdate();
        gfx_rletsprite_t* GetSprite();
    };
}
