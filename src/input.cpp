#include "Input.h"

#include <stdbool.h>
#include <keypadc.h>

#include "error.h"
#include "Game.h"

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
    Input::OnUpdate()
    {
        Input::UpdateKey(kb_Key2nd,   m_2nd  );
        Input::UpdateKey(kb_KeyAlpha, m_alpha);
        Input::UpdateKey(kb_KeyClear, m_clear);
        Input::UpdateKey(kb_KeyLeft,  m_left );
        Input::UpdateKey(kb_KeyRight, m_right);
        Input::UpdateKey(kb_KeyUp,    m_up   );
        Input::UpdateKey(kb_KeyDown,  m_down );

        Input::UpdateInputStream();
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
                handle_error("Input::UpdateKey()", true);
                break;              

            default:
                break;
        }
    }

    void
    Input::UpdateInputStream()
    {
        /* return if empty input frame */
        if (Input::IsEmptyInput()) { return; }

        /* push back input stream */
        for(uint8_t i = INPUT_STREAM_LEN - INPUT_ENTRIES - 1; i > 0; --i)
        {
            InputStream[i] = InputStream[i + INPUT_ENTRIES];
        }

        /* ignore inputs between each frame check, so avoid kb_IsDown(); */

        bool isDown_2nd   = Input::IsKeyDown(kb_Key2nd);
        bool isDown_Alpha = Input::IsKeyDown(kb_KeyAlpha);
        bool isDown_Left  = Input::IsKeyDown(kb_KeyLeft);
        bool isDown_Right = Input::IsKeyDown(kb_KeyRight);
        bool isDown_Up    = Input::IsKeyDown(kb_KeyUp);
        bool isDown_Down  = Input::IsKeyDown(kb_KeyDown);

        /* insert current input frame */

        if (isDown_2nd && isDown_Alpha)
        {
            InputStream[0] = i2NDALPHA; // 2nd-Alpha
        } else
        if (isDown_2nd)
        {
            InputStream[0] = i2ND; // 2nd
        } else
        if (isDown_Alpha)
        {
            InputStream[0] = iALPHA; // Alpha
        }

        if (isDown_Left)
        {
            if (isDown_Up)
            {
                InputStream[1] = iLEFTUP; // left-up
            } else 
            if (isDown_Down)
            {
                InputStream[1] = iLEFTDOWN; // left-down
            } else
            {
                InputStream[1] = iLEFT; // left
            }
        }

        if (isDown_Right)
        {
            if (isDown_Up)
            {
                InputStream[1] = iRIGHTUP; // left-up
            } else 
            if (isDown_Down)
            {
                InputStream[1] = iRIGHTDOWN; // right-down
            } else
            {
                InputStream[1] = iRIGHT; // right
            }
        }
    }

    key_state_t
    Input::GetKeyState(kb_lkey_t key)
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

    bool
    Input::IsKeyDown(kb_lkey_t key)
    {
        switch(key)
        {
            case kb_Key2nd:
                return (m_2nd == PRESSED   || m_2nd == HELD);

            case kb_KeyAlpha:
                return (m_alpha == PRESSED || m_alpha == HELD);

            case kb_KeyClear:
                return (m_clear == PRESSED || m_clear == HELD);

            case kb_KeyLeft:
                return (m_left == PRESSED  || m_left == HELD);

            case kb_KeyRight:
                return (m_right == PRESSED || m_right == HELD);

            case kb_KeyUp:
                return (m_up == PRESSED    || m_up == HELD);

            case kb_KeyDown:
                return (m_down == PRESSED  || m_clear == HELD);

            default:
                handle_error("Input::IsKeyDown()", true);
                return false;
        }
    }

    bool
    Input::IsEmptyInput()
    {
        return (m_2nd   == NONE
             && m_alpha == NONE
             && m_left  == NONE
             && m_right == NONE
             && m_up    == NONE
             && m_down  == NONE
             && m_clear == NONE);
    }

    inputs_t
    Input::GetInputStream(uint8_t index)
    {
        return InputStream[index];
    }
}
