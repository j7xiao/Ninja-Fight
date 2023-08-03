#include "error.h"

#include <graphx.h>
#include <stdlib.h>
#include <tice.h>

#include "appvar.h"

void handle_error(const char* msg, bool use_at_exit)
{
    gfx_End();
    os_ClrHomeFull();

    os_SetCursorPos(0, 0);
    os_PutStrFull("Error:");

    os_SetCursorPos(1, 0);
    os_PutStrFull(msg);

    while (!os_GetCSC());

    if (use_at_exit)
        atexit(free_sprites);
    else
        exit(0);
}