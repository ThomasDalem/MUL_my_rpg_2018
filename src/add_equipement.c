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
    sfTexture *texture = sfTexture_createFromFile("assets/textures/equip.jpg", NULL);
    sfTexture *sw_texture = sfTexture_createFromFile("assets/textures/sword_icon.png", NULL);

    sfRectangleShape_setTexture(invent->button[j]->but, texture, sfTrue);
    if (invent->button[j]->object.effect == 1) 
        rect = create_char_perso(37, 52, 200, 178);
    if (invent->button[j]->object.effect == 2) 
        rect = create_char_perso(235, 13, 279, 258);
    if (invent->button[j]->object.effect == 3) 
        rect = create_char_perso(513, 52, 200, 277);
    if (invent->button[j]->object.effect == 4) 
        rect = create_char_perso(810, 13, 277, 188);
    if (rect.top != 0)
        sfRectangleShape_setTextureRect(invent->button[j]->but, rect);
    if (invent->button[j]->object.effect == 5) {
        sfRectangleShape_setTexture(invent->button[j]->but, sw_texture, sfTrue);
        rect = create_char_perso(0, 0, 224, 224);
        sfRectangleShape_setTextureRect(invent->button[j]->but, rect);
    }
}

void add_new_equipement(scene_t *scene, inv_t *invent, int i)
{
    int j = 0;
    sfIntRect rect;

    while (invent->button[j] != NULL && invent->button[j]->object.type != 0)
        j++;
    if (invent->button[j] == NULL)
        return;
    if (scene->perso->money < 20)
        printf("non c'est mort, tu dégage le pauvre\n");
    invent->button[j]->object.type = 1;
    invent->button[j]->object.effect = scene->sell->things[i]->object.effect;
    invent->button[j]->object.damage = scene->sell->things[i]->object.damage;
    invent->button[j]->object.defense = scene->sell->things[i]->object.defense;
    invent->button[j]->object.magic = scene->sell->things[i]->object.magic;
    add_equipement_texture(invent, j);
    scene->perso->money-= scene->sell->things[i]->object.cost;
    set_money_text(scene);
}