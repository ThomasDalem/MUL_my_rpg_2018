/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** change_map
*/

#include <stdio.h>
#include "prototype.h"
#include "structures.h"

static sfVector2f change_player_pos(map_t *map, map_t *prev_map, sfVector2f pos)
{
    pos.x = (prev_map == map->left) ? 0 : pos.x;
    pos.x = (prev_map == map->right) ? 1920 : pos.x;
    pos.y = (prev_map == map->up) ? 0 : pos.y;
    pos.y = (prev_map == map->down) ? 1080 : pos.y;
    return (pos);
}

int check_maps(sfVector2f player_pos, scene_t *scene)
{
    map_t *next_map = NULL;

    next_map = (player_pos.x > 1920) ? scene->map->right : next_map;
    next_map = (player_pos.x < -20) ? scene->map->left : next_map;
    next_map = (player_pos.y > 1090) ? scene->map->down : next_map;
    next_map = (player_pos.y < -20) ? scene->map->up : next_map;
    if (next_map) {
        player_pos = sfSprite_getPosition(scene->perso->sprite);
        player_pos = change_player_pos(next_map, scene->map, player_pos);
        scene->map = next_map;
        sfSprite_setPosition(scene->perso->sprite, player_pos);
    }
    return (0);
}
