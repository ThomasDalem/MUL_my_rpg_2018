/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** quest_end
*/

#include <stdlib.h>
#include "structures.h"
#include "map.h"

int check_enemies_in_map(map_t *map, int id)
{
    obj_t *enemies = map->enemies;

    while (enemies) {
        if (enemies->id == id)
            return (0);
        enemies = enemies->next;
    }
    return (1);
}

int check_line_enemies(map_t *col, int check_id)
{
    for (map_t *line = col; line != NULL; line = line->right) {
        if (check_enemies_in_map(line, check_id) == 0)
            return (0);
    }
    return (1);
}

int check_quest_kill(void *obj, void *check)
{
    map_t *maps = get_top_left_map((map_t *)obj);
    int *check_id = (int *)check;

    for (map_t *col = maps; col != NULL; col = col->down) {
        if (check_line_enemies(col, *check_id) == 0)
            return (0);
    }
    return (1);
}

int check_quests(scene_t *scene, quest_t *quests)
{
    if (quests == NULL)
        return (0);
    if (quests->check_quest_end != NULL &&
        quests->check_quest_end(scene->map, &quests->objective_id) == 1) {
        scene->quest = scene->quest->next;
        scene->perso->money += quests->money;
        return (1);
    }
    return (0);
}
