/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** norm_move
*/

#include "prototype.h"

void move_norm(sfFloatRect *pos_zone, sfFloatRect *pos_enn, float *time,
                obj_t *enemies)
{
    *pos_zone = sfCircleShape_getGlobalBounds(enemies->detect_zone);
    *pos_enn = sfSprite_getGlobalBounds(enemies->sprite);
    *time = sfTime_asSeconds(sfClock_getElapsedTime(enemies->dir_clock));
}