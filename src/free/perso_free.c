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
    if (scene->perso.sprite_perso != NULL)
        sfSprite_destroy(scene->perso.sprite_perso);
    if (scene->perso.texture != NULL)
        sfTexture_destroy(scene->perso.texture);
    if (scene->perso.detect_zone != NULL)
        sfCircleShape_destroy(scene->perso.detect_zone);
    //free(scene->perso);
}
