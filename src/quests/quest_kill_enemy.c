/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** quest_kill_enemy
*/

#include <stdlib.h>
#include "structures.h"

int check_quest_kill(void *obj, void *check)
{
    obj_t *enemies = (obj_t *)obj;
    int check_id = (int)check;

    while (enemies) {
        if (enemies->id == check_id)
            return (0);
    }
    return (1);
}
