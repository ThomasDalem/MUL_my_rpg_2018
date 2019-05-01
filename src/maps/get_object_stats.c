/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** get_object_stats
*/

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics/Texture.h>
#include "structures.h"
#include "map.h"
#include "my.h"

static int get_texture(char *path, map_obj_t *obj)
{
    remove_endline(path);
    obj->texture = sfTexture_createFromFile(path, NULL);
    free(path);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    return (0);
}

static int get_pos(FILE *stream, map_obj_t *obj)
{
    char *line = NULL;
    size_t len = 0;
    sfVector2f pos;

    if (getline(&line, &len, stream) == -1)
        return (84);
    pos.x = my_getnbr(line);
    free(line);
    line = NULL;
    if (getline(&line, &len, stream) == -1)
        return (84);
    pos.y = my_getnbr(line);
    free(line);
    sfSprite_setPosition(obj->sprite, pos);
    return (0);
}

static int get_collider(FILE *stream, map_obj_t *obj)
{
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, stream) == -1)
        return (84);
    obj->has_collider = my_getnbr(line);
    free(line);
    return (0);
}

int get_object_stats(FILE *stream, map_obj_t *obj, char *path)
{
    if (get_texture(path, obj))
        return (84);
    if (get_pos(stream, obj))
        return (84);
    if (get_collider(stream, obj))
        return (84);
    return (0);
}
