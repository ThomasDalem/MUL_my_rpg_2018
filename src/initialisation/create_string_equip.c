/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_string_equip
*/

#include "prototype.h"

void set_string_equip(but_s *button, char *str)
{
    button->txt = sfText_create();
    sfText_setString(button->txt, str);
    sfText_setFont(button->txt, button->font);
    sfText_setCharacterSize(button->txt, 30);
    sfText_setColor(button->txt, sfWhite);
}

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
    set_string_equip(button, str);
    return (0);
}