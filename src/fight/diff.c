/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** diff
*/

#include "fight.h"

int diff(obj_t *perso, obj_t *ennemi)
{
    float x_perso = sfSprite_getPosition(perso->sprite).x;
    float x_enn = sfSprite_getPosition(ennemi->sprite).x;
    float diff = x_perso - x_enn;

    if (diff < 0)
        return (1);
    if (diff > 0)
        return (-1);
    return (0);
}