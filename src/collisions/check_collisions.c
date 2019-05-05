/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** check_collisions
*/

#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include <stdio.h>
#include "collisions.h"

int check_collision_objs(sfSprite *player, map_obj_t *objects, sfVector2f dir)
{
    sfFloatRect player_rect = sfSprite_getGlobalBounds(player);

    while (objects) {
        if (will_rect_collide(player_rect, objects->collision_rect, dir) &&
            objects->has_collider)
            return (1);
        objects = objects->next;
    }
    return (0);
}

int check_collision_enemies(obj_t *character, obj_t *enemies, sfVector2f dir)
{
    while (enemies) {
        if (will_collide(character->sprite, enemies->sprite, dir)
            && character != enemies) {
            return (1);
        }
        enemies = enemies->next;
    }
    return (0);
}

int check_collision_npc(sfSprite *player, obj_t *npc, sfVector2f dir)
{
    while (npc) {
        if (will_collide(player, npc->sprite, dir))
            return (1);
        npc = npc->next;
    }
    return (0);
}

int check_collision_scene(scene_t *scene, sfSprite *player, sfVector2f dir)
{
    if (check_collision_objs(player, scene->map->objects, dir))
        return (1);
    if (check_collision_enemies(scene->perso, scene->map->enemies, dir))
        return (1);
    if (check_collision_npc(player, scene->map->pnj, dir))
        return (1);
    return (0);
}

int check_collision(scene_t *scene, sfVector2f direction)
{
    if (check_collision_scene(scene, scene->perso->sprite, direction))
        return (1);
    return (0);
}
