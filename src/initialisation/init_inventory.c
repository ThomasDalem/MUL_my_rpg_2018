/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** init_inventory
*/

#include "prototype.h"

int set_text_inventory(inv_t *invent, scene_t *scene)
{
    invent->attack = sfText_create();
    invent->defense = sfText_create();
    invent->magic = sfText_create();
    invent->life = sfText_create();
    sfText_setString(invent->life, set_life_str(scene->perso));
    sfText_setString(invent->attack, set_attack_str(scene->perso));
    sfText_setString(invent->defense, set_defense_str(scene->perso));
    sfText_setString(invent->magic, set_magic_str(scene->perso));
    sfText_setFont(invent->life, invent->font);
    sfText_setFont(invent->attack, invent->font);
    sfText_setFont(invent->defense, invent->font);
    sfText_setFont(invent->magic, invent->font);
    sfText_setColor(invent->life, sfWhite);
    sfText_setColor(invent->attack, sfWhite);
    sfText_setColor(invent->defense, sfWhite);
    sfText_setColor(invent->magic, sfWhite);
    sfText_setCharacterSize(invent->life, 50);
    sfText_setCharacterSize(invent->attack, 50);
    sfText_setCharacterSize(invent->defense, 50);
    sfText_setCharacterSize(invent->magic, 50);
    return (1);
}

void set_pos_text(inv_t *invent, sfVector2f pos_text)
{
    pos_text.x = 1500;
    pos_text.y = 20;
    sfText_setPosition(invent->life, pos_text);
    pos_text.y = 80;
    sfText_setPosition(invent->attack, pos_text);
    pos_text.y = 140;
    sfText_setPosition(invent->defense, pos_text);
    pos_text.y = 200;
    sfText_setPosition(invent->magic, pos_text);
}

void init_button(but_s *button, int x, int y)
{
    sfVector2f pos;
    sfVector2f size;

    pos.x = x;
    pos.y = y;
    button->next = malloc(sizeof(but_s) * 2);
    size.x = 150;
    size.y = 150;
    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfBlue);
    sfRectangleShape_setOutlineThickness(button->but, 3);
    sfRectangleShape_setFillColor(button->but, sfWhite);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    create_use_button(&button->next[0], x, y);
    create_throw_button(&button->next[1], x + 75, y);
}

int init_inventory_button(inv_t *invent)
{
    int i = 0;
    int j = 0;
    int x = 10;

    while (i < 10) {
        invent->button[i] = malloc(sizeof(but_s));
        if (invent->button[i] == NULL)
            return (84);
        i++;
    }
    invent->button[10] == NULL;
    while (j != 10) {
        init_button(invent->button[j], x, 800);
        invent->button[j]->object.type = 0;
        j++;
        x = x + 160;
    }
    return (0);
}

int init_inventory(inv_t *invent, scene_t *scene)
{
    sfVector2f pos_sprite = {50, 50};
    sfVector2f pos_text;

    invent->font = sfFont_createFromFile("./assets/texts/pause.ttf");
    invent->button = malloc(sizeof(but_s) * 11);
    if (invent->button == NULL || set_text_inventory(invent, scene) == 84)
        return (84);
    invent->sprite = sfSprite_create();
    memset(invent->button, 0, sizeof(but_s) * 11);
    if (init_inventory_button(invent) == 84)
        return (84);
    set_pos_text(invent, pos_text);
    set_sprite_inventory(invent, scene, pos_sprite);
    set_stats_equipement(invent);
    set_equipement(invent, scene);
    set_already_effect_str(invent);
    return (0);
}
