/*
** EPITECH PROJECT, 2019
** Tower Defense
** File description:
** Event gestion
*/

#include "prototype.h"

void reboot(but_s **button)
{
    int i = 0;

    while (button[i] != NULL) {
        button[i]->is_clicked = 0;
        i++;
    }
}

int move_case(scene_t *scene, sfEvent *event)
{
    switch (event->key.code) {
        case sfKeyA : move_player(scene, scene->perso, LEFT);
            break;
        case sfKeyD : move_player(scene, scene->perso, RIGHT);
            break;
        case sfKeyQ : move_player(scene, scene->perso, LEFT);
            break;
        case sfKeyS : move_player(scene, scene->perso, DOWN);
            break;
        case sfKeyZ : move_player(scene, scene->perso, UP);
            break;
    }
    return (0);
}

int allevent(scene_t *scene, sfEvent *event, pause_s *pause, inv_t *invent)
{
    sfVector2i mouse;
    int r = 1;

    if (event->type == sfEvtKeyPressed) {
        switch (event->key.code) {
        case sfKeyE : return (inventory_gestion(invent, scene));
        case sfKeyT : start_discuss(scene);
            break;
        }
        move_case(scene, event);
    }
    if (event->key.code == sfKeyEscape)
        return (pause_function(scene, pause));
    if (event->type == sfEvtClosed)
        return (3);
    return (1);
}
