/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** alive
*/

#include "fight.h"

int check_alive(scene_t *scene)
{
    int perso_live = scene->perso->stat.life;
    int enn_live = scene->ennemi->stat.life;

    if (perso_live < 1)
        return (4);
    if (enn_live < 1)
        return (0);
    return (1);
}
