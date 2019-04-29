/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_maps
*/

#include "prototype.h"
#include "structures.h"
#include "map.h"

void create_map1(map_t *map)
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

void create_map2(map_t *map)
{
    char *path = "assets/textures/map_1.jpg";
    char *path_wall = "assets/textures/objects/wall_map_1.png";
    char *path_dispenser = "assets/textures/objects/desk.png";

    map->texture = sfTexture_createFromFile(path, NULL);
    map->sprite = sfSprite_create();
    sfSprite_setTexture(map->sprite, map->texture, sfFalse);
    map->objects = add_objects(path_wall, 0, 0, map->objects);
    map->objects = add_objects(path_dispenser, 300, 300, map->objects);
}

void create_map3(map_t *map)
{
    char *path = "assets/textures/map_1.jpg";
    char *path_dispenser = "assets/textures/objects/desk.png";

    map->texture = sfTexture_createFromFile(path, NULL);
    map->sprite = sfSprite_create();
    sfSprite_setTexture(map->sprite, map->texture, sfFalse);
    map->objects = add_objects(path_dispenser, 342, 700, map->objects);
}

void create_map4(map_t *map)
{
    char *path = "assets/textures/map_1.jpg";
    char *path_dispenser = "assets/textures/objects/desk.png";

    map->texture = sfTexture_createFromFile(path, NULL);
    map->sprite = sfSprite_create();
    sfSprite_setTexture(map->sprite, map->texture, sfFalse);
    map->objects = add_objects(path_dispenser, 1000, 0, map->objects);
}