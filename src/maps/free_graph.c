/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** free_graph
*/

#include <stdlib.h>
#include "prototype.h"
#include "map.h"
#include "particles.h"

static void free_map_obj(map_obj_t *objs)
{
    map_obj_t *save = NULL;

    while (objs != NULL) {
        save = objs;
        objs = objs->next;
        sfSprite_destroy(save->sprite);
        sfTexture_destroy(save->texture);
        free(save);
    }
}

void free_graph(map_t *node)
{
    map_t *first_node = get_top_left_map(node);
    map_t *row = first_node;
    map_t *col = NULL;
    map_t *save = NULL;

    while (row) {
        col = row;
        row = row->down;
        while (col) {
            save = col;
            col = col->right;
            free_map_obj(save->objects);
            free(save->map_file);
            free_particles(save->particles);
            free(save);
        }
    }
}
