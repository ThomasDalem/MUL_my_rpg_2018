/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_potion
*/

#include "prototype.h"

void  set_already_effect_str(inv_t *invent)
{
    char str[] = "you can not use 2 potions at the same time";
    sfVector2f pos = {1400, 400};

    invent->pot = sfText_create();
    set_text(invent->pot, str, invent->font, pos);
    invent->color_potion = (sfColor){255, 255, 255, 0};
    sfText_setPosition(invent->pot, pos);
    sfText_setColor(invent->pot, invent->color_potion);
    invent->clock_potion = sfClock_create();
}

void set_good_potion_effect(but_s *things, char *str)
{
    if (things->object.effect == 1)
        my_strcat(str, " LIVE = ");
    if (things->object.effect == 2)
        my_strcat(str, " ATTACK = ");
    if (things->object.effect == 3)
        my_strcat(str, " DEFENSE = ");
    if (things->object.effect == 4)
        my_strcat(str, " SPEED = ");
}

int create_potion_equip(but_s *button)
{
    char *str = malloc(sizeof(char) * 4096);

    button->font = sfFont_createFromFile("assets/texts/Timeless.ttf");
    if (str == NULL)
        return (84);
    my_strcpy(str, "COST = ");
    my_strcat(str, int_to_char(button->object.cost));
    if (button->object.duration != 0) {
        my_strcat(str, " DURATION = ");
        my_strcat(str, int_to_char(button->object.duration));
    }
    set_good_potion_effect(button, str);
    my_strcat(str, int_to_char(button->object.capacities));
    button->txt = sfText_create();
    sfText_setString(button->txt, str);
    sfText_setFont(button->txt, button->font);
    sfText_setCharacterSize(button->txt, 30);
    sfText_setColor(button->txt, sfWhite);
    return (0);
}

void init_potion_str(but_s *thing, char *str, int r)
{
    sfVector2f pos = sfRectangleShape_getPosition(thing->but);
    char **arr = my_str_to_word_array(str, ',');

    thing->object.capacities = my_getnbr(arr[1]);
    thing->object.duration = my_getnbr(arr[0]);
    thing->object.cost = my_getnbr(arr[2]);
    thing->font = sfFont_createFromFile("assets/texts/info.ttf");
    thing->txt = sfText_create();
    create_potion_equip(thing);
    pos.x = pos.x + 120;
    pos.y = pos.y + 40;
    sfText_setPosition(thing->txt, pos);
}

void init_disp_potion(but_s *things)
{
    sfTexture *texture = sfTexture_createFromFile(
        "assets/textures/potion.png", NULL);
    sfIntRect rect = {0, 0, 0, 0};

    sfRectangleShape_setTexture(things->but, texture, sfTrue);
    if (things->object.effect == 1)
        rect = create_char_perso(0, 0, 134, 134);
    if (things->object.effect == 2)
        rect = create_char_perso(134, 10, 134, 134);
    if (things->object.effect == 3)
        rect = create_char_perso(0, 134, 134, 134);
    if (things->object.effect == 4)
        rect = create_char_perso(134, 134, 134, 134);
    sfRectangleShape_setTextureRect(things->but, rect);
}
