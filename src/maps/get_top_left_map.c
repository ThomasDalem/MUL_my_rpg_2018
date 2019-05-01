/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** get_top_left_map
*/

#include "prototype.h"
#include "structures.h"

map_t *get_top_left_map(map_t *maps)
{
    if (maps == NULL)
        return (NULL);
    while (maps->left)
        maps = maps->left;
    while (maps->up)
        maps = maps->up;
    return (maps);
}
