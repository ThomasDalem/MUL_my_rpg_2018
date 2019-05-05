/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** add_equipement
*/

#include "prototype.h"

void add_equipement_texture(inv_t *invent, int j)
{
    sfIntRect rect = {0, 0, 0, 0};
    sfTexture *texture = sfTexture_createFromFile(
        "assets/textures/equip.jpg", NULL);
    sfTexture *sw_te = sfTexture_createFromFile(
        "assets/textures/sword_icon.png", NULL);

    sfRectangleShape_setTexture(invent->button[j]->but, texture, sfTrue);
    if (invent->button[j]->object.effect == 1)
        rect = create_char_perso(37, 52, 200, 178);
    if (invent->button[j]->object.effect == 2)
        rect = create_char_perso(235, 13, 279, 258);
    if (invent->button[j]->object.effect == 3)
        rect = create_char_perso(513, 52, 200, 277);
    if (invent->button[j]->object.effect == 4)
        rect = create_char_perso(810, 13, 277, 188);
    sfRectangleShape_setTextureRect(invent->button[j]->but, rect);
    if (invent->button[j]->object.effect == 5) {
        sfRectangleShape_setTexture(invent->button[j]->but, sw_te, sfTrue);
        rect = create_char_perso(0, 0, 224, 224);
        sfRectangleShape_setTextureRect(invent->button[j]->but, rect);
    }
}

void add_new_equipement(scene_t *scene, inv_t *invent, int i, int j)
{
    invent->button[j]->object.type = 1;
    invent->button[j]->object.effect = scene->sell->things[i]->object.effect;
    invent->button[j]->object.damage = scene->sell->things[i]->object.damage;
    invent->button[j]->object.defense = scene->sell->things[i]->object.defense;
    invent->button[j]->object.magic = scene->sell->things[i]->object.magic;
    add_equipement_texture(invent, j);
    scene->perso->money-= scene->sell->things[i]->object.cost;
    set_money_text(scene);
}

void add_potion_equipement(scene_t *scene, inv_t *invent, int i, int j)
{
    invent->button[j]->object.type = 2;
    invent->button[j]->object.effect = scene->sell->things[i]->object.effect;
    invent->button[j]->object.duration = 
                                    scene->sell->things[i]->object.duration;
    invent->button[j]->object.capacities = 
        scene->sell->things[i]->object.capacities;
    invent->button[j]->object.cost = 0;
    add_equipement_texture(invent, j);
    init_disp_potion(invent->button[j]);
    scene->perso->money-= scene->sell->things[i]->object.cost;
    set_money_text(scene);
}

void set_new_equipement(scene_t *scene, inv_t *invent, int i)
{
    int j = 0;

    while (invent->button[j] != NULL && invent->button[j]->object.type != 0)
        j++;
    if (invent->button[j] == NULL) {
        scene->sell->color_place.a = 255;
        return;
    }
    if (scene->perso->money - scene->sell->things[i]->object.cost < 0) {
        scene->sell->color_money.a = 255;
        return;
    }
    if (scene->sell->things[i]->object.type == 1)
        add_new_equipement(scene, invent, i, j);
    if (scene->sell->things[i]->object.type == 2)
        add_potion_equipement(scene, invent, i, j);
}

void check_text(scene_t *scene)
{
    sfTime time_money = sfClock_getElapsedTime(scene->sell->clock_money);
    sfTime time_place = sfClock_getElapsedTime(scene->sell->clock_place);
    float second_money = sfTime_asSeconds(time_money);
    float second_place = sfTime_asSeconds(time_place);

    if (second_money > 0.01) {
        if (scene->sell->color_money.a > 0)
            scene->sell->color_money.a--;
        sfClock_restart(scene->sell->clock_money);
    }
    if (second_place > 0.01) {
        if (scene->sell->color_place.a > 0)
            scene->sell->color_place.a--;
        sfClock_restart(scene->sell->clock_place);
    }
}