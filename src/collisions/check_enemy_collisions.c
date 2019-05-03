/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** check_enemy_collisions
*/

#include "structures.h"
#include "collisions.h"

int check_collision_with_player(obj_t *enemy, obj_t *player, sfVector2f dir)
{
    if (will_collide(player->sprite, enemy->sprite, dir))
        return (0);
    return (0);
}

int check_enemy_collision_scene(scene_t *scene, obj_t *enemy, sfVector2f dir)
{
    if (check_collision_objs(enemy->sprite, scene->map->objects, dir))
        return (1);
    if (check_collision_enemies(enemy, scene->map->enemies, dir))
        return (1);
    if (check_collision_npc(enemy->sprite, scene->pnj, dir))
        return (1);
    if (check_collision_with_player(enemy, scene->perso, dir))
        return (1);
    return (0);
}

int check_enemy_collision(scene_t *scene, obj_t *enemy, sfVector2f direction)
{
    if (check_enemy_collision_scene(scene, enemy, direction))
        return (1);
    return (0);
}
