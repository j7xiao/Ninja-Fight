/**
 * @file            error.h
 * @brief           Originally defined within `Class game`. Move to c
 *                  file to silence vscode error w/ os_FullClrHome().
 */

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>

    /**
     * @param use_at_exit Use at_exit() to run game.end() routine before
     * terminating program
     * @note Set to false if all dynamically allocated variables have been
     * properly free'd. Otherwise, set to true. 
     * @warning Will probably reset calculator if set to
     * true and isn't supposed to be. Will probably cause memory leaks if set
     * to false and isn't supposed to be. glhf :D
     */
    void handle_error(const char *msg, bool use_at_exit);

#ifdef __cplusplus
}
#endif