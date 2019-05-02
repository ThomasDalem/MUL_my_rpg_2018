/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_sell_equipement
*/

#include "prototype.h"

int fill_sell_str(scene_t *scene)
{
    FILE *fd = fopen("source/equipement", "r");
    int t = 1;
    int i = 0;
    size_t n = 0;

    scene->sell->str = malloc(sizeof(char *) * 2);
    if (fd == NULL || scene->sell->str == NULL)
        return (84);
    while (getline(&scene->sell->str[i], &n , fd) != -1) {
        scene->sell->str = reallocation(scene->sell->str, t);
        if (scene->sell->str == NULL)
            return (84);
        t++;
        i++;
    }
    return (0);
}