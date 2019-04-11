/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** free_graph
*/

#include <stdlib.h>
#include "prototype.h"

void free_graph(map_t *node)
{
    map_t *first_node = get_first_node(node);
    map_t *row = first_node;
    map_t *col = NULL;
    map_t *save = NULL;

    while (row) {
        col = row;
        row = row->down;
        while (col) {
            save = col;
            col = col->right;
            free(save);
        }
    }
}
