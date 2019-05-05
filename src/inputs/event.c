/*
** EPITECH PROJECT, 2019
** Tower Defense
** File description:
** Event gestion
*/

#include "quest.h"
#include "prototype.h"

void reboot(but_s **button)
{
    int i = 0;

    while (button[i] != NULL) {
        button[i]->is_clicked = 0;
        i ++;
    }
}

int move_case(scene_t *scene, sfEvent *event)
{
    switch (event->key.code) {
        case sfKeyD : scene->perso->move_dir = RIGHT;
            break;
        case sfKeyQ : scene->perso->move_dir = LEFT;
            break;
        case sfKeyS : scene->perso->move_dir = DOWN;
            break;
        case sfKeyZ : scene->perso->move_dir = UP;
            break;
        default: scene->perso->move_dir = 0;
            break;
    }
    return (0);
}

int stop_movement(scene_t *scene, sfEvent *event)
{
    if (event->key.code == sfKeyD && scene->perso->move_dir == RIGHT)
        scene->perso->move_dir = 0;
    if (event->key.code == sfKeyQ && scene->perso->move_dir == LEFT)
        scene->perso->move_dir = 0;
    if (event->key.code == sfKeyZ && scene->perso->move_dir == UP)
        scene->perso->move_dir = 0;
    if (event->key.code == sfKeyS && scene->perso->move_dir == DOWN)
        scene->perso->move_dir = 0;
    return (0);
}

int allevent(scene_t *scene, sfEvent *event, pause_s *pause, inv_t *invent)
{
    if (event->type == sfEvtKeyPressed) {
        switch (event->key.code) {
        case sfKeyE : return (inventory_gestion(invent, scene));
        case sfKeyT : start_discuss(scene);
            break;
        }
        move_case(scene, event);
    }
    else if (event->type == sfEvtKeyReleased)
        stop_movement(scene, event);
    if (event->key.code == sfKeyEscape)
        return (pause_function(scene, pause));
    if (event->type == sfEvtClosed)
        return (3);
    return (1);
}
