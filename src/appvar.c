#include "appvar.h"

#include <graphx.h>
#include <fileioc.h>
#include <stdint.h>

#include "error.h"

gfx_rletsprite_t *ninja_r_sprites[NINJA_SPRITE_ENTRIES_NUM];
gfx_rletsprite_t *ninja_l_sprites[NINJA_SPRITE_ENTRIES_NUM];

void load_sprites(void);
void free_sprites(void);

/**
 * @brief Reads 32x32px sprite data from file. Converts to 64x64px with RLEt.
 * Stores converted sprite (sprite_r) as well as a flipped copy of the sprite
 * (sprite_l) into their respective sprite params
 */
static void
new_scaled_rlet_sprite(gfx_rletsprite_t **sprite_r
                     , gfx_rletsprite_t **sprite_l, const uint8_t *data_ptr)
{
    gfx_sprite_t *tmp_r_sprite, *tmp_l_sprite;

    // right
    tmp_r_sprite = gfx_MallocSprite(NINJA_SPRITE_WIDTH, NINJA_SPRITE_HEIGHT);
    gfx_ScaleSprite((gfx_sprite_t *)data_ptr, tmp_r_sprite);
    *sprite_r = gfx_ConvertMallocRLETSprite(tmp_r_sprite);

    // left
    tmp_l_sprite = gfx_MallocSprite(NINJA_SPRITE_WIDTH, NINJA_SPRITE_HEIGHT);
    gfx_FlipSpriteY(tmp_r_sprite, tmp_l_sprite);
    *sprite_l = gfx_ConvertMallocRLETSprite(tmp_l_sprite);

    // free
    free(tmp_r_sprite);
    free(tmp_l_sprite);
}

/* Reads sprites from appvar and writes to program */
void load_sprites(void)
{
    uint8_t appvar = ti_Open("StkNnjaS", "r");

    if (appvar == 0)
    {
        handle_error("Missing appVar StkNnjaS!", false);
    }

    /* Reads palette data and sets global palette */

    uint16_t pal_size;
    uint16_t *pal_ptr;

    pal_ptr = (uint16_t *)ti_GetDataPtr(appvar);
    pal_size = *pal_ptr;
    pal_ptr++;

    gfx_SetPalette(pal_ptr, pal_size, 0);

    /*
     * Sprite data outputs after palette data (as per gfx/convimg.yaml)
     * Read from appvar and write to sprite arrays using sprite routine
     */

    uint8_t *spr_ptr;

    spr_ptr = (uint8_t *)pal_ptr;
    spr_ptr += pal_size;

    for(uint8_t i = 0; i < NINJA_SPRITE_ENTRIES_NUM; ++i)
    {
        new_scaled_rlet_sprite(&ninja_r_sprites[i], &ninja_l_sprites[i]
                             , spr_ptr);
        spr_ptr += NINJA_SPRITE_DATA_SIZE;
    }

    ti_Close(appvar);
}

/**
 *  Frees sprites malloc'd at program start
 *  @see sprite_routine();
 */
void free_sprites(void)
{
    uint8_t i;

    for (i = 0; i < NINJA_SPRITE_ENTRIES_NUM; ++i)
    {
        free(ninja_r_sprites[i]);
        free(ninja_l_sprites[i]);
    }
}
