#pragma once

#include <stdint.h>

namespace J7
{
    class Game
    {
        static constexpr uint16_t CLOCK_FREQ { 32768 };
        static constexpr uint8_t FRAMERATE { 30 };
        uint16_t m_frametime;

    public:
        void start();
        void end();
        bool step();
        void draw();
        void fix30FPS();
    };

    extern Game game;
}