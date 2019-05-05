/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** add_particles
*/

#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "particles.h"
#include "my.h"

int add_particles(FILE *stream, map_t *map)
{
    char *line = NULL;
    size_t len = 0;
    int x = 0;
    int y = 0;

    if (getline(&line, &len, stream) == -1)
        return (84);
    x = my_getnbr(line);
    free(line);
    line = NULL;
    if (getline(&line, &len, stream) == -1)
        return (84);
    y = my_getnbr(line);
    map->particles = create_particles(10, x, y);
    return (1);
}
