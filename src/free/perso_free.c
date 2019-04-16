/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** Perso Free File
*/

#include "prototype.h"

void free_perso(scene_t *scene)
{
    if (scene->perso == NULL)
        return;
    if (scene->perso->sprite != NULL)
        sfSprite_destroy(scene->perso->sprite);
    if (scene->perso->texture != NULL)
        sfTexture_destroy(scene->perso->texture);
    free(scene->perso);
}
