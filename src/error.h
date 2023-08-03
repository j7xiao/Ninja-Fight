/**
 * @file            error.h
 * @brief           error include file - originally defined within Class game
 *                  moved to c file to silence vscode error w/ os_FullClrHome()
 */

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>

    /**
     * @param use_at_exit use at_exit() to run game.end() routine before
     * terminating program
     * @note set to false if all dynamically allocated variables have been
     * properly free'd. otherwise, set to true. 
     * @warning will probably reset calculator if set to
     * true and isn't supposed to be. Will probably cause memory leaks if set
     * to false and isn't supposed to be. glhf :D
     */
    void handle_error(const char *msg, bool use_at_exit);

#ifdef __cplusplus
}
#endif