/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** check_fight
*/

#include "prototype.h"

int start_fight(scene_t *scene, inv_t *invent, pause_s *pause)
{
    sfEvent event;
    int nb_perso;
    int fight = 1;

    while (sfRenderWindow_isOpen(scene->window) && fight == 1) {
        disp_scene(scene);
        move_ennemie(scene);
        while (sfRenderWindow_pollEvent(scene->window, &event)) {
            fight = fight_event(scene, &event, &pause, &invent);
        }
    }
    return (fight);
}

int is_a_fight(scene_t *scene, inv_t *invent, pause_s *pause)
{
    obj_t *enn = scene->ennemi;
    sfFloatRect pos_enn;
    sfFloatRect pos_perso = sfSprite_getGlobalBounds(scene->perso->sprite);
    int i = 0;

    while (scene->ennemi != NULL && i == 0) {
        pos_enn = sfSprite_getGlobalBounds(scene->ennemi->sprite);
        if (is_colliding(pos_enn, pos_perso)  == 1)
            i = start_fight(scene, invent, pause);
        scene->ennemi = scene->ennemi->next;
    }
    scene->ennemi = enn;
    return (i);
}