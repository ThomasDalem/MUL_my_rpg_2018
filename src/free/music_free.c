/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** Free Music File
*/

#include "prototype.h"

int free_music(scene_t *scene)
{
    sfMusic_destroy(scene->music->sound);
    return (0);
}
