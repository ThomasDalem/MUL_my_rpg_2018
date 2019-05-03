/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_equipement
*/

#include "prototype.h"

int create_string_equip(but_s *button, struct stats equip)
{
    char *str = malloc(sizeof(char) * 4096);

    button->font = sfFont_createFromFile("assets/texts/Timeless.ttf");
    if (str == NULL)
        return (84);
    if (equip.life != 0) {
        my_strcpy(str, "COST = ");
        my_strcat(str, int_to_char(equip.life));
        my_strcat(str, " ATTACK = ");
    }
    else
        my_strcpy(str, "ATTACK = ");
    my_strcat(str, int_to_char(equip.attack));
    my_strcat(str, " DEFENSE = ");
    my_strcat(str, int_to_char(equip.defense));
    my_strcat(str, " SPEED = ");
    my_strcat(str, int_to_char(equip.magic));
    button->txt = sfText_create();
    sfText_setString(button->txt, str);
    sfText_setFont(button->txt, button->font);
    sfText_setCharacterSize(button->txt, 30);
    sfText_setColor(button->txt, sfWhite);
    return (0);
}

void create_icone(but_s *button, int x, int y)
{
    sfIntRect rect;

    if (y == 20)
        rect = create_char_perso(37, 52, 200, 178);
    if (y == 120)
        rect = create_char_perso(235, 13, 279, 258);
    if (y == 220)
        rect = create_char_perso(513, 52, 200, 277);
    if (y == 320)
        rect = create_char_perso(810, 13, 277, 188);
    sfRectangleShape_setTextureRect(button->but, rect);
}

void init_helmet(but_s *button, int x, int y, struct stats equip)
{
    sfVector2f pos = {x, y};
    sfVector2f size = {100, 90};
    sfTexture *texture = sfTexture_createFromFile(
        "assets/textures/equip.jpg", NULL);

    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfWhite);
    sfRectangleShape_setOutlineThickness(button->but, 1);
    sfRectangleShape_setFillColor(button->but, sfWhite);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    if (y >= 20 && y <= 320) {
        sfRectangleShape_setTexture(button->but, texture, sfFalse);
        create_icone(button, x, y);
    }
    create_string_equip(button, equip);
    pos.x = pos.x + 130;
    sfText_setPosition(button->txt, pos);
}

void init_sword(but_s *button, int x, int y, struct stats equip)
{
    sfVector2f pos = {x, y};
    sfVector2f size = {100, 90};
    sfIntRect rect = create_char_perso(0, 0, 224, 224);
    sfTexture *texture = sfTexture_createFromFile(
        "assets/textures/sword_icon.png", NULL);

    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfWhite);
    sfRectangleShape_setOutlineThickness(button->but, 1);
    sfRectangleShape_setFillColor(button->but, sfWhite);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    sfRectangleShape_setTexture(button->but, texture, sfFalse);
    create_string_equip(button, equip);
    sfRectangleShape_setTextureRect(button->but, rect);
    pos.x = pos.x + 130;
    sfText_setPosition(button->txt, pos);
}

int set_equipement(inv_t *invent, scene_t *scene)
{
    int i = 0;
    int j = 0;

    invent->equipement = malloc(sizeof(but_s) * 6);
    if (invent->equipement == NULL)
        return (84);
    while (i != 5) {
        invent->equipement[i] = malloc(sizeof(but_s));
        if (invent->equipement[i] == NULL)
            return (84);
        i++;
    }
    invent->equipement[i] = NULL;
    init_helmet(invent->equipement[0], 300, 20, invent->stat_equip[0]);
    init_helmet(invent->equipement[1], 300, 120, invent->stat_equip[1]);
    init_helmet(invent->equipement[2], 300, 220, invent->stat_equip[2]);
    init_helmet(invent->equipement[3], 300, 320, invent->stat_equip[3]);
    init_sword(invent->equipement[4], 300, 420, invent->stat_equip[4]);
}
