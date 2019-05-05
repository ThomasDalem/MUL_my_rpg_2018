/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** set_potion_str
*/

#include "prototype.h"

void set_potion_effect(scene_t *scene, inv_t *invent, int i)
{
    if (invent->button[i]->object.effect == 2) 
        scene->perso->stat.attack+= invent->button[i]->object.capacities;
    if (invent->button[i]->object.effect == 3) 
        scene->perso->stat.defense+= invent->button[i]->object.capacities;
    if (invent->button[i]->object.effect == 4)
        scene->perso->stat.magic+= invent->button[i]->object.capacities;
    scene->perso->fight->type = invent->button[i]->object.effect;
    scene->perso->fight->effect = invent->button[i]->object.capacities;
}

void change_potion_str(inv_t *invent, scene_t *scene)
{
    sfVector2f pos_text;

    sfText_destroy(invent->attack);
    sfText_destroy(invent->defense);
    sfText_destroy(invent->magic);
    sfText_destroy(invent->life);
    set_text_inventory(invent, scene);
    set_pos_text(invent, pos_text);
}