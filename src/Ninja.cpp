#include "Ninja.h"

namespace J7
{
    Ninja::Ninja(uint16_t relX, uint8_t relY, gfx_rletsprite_t **spritePath)
    : AnimationController{ TILES_NINJA_IDLE, 4, spritePath }
    {
        m_relX = relX;
        m_relY = relY;
    }

    uint16_t
    Ninja::GetRelXPos()
    {
        return m_relX;
    }

    uint8_t
    Ninja::GetRelYPos()
    {
        return m_relY;
    }
}