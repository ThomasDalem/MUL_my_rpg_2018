/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_map
*/

#include <stdlib.h>
#include "prototype.h"
#include "structures.h"

static sfFloatRect add_collision_rect(sfSprite *sprite)
{
    sfFloatRect collision_rect;

    collision_rect = sfSprite_getGlobalBounds(sprite);
    if (collision_rect.height > 40)
        collision_rect.height -= 40;
    return (collision_rect);
}

static map_obj_t *add_objects(char *path, int x, int y, map_obj_t *next)
{
    map_obj_t *object = malloc(sizeof(map_obj_t));
    sfFloatRect col_rect;

    if (object == NULL)
        return (NULL);
    object->texture = sfTexture_createFromFile(path, NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfFalse);
    object->has_collider = 1;
    sfSprite_setPosition(object->sprite, (sfVector2f){x, y});
    object->collision_rect = add_collision_rect(object->sprite);
    object->next = next;
    return (object);
}

void create_map(map_t *map)
{
    char *path = "assets/textures/map_1.jpg";
    char *path_wall = "assets/textures/objects/wall_map_1.png";
    char *path_dispenser = "assets/textures/objects/desk.png";

    map->texture = sfTexture_createFromFile(path, NULL);
    map->sprite = sfSprite_create();
    sfSprite_setTexture(map->sprite, map->texture, sfFalse);
    map->objects = add_objects(path_wall, 0, 0, map->objects);
    map->objects = add_objects(path_dispenser, 500, 600, map->objects);
}
