/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** switch_equipement
*/

#include "prototype.h"

void change_stat_perso(inv_t *invent, scene_t *scene, int j)
{
    sfVector2f pos_text;

    scene->perso->stat.attack += invent->stat_equip[j].attack;
    scene->perso->stat.defense += invent->stat_equip[j].defense;
    scene->perso->stat.magic += invent->stat_equip[j].magic;
    sfText_destroy(invent->attack);
    sfText_destroy(invent->defense);
    sfText_destroy(invent->magic);
    sfText_destroy(invent->life);
    set_text_inventory(invent, scene);
    set_pos_text(invent, pos_text);
}

int is_a_potion(scene_t *scene, inv_t *invent, int i)
{
    if (invent->button[i]->object.type == 1)
        return (1);
    if (scene->perso->fight->is_potion == 1) {
        sfClock_restart(invent->clock_potion);
        invent->color_potion.a = 255;
        sfText_setColor(invent->pot, invent->color_potion);
        return (0);
    }
    if (invent->button[i]->object.effect == 1) {
        scene->perso->stat.life+= invent->button[i]->object.capacities;
        remove_equipement(scene, invent, i);
        change_potion_str(invent, scene);
        return (0);
    }
    scene->perso->fight->is_potion = 1;
    sfClock_restart(scene->perso->fight->time_potion);
    set_potion_effect(scene, invent, i);
    change_potion_str(invent, scene);
    remove_equipement(scene, invent, i);
    return (0);
}

void switch_stat(scene_t *scene, inv_t *invent, int i)
{
    int j = invent->button[i]->object.effect - 1;
    int attack = invent->stat_equip[j].attack;
    int defense = invent->stat_equip[j].defense;
    int speed = invent->stat_equip[j].magic;
    sfVector2f pos = sfText_getPosition(invent->equipement[j]->txt);
    
    if (is_a_potion(scene, invent, i) == 0)
        return;
    invent->stat_equip[j].attack = invent->button[i]->object.damage;
    invent->stat_equip[j].defense = invent->button[i]->object.defense;
    invent->stat_equip[j].magic = invent->button[i]->object.magic;
    invent->button[i]->object.damage = attack;
    invent->button[i]->object.defense = defense;
    invent->button[i]->object.magic = speed;
    invent->stat_equip[j].life = 0;
    scene->perso->stat.attack -= attack;
    scene->perso->stat.defense -= defense;
    scene->perso->stat.magic -= speed;
    create_string_equip(invent->equipement[j], invent->stat_equip[j]);
    sfText_setPosition(invent->equipement[j]->txt, pos);
    change_stat_perso(invent, scene, j);
}

void remove_equipement(scene_t *scene, inv_t *invent, int i)
{
    invent->button[i]->object.cost = 0;
    invent->button[i]->object.type = 0;
    invent->button[i]->object.effect = 0;
    invent->button[i]->object.damage = 0;
    invent->button[i]->object.defense = 0;
    invent->button[i]->object.magic = 0;
    sfRectangleShape_setTexture(invent->button[i]->but, NULL, sfTrue);
}

int switch_equipement(scene_t *scene, inv_t *invent)
{
    int i = 0;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);

    while (invent->button[i] != NULL) {
        if (button_is_clicked(invent->button[i]->next[0].but, mouse) == 0 &&
            invent->button[i]->object.type != 0 
            && invent->button[i]->is_clicked == 1)
            switch_stat(scene, invent, i);
        if (button_is_clicked(invent->button[i]->next[1].but, mouse) == 0 && 
            invent->button[i]->object.type != 0
            && invent->button[i]->is_clicked == 1) {
            remove_equipement(scene, invent, i);
            invent->button[i]->is_clicked = 0;
            invent->button[i]->next[0].is_clicked = 0;
            invent->button[i]->next[1].is_clicked = 0;
        }
        i++;
    }
}