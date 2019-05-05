/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** add_seller
*/

#include <stdio.h>
#include "structures.h"
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

int add_seller(FILE *stream, map_t *map)
{
    obj_t *npc = malloc(sizeof(obj_t));
    sfVector2f pos = get_pos(stream);

    if (npc == NULL || pos.x == -1 || pos.y == -1)
        return (84);
    create_pnj(npc);
    if (init_pnj_phrase(npc) == 84)
        return (84);
    sfSprite_setPosition(npc->sprite, pos);
    create_zone_enn(npc, 50);
    npc->anim_clock = sfClock_create();
    npc->next = map->pnj;
    map->pnj = npc;
    return (1);
}
