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

#define INDEX_NINJA_0_IDLE          0
#define INDEX_NINJA_1_IDLE          1
#define INDEX_NINJA_2_IDLE          2

#define INDEX_NINJA_0_JAB           3
#define INDEX_NINJA_1_JAB           4
#define INDEX_NINJA_2_JAB           5
#define INDEX_NINJA_3_JAB           6

#define INDEX_NINJA_0_RUN           7
#define INDEX_NINJA_1_RUN           8
#define INDEX_NINJA_2_RUN           9
#define INDEX_NINJA_3_RUN           10
#define INDEX_NINJA_4_RUN           11
#define INDEX_NINJA_5_RUN           12

#define TILES_NINJA_IDLE            3
#define TILES_NINJA_JAB             4
#define TIELS_NINJA_RUN             6

    extern gfx_rletsprite_t *ninja_r_sprites[NINJA_SPRITE_ENTRIES_NUM];
    extern gfx_rletsprite_t *ninja_l_sprites[NINJA_SPRITE_ENTRIES_NUM];

    void load_sprites(void);
    void free_sprites(void);

#ifdef __cplusplus
}
#endif