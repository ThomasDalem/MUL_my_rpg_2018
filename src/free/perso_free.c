/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** Perso Free File
*/

#include "prototype.h"

void free_enn(scene_t *scene)
{
    while (scene->ennemi != NULL) {
        sfSprite_destroy(scene->ennemi->sprite);
        sfTexture_destroy(scene->ennemi->texture);
        sfClock_destroy(scene->ennemi->fight->jump_clock);
        sfClock_destroy(scene->ennemi->fight->block_time);
        sfClock_destroy(scene->ennemi->fight->attack_time.clock);
        sfTexture_destroy(scene->ennemi->fight->texture);
        scene->ennemi = scene->ennemi->next;
    }
    free(scene->ennemi);
}

void free_perso(scene_t *scene)
{
    if (scene->perso == NULL)
        return;
    if (scene->perso->sprite != NULL)
        sfSprite_destroy(scene->perso->sprite);
    if (scene->perso->texture != NULL)
        sfTexture_destroy(scene->perso->texture);
    sfClock_destroy(scene->perso->fight->jump_clock);
    sfClock_destroy(scene->perso->fight->block_time);
    sfClock_destroy(scene->perso->fight->attack_time.clock);
    sfTexture_destroy(scene->perso->fight->texture);
    free(scene->perso);
}
