/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Get objects from map's files
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include "prototype.h"
#include "structures.h"
#include "my.h"
#include "map.h"

static sfFloatRect add_collision_rect(sfSprite *sprite)
{
    sfFloatRect collision_rect;

    collision_rect = sfSprite_getGlobalBounds(sprite);
    if (collision_rect.height > 40)
        collision_rect.height -= 40;
    return (collision_rect);
}


static map_obj_t *create_object(map_obj_t *next_obj, FILE *stream)
{
    map_obj_t *object = malloc(sizeof(map_obj_t));
    char *line = NULL;
    size_t len = 0;
    sfVector2f pos;

    if (object == NULL)
        return (NULL);
    if (getline(&line, &len, stream) == -1)
        return (NULL);
    remove_endline(line);
    object->texture = sfTexture_createFromFile(line, NULL);
    object->sprite = sfSprite_create();
    if (getline(&line, &len, stream) == -1)
        return (NULL);
    pos.x = my_getnbr(line);
    if (getline(&line, &len, stream) == -1)
        return (NULL);
    pos.y = my_getnbr(line);
    sfSprite_setTexture(object->sprite, object->texture, sfFalse);
    sfSprite_setPosition(object->sprite, pos);
    object->next = next_obj;
    if (getline(&line, &len, stream) == -1)
        return (NULL);
    object->has_collider = my_getnbr(line);
    object->collision_rect = add_collision_rect(object->sprite);
    return (object);
}

static int add_objects_to_map(map_t *map, FILE *stream)
{
    map_obj_t *save = NULL;

    map->objects = create_object(map->objects, stream);
    while (map->objects != NULL) {
        save = map->objects;
        map->objects = create_object(map->objects, stream);
    }
    map->objects = save;
    return (1);
}

int init_map(char const *filepath, map_t *map)
{
    FILE *stream = fopen(filepath, "r");

    if (stream == NULL) {
        write(2, "Error open\n", 11);
        fclose(stream);
        return (84);
    }
    add_objects_to_map(map, stream);
    fclose(stream);
    return (0);
}
