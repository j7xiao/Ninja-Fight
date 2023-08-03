#include "input.h"

#include <stdbool.h>
#include <keypadc.h>

#include "error.h"
#include "game.h"

namespace J7
{
    J7::Input input{}; 
    
    Input::Input()
    {
        m_2nd = NONE;
        m_alpha = NONE;
        m_left = NONE;
        m_right = NONE;
        m_up = NONE;
        m_down = NONE;
        m_clear = NONE;
    }
        
    void
    Input::UpdateInput()
    {
        Input::UpdateKey(kb_Key2nd, m_2nd);
        Input::UpdateKey(kb_KeyAlpha, m_alpha);
        Input::UpdateKey(kb_KeyClear, m_clear);
        Input::UpdateKey(kb_KeyLeft, m_left);
        Input::UpdateKey(kb_KeyRight, m_right);
        Input::UpdateKey(kb_KeyUp, m_up);
        Input::UpdateKey(kb_KeyDown, m_down);
    }

    void
    Input::UpdateKey(kb_lkey_t key, key_state_t &key_state)
    {
        bool is_key_down = kb_IsDown(key);
        
        switch (key_state)
        {
            case NONE:
                if (is_key_down) { key_state = PRESSED;  }
                break;

            case PRESSED:
                if (is_key_down) { key_state = HELD;     }
                else             { key_state = RELEASED; }
                break;

            case RELEASED:
                if (is_key_down) { key_state = PRESSED;  }
                else             { key_state = NONE;     }
                break;

            case HELD:
                if (is_key_down) { key_state = RELEASED; }
                break;

            case ERROR:
                handle_error("input logic >.<", true);              

            default:
                break;
        }
    }

    key_state_t
    Input::GetKey(kb_lkey_t key)
    {
        switch(key)
        {
            case kb_Key2nd:
                return m_2nd;

            case kb_KeyAlpha:
                return m_alpha;

            case kb_KeyClear:
                return m_clear;

            case kb_KeyLeft:
                return m_left;

            case kb_KeyRight:
                return m_right;

            case kb_KeyUp:
                return m_up;

            case kb_KeyDown:
                return m_down;

            default:
                return ERROR;
        }
    }
}
