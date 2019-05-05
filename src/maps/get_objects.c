/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Get objects from map's files
*/

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

static map_obj_t *create_object(map_obj_t *next_obj, FILE *stream, char *path)
{
    map_obj_t *object = malloc(sizeof(map_obj_t));
    char *line = NULL;
    size_t len = 0;
    sfVector2f pos;

    if (object == NULL)
        return (NULL);
    if (get_object_stats(stream, object, path) == 84)
        return (NULL);
    object->collision_rect = add_collision_rect(object->sprite);
    object->next = next_obj;
    return (object);
}

static int get_object_type(char *str, map_t *map, FILE *stream)
{
    char const *types[4] = {"sparks\n", "enemy\n", "seller\n", NULL};
    int (*add_functions[4])(FILE *stream, map_t *map) = {&add_particles,
                                                        &add_enemy,
                                                        &add_seller
                                                        };

    for (int i = 0; types[i] != NULL; i++) {
        if (my_strcmp(str, types[i]) == 0) {
            add_functions[i](stream, map);
            return (1);
        }
    }
    map->objects = create_object(map->objects, stream, str);
    return (0);
}

static int add_objects_to_map(map_t *map, FILE *stream)
{
    map_obj_t *save = NULL;
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, stream) != -1) {
        get_object_type(line, map, stream);
        line = NULL;
    }
    return (1);
}

int init_map(char const *filepath, map_t *map)
{
    FILE *stream = fopen(filepath, "r");

    if (stream == NULL) {
        write(2, "Error open\n", 11);
        return (84);
    }
    add_objects_to_map(map, stream);
    fclose(stream);
    return (0);
}
