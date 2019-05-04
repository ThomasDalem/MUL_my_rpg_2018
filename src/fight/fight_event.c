/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** fight_event
*/

#include "prototype.h"

void fight_key_event(scene_t *scene, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed) {
        switch (event->key.code) {
        case sfKeyD : move_fight(scene, RIGHT);
            break;
        case sfKeyQ : move_fight(scene, LEFT);
            break;
        }
    }
}

int fight_event(scene_t *scene, sfEvent *event, pause_s *pause, inv_t *invent)
{
    if (event->type == sfEvtKeyPressed) {
        switch (event->key.code) {
        case sfKeyE : return (inventory_gestion(invent, scene));
        case sfKeyZ : jump(scene);
            break;
        case sfKeyK : attack(scene->perso, scene->ennemi);
            break;
        case sfKeyM : defense(scene->perso);
            break;
        case sfKeyP : scene->ennemi->stat.life = 0;
            break;
        }
        fight_key_event(scene, event);
    }
    if (event->key.code == sfKeyEscape)
        return (pause_function(scene, pause));
    if (event->type == sfEvtClosed)
        return (3);
    return (1);
}