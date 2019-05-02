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

void free_inventory(inv_t *invent)
{
    int i = 0;
    int j = 0;

    sfSprite_destroy(invent->sprite);
    sfText_destroy(invent->attack);
    sfText_destroy(invent->defense);
    sfText_destroy(invent->life);
    sfText_destroy(invent->life);
    sfFont_destroy(invent->font);
    while (invent->button[i] != NULL) {
        sfRectangleShape_destroy(invent->button[i]->but);
        i ++;
    }
    while (invent->equipement[j] != NULL) {
        sfRectangleShape_destroy(invent->equipement[j]->but);
        j ++;
    }
}

void close_window(scene_t *scene, pause_s *pause, int *gamemode, inv_t *invent)
{
    free_global(scene);
    if (*gamemode == 3)
        sfRenderWindow_close(scene->window);
}
