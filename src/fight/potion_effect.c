/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** potion_effect
*/

#include "prototype.h"

void potion_effect(scene_t *scene)
{
    sfTime time;
    float potion_time;

    if (scene->perso->fight->is_potion != 1)
        return;
    time = sfClock_getElapsedTime(scene->perso->fight->time_potion);
    potion_time = sfTime_asSeconds(time);
    if (potion_time > 10) {
        if (scene->perso->fight->type == 2)
            scene->perso->stat.attack-= scene->perso->fight->effect;
        if (scene->perso->fight->type == 3)
            scene->perso->stat.defense-= scene->perso->fight->effect;
        if (scene->perso->fight->type == 4)
            scene->perso->stat.magic-= scene->perso->fight->effect;
        scene->perso->fight->is_potion = 0;
        sfClock_restart(scene->perso->fight->time_potion);
    }    
}