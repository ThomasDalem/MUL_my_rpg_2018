/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** set_stats_equipement
*/

#include "prototype.h"

int set_stats_equipement(inv_t *invent)
{
    int i = 0;

    invent->stat_equip = malloc(sizeof(struct stats) * 6);
    if (invent->stat_equip == NULL)
        return (84);
    while (i != 5) {
        invent->stat_equip[i] = create_stat_perso(0, 0, 0, 0);
        i++;
    }
    return (0);
}