#pragma once

#include <keypadc.h>

namespace J7
{
    typedef enum { NONE, PRESSED, RELEASED, HELD, ERROR = -1 } key_state_t;

    typedef enum
    {
        iNONE,

        iLEFT, iRIGHT, iUP, iDOWN, iLEFTUP, iLEFTDOWN, iRIGHTUP,
        iRIGHTDOWN,

        iCLEAR,

        i2ND, iALPHA, i2NDALPHA
    }
    inputs_t;

    /*
     * Class INPUT
     * 
     * OnUpdate():
     * > e.g. Inputs Pressed: left, 2nd, down
     *     
     * > update key state of (left, 2nd, down)
     * 
     * > order InputStream[] = { 2nd, LeftDown, ... }
     */
    class Input
    {
        key_state_t m_2nd;
        key_state_t m_alpha;
        key_state_t m_left;
        key_state_t m_right;
        key_state_t m_up;
        key_state_t m_down;
        key_state_t m_clear;

        static constexpr uint8_t INPUT_STREAM_LEN { 8 };

        /* (Special input, direction input) */
        static constexpr uint8_t INPUT_ENTRIES    { 2 };

        /* (Special Inputs, Directional Inputs) */
        inputs_t InputStream[INPUT_STREAM_LEN];

        void UpdateKey(kb_lkey_t key, key_state_t &key_state);
        void UpdateInputStream();

    public:
        Input();

        void OnUpdate();

        key_state_t GetKeyState(kb_lkey_t key);
        bool IsKeyDown(kb_lkey_t key);
        bool IsEmptyInput();
        inputs_t GetInputStream(uint8_t index);
    };

    extern Input input;
}
