/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_map
*/

#include <stdlib.h>
#include "prototype.h"
#include "structures.h"

void create_map(map_t *map)
{
    char *path = "assets/textures/map_1.jpg";
    char *path_object = "assets/textures/objects.png";

    map->texture = sfTexture_createFromFile(path, NULL);
    map->sprite = sfSprite_create();
    sfSprite_setTexture(map->sprite, map->texture, sfFalse);
    map->objects = add_objects(path_object, 500, 500, map->objects);
    map->objects = add_objects(path_object, 1000, 1000, map->objects);
}

map_obj_t *add_objects(char *path, int x, int y, map_obj_t *next)
{
    map_obj_t *object = malloc(sizeof(map_obj_t));

    if (object == NULL)
        return (NULL);
    object->texture = sfTexture_createFromFile(path, NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfFalse);
    object->has_collider = 1;
    sfSprite_setPosition(object->sprite, (sfVector2f){x, y});
    object->next = next;
    return (object);
}