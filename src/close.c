/*
** EPITECH PROJECT, 2018
** window_stats.c
** File description:
** HEADER
*/

#include "prototype.h"

static void free_pause(pause_s *pause)
{
    sfRectangleShape_destroy(pause->filter);
    sfFont_destroy(pause->font);
    sfText_destroy(pause->txt[0]);
    sfText_destroy(pause->txt[1]);
    sfText_destroy(pause->txt[2]);
    free(pause->txt);
}

void close_window(scene_t *scene, pause_s *pause, int *gamemode)
{
    free_pause(pause);
    if (*gamemode == 3)
        sfRenderWindow_close(scene->window);
}
