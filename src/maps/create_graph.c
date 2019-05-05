/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_graph
*/

#include <stdlib.h>
#include "prototype.h"
#include "structures.h"
#include "map.h"

static map_t *create_node(map_t *prev_node, int nbr)
{
    char *save = NULL;
    map_t *node = malloc(sizeof(map_t));

    if (!node)
        return (NULL);
    node->objects = NULL;
    node->up = NULL;
    node->down = NULL;
    node->left = prev_node;
    node->right = NULL;
    node->particles = NULL;
    node->enemies = NULL;
    node->pnj = NULL;
    node->map_file = my_strmcat("./maps/map", int_to_char(nbr));
    save = node->map_file;
    node->map_file = my_strmcat(node->map_file, ".map");
    free(save);
    if (init_map(node->map_file, node) == 84)
        return (NULL);
    return (node);
}

static map_t *create_line(int x, int nbr)
{
    map_t *line = create_node(NULL, nbr);
    map_t *cursor = line;

    if (!line)
        return (NULL);
    nbr++;
    for (int i = 1; i < x; i ++) {
        cursor->right = create_node(cursor, nbr);
        nbr ++;
        if (!cursor->right)
            return (NULL);
        cursor = cursor->right;
    }
    return (line);
}

static void link_lines(map_t *top_line, map_t *bottom_line)
{
    if (!top_line || !bottom_line)
        return;
    while (top_line && bottom_line) {
        top_line->down = bottom_line;
        bottom_line->up = top_line;
        top_line = top_line->right;
        bottom_line = bottom_line->right;
    }
}

map_t *create_graph(int x, int y)
{
    map_t *line = NULL;
    map_t *prev_line = NULL;
    int nbr = 0;

    for (int i = 0; i < y; i ++) {
        line = create_line(x, nbr);
        nbr += x;
        if (!line)
            return (NULL);
        link_lines(prev_line, line);
        prev_line = line;
    }
    return (line);
}
