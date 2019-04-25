/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** defense
*/

#include "prototype.h"

void defense_condition(scene_t *scene)
{
    sfTime time;
    float second = 0;

    if (scene->perso->fight->is_blocking == 1) {
        time = sfClock_getElapsedTime(scene->perso->fight->block_time);
        second = sfTime_asSeconds(time);
        if (second > 0.5) {
            scene->perso->fight->is_blocking = 0;
            sfClock_restart(scene->perso->fight->block_time);
            sfSprite_setTextureRect(scene->perso->sprite, scene->perso->fight->rect);
        }
    }
}

void defense(scene_t *scene)
{
    sfSprite_setTextureRect(scene->perso->sprite, scene->perso->fight->defense_rect);
    scene->perso->fight->is_blocking = 1;
    sfClock_restart(scene->perso->fight->block_time);
}