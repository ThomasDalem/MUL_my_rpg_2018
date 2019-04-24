/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include "structures.h"

map_t *create_graph(int x, int y);
void free_graph(map_t *node);
map_t *get_top_left_map(map_t *maps);
map_obj_t *add_objects(char *path, int x, int y, map_obj_t *next);
int check_maps(sfVector2f player_pos, scene_t *scene);

// Maps creation
void create_map1(map_t *map);
void create_map2(map_t *map);
void create_map3(map_t *map);
void create_map4(map_t *map);

#endif /* !MAP_H_ */
