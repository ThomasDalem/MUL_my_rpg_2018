/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** defense
*/

#include "prototype.h"

void defense_condition(obj_t *perso)
{
    sfTime time;
    float second = 0;

    if (perso->fight->is_blocking == 1) {
        time = sfClock_getElapsedTime(perso->fight->block_time);
        second = sfTime_asSeconds(time);
        if (second > 0.5) {
            perso->fight->is_blocking = 0;
            sfClock_restart(perso->fight->block_time);
            sfSprite_setTextureRect(perso->sprite, perso->fight->rect);
        }
    }
}

void defense(obj_t *perso)
{
    if (perso->fight->is_attacking == 1)
        return;
    sfSprite_setTextureRect(perso->sprite, perso->fight->defense_rect);
    perso->fight->is_blocking = 1;
    sfClock_restart(perso->fight->block_time);
}