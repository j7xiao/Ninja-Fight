#pragma once

namespace J7
{
    class Game
    {
    public:
        void start();
        void end();
        bool step();
        void draw();
    };

    extern Game game;
}