/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** get_distance
*/

#include "structures.h"

sfVector2f get_distance(obj_t *enemy, obj_t *player)
{
    sfVector2f enemy_pos = sfSprite_getPosition(enemy->sprite);
    sfVector2f player_pos = sfSprite_getPosition(player->sprite);
    sfVector2f distance;

    distance.x = enemy_pos.x - player_pos.x;
    distance.y = enemy_pos.y - player_pos.y;
    return (distance);
}