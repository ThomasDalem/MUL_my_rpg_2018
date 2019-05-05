/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** fight_norm
*/

#include "prototype.h"

void start_repulse(scene_t *scene)
{
    check_orient(scene);
    sfClock_restart(scene->perso->anim_clock);
    sfClock_restart(scene->ennemi->anim_clock);
}