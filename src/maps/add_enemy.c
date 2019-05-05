/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** add_enemy
*/

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "my.h"
#include "prototype.h"

static sfVector2f get_pos(FILE *stream)
{
    char *line = NULL;
    size_t len = 0;
    sfVector2f pos = {-1, -1};

    if (getline(&line, &len, stream) == -1)
        return (pos);
    pos.x = my_getnbr(line);
    free(line);
    line = NULL;
    if (getline(&line, &len, stream) == -1)
        return (pos);
    pos.y = my_getnbr(line);
    return (pos);
}

static int get_id(FILE *stream)
{
    char *line = NULL;
    size_t len = 0;
    int id = 0;

    if (getline(&line, &len, stream) == -1)
        return (-1);
    id = my_getnbr(line);
    free(line);
    return (id);
}

static obj_t *create_enemy(FILE *stream, obj_t *next)
{
    obj_t *enemy = malloc(sizeof(obj_t));

    if (enemy == NULL)
        return (NULL);
    create_ennemie(enemy);
    sfSprite_setPosition(enemy->sprite, get_pos(stream));
    enemy->id = get_id(stream);
    if (enemy->id == -1)
        return (NULL);
    if (init_fight_perso(enemy) == 84)
        return (NULL);
    create_zone_enn(enemy, 150);
    enemy->anim_clock = sfClock_create();
    enemy->move_clock = sfClock_create();
    enemy->dir_clock = sfClock_create();
    enemy->move_dir = 0;
    enemy->next = next;
    return (enemy);
}

int add_enemy(FILE *stream, map_t *map)
{
    map->enemies = create_enemy(stream, map->enemies);
    if (map->enemies == NULL)
        return (84);
    return (1);
}
