#include "appvar.h"

#include <graphx.h>
#include <fileioc.h>
#include <stdint.h>

#include "error.h"

gfx_rletsprite_t *ninja_sprites[NINJA_SPRITE_ENTRIES_NUM];

void load_sprites(void);
void free_sprites(void);

/**
 * @brief Reads 32x32px sprite data from file. Converts to 64x64px with RLEt.
 * Stores converted sprites in provided sprite.
 */
static void
scale_new_rlet_sprite(gfx_rletsprite_t **sprite, const uint8_t *data_ptr)
{
    gfx_sprite_t *tmp_sprite;

    tmp_sprite = gfx_MallocSprite(NINJA_SPRITE_WIDTH, NINJA_SPRITE_HEIGHT);
    gfx_ScaleSprite((gfx_sprite_t *)data_ptr, tmp_sprite);
    *sprite = gfx_ConvertMallocRLETSprite(tmp_sprite);

    free(tmp_sprite);
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
        scale_new_rlet_sprite(&ninja_sprites[i], spr_ptr);
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
        free(ninja_sprites[i]);
    }
}
