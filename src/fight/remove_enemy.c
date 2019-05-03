/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** remove_enemy
*/

#include "structures.h"
#include "fight.h"

void remove_enemy(obj_t *enemy, obj_t **list)
{
    obj_t *cursor = *list;
    obj_t *save = NULL;

    if (enemy == *list) {
        *list = (*list)->next;
        free_enemy(cursor);
        return;
    }
    while (cursor != NULL) {
        if (cursor->next == enemy) {
            save = cursor->next;
            cursor->next = cursor->next->next;
            free_enemy(save);
            return;
        }
        cursor = cursor->next;
    }
}
