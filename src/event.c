/*
** EPITECH PROJECT, 2019
** Tower Defense
** File description:
** Event gestion
*/

#include "prototype.h"

void reboot(scene_t *scene)
{
    int i = 0;

    while (scene->button[i] != NULL) {
        scene->button[i]->is_clicked = 0;
        i ++;
    }
}

int allevent(scene_t *scene, sfEvent *event, pause_s *pause, inv_t *invent)
{
    sfVector2i mouse;
    int r = 1;

    if (event->type == sfEvtKeyPressed) {
        switch (event->key.code) {
        case sfKeyA : move_player(scene->perso, LEFT);
            break;
        case sfKeyD : move_player(scene->perso, RIGHT);
            break;
        case sfKeyE : return (inventory_gestion(invent, scene));
        case sfKeyQ : move_player(scene->perso, LEFT);
            break;
        case sfKeyS : move_player(scene->perso, DOWN);
            break;
        case sfKeyZ : move_player(scene->perso, UP);
            break;
        case sfKeyT : start_discuss(scene);
            break;
        }
    }
    if (event->key.code == sfKeyEscape)
        return (pause_function(scene, pause));
    if (event->type == sfEvtClosed)
        return (3);
    return (1);
}
