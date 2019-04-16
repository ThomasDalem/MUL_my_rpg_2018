/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** Global Free File
*/

#include "prototype.h"

int free_global(scene_t *scene)
{
    printf("[INTERNAL] music (free) attempting ...\n");
    free_music(scene);
    printf("[INTERNAL] perso (free) attempting ...\n");
    free_perso(scene);
    printf("[INTERNAL] end (free)\n");
    return (0);
}
