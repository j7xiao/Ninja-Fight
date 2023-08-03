#pragma once

#include <stdbool.h>
#include <keypadc.h>

namespace J7
{
    typedef enum { NONE, PRESSED, RELEASED, HELD, ERROR } key_state_t;

    class Input
    {
        key_state_t m_2nd;
        key_state_t m_alpha;
        key_state_t m_left;
        key_state_t m_right;
        key_state_t m_up;
        key_state_t m_down;

        key_state_t m_clear;

        void UpdateKey(kb_lkey_t key, key_state_t &key_state);

    public:
        Input();

        void UpdateInput();

        key_state_t GetKey(kb_lkey_t key);
    };

    extern Input input;
}
