/**
 * @file            appvar.h
 * @brief           appvar include file
 */

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include <graphx.h>

#define NINJA_SPRITE_ENTRIES_NUM    13
#define NINJA_SPRITE_HEIGHT         64
#define NINJA_SPRITE_WIDTH          64
#define NINJA_SPRITE_DATA_SIZE      1026

    extern gfx_rletsprite_t *ninja_sprites[NINJA_SPRITE_ENTRIES_NUM];

    void load_sprites(void);
    void free_sprites(void);

#ifdef __cplusplus
}
#endif