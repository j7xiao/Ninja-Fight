#pragma once

#include "AnimationController.h"

namespace J7
{
    class Ninja : public AnimationController
    {
        /* Projectiles when? D: */

        uint16_t m_absX;
        uint16_t m_relX;

        uint8_t m_absY;
        uint8_t m_relY;

    public:
        Ninja(uint16_t relX, uint8_t relY, gfx_rletsprite_t **spritePath);
        uint16_t GetRelXPos();
        uint8_t GetRelYPos();
    };
}
