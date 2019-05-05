/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include <stdio.h>
#include "structures.h"

map_t *create_graph(int x, int y);
void free_graph(map_t *node);
map_t *get_top_left_map(map_t *maps);
int check_maps(sfVector2f player_pos, scene_t *scene);
int init_map(char const *filepath, map_t *map);
void remove_endline(char *line);
int get_object_stats(FILE *stream, map_obj_t *obj, char *path);
void free_graph(map_t *node);
int add_particles(FILE *stream, map_t *map);
int add_enemy(FILE *stream, map_t *map);
int add_seller(FILE *stream, map_t *map);
map_obj_t *add_objects(char *path, int x, int y, map_obj_t *next);

#endif /* !MAP_H_ */
