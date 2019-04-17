/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** fight_event
*/

#include "prototype.h"

int fight_event(scene_t *scene, sfEvent *event, pause_s *pause, inv_t *invent)
{
    sfVector2i mouse;
    int r = 1;

    if (event->type == sfEvtKeyPressed) {
        switch (event->key.code) {
        case sfKeyD : right_move(scene->perso);
            break;
        case sfKeyE : return (inventory_gestion(invent, scene));
        case sfKeyQ : left_move(scene->perso);
            break;
        case sfKeyZ : jump_mve(scene->perso);
            break;
        case sfKeyK : attack(scene);
            break;
        }
    }
    if (event->key.code == sfKeyEscape)
        return (pause_function(scene, pause));
    if (event->type == sfEvtClosed)
        return (3);
    return (1);
}
