/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** attack
*/

#include "prototype.h"

void attack(scene_t *scene)
{
    sfSprite_setTextureRect(scene->perso->sprite, scene->perso->fight->attack_rect);
    scene->perso->fight->is_attacking = 1;
    sfClock_restart(scene->perso->fight->attack_time.clock);
    //condition de dégat sur l'ennemie
}