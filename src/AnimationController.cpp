#include "AnimationController.h"

namespace J7
{
    AnimationController::AnimationController
    (uint8_t totalTiles, uint8_t delayCount, gfx_rletsprite_t** spritePath)
    {
        m_totalTiles = totalTiles;
        m_delayCount = delayCount;

        m_spritePath = spritePath;
    }

    void
    AnimationController::OnUpdate()
    {
        m_currentDelay++;
        
        if (m_currentDelay == m_delayCount)
        {
            m_currentDelay = 0;
            m_currentTile++;

            if (m_currentTile == m_totalTiles)
            {
                m_currentTile = 0;
            }
        }
    }

    gfx_rletsprite_t*
    AnimationController::GetSprite()
    {
        return m_spritePath[m_currentTile];
    }
}