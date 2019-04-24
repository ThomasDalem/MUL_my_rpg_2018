/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_graph
*/

#include <stdlib.h>
#include <stdio.h>
#include "prototype.h"
#include "structures.h"
#include "map.h"

static map_t *create_node(map_t *prev_node)
{
    static int nb = 0;
    map_t *node = malloc(sizeof(map_t));

    if (!node)
        return (NULL);
    node->objects = NULL;
    node->up = NULL;
    node->down = NULL;
    node->left = prev_node;
    node->right = NULL;
    node->map_file = my_strmcat("./maps/map", int_to_char(nb));
    node->map_file = my_strmcat(node->map_file, ".map");
    if (init_map(node->map_file, node) == 84)
        return (NULL);
    nb++;
    return (node);
}

static map_t *create_line(int x)
{
    map_t *line = create_node(NULL);
    map_t *cursor = line;

    if (!line)
        return (NULL);
    for (int i = 0; i < x; i++) {
        cursor->right = create_node(cursor);
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

    for (int i = 0; i < y; i++) {
        line = create_line(x);
        if (!line)
            return (NULL);
        link_lines(prev_line, line);
        prev_line = line;
    }
    return (line);
}
