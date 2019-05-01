/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_use_throw_button
*/

#include "prototype.h"

void create_use_button(but_s *button, int x, int y)
{
    sfVector2f pos = {x, y- 40};
    sfVector2f size = {70, 30};

    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfRed);
    sfRectangleShape_setOutlineThickness(button->but, 3);
    sfRectangleShape_setFillColor(button->but, sfTransparent);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    button->txt = sfText_create();
    button->font = sfFont_createFromFile("assets/texts/menu.otf");
    set_text(button->txt, "use", button->font, (sfVector2f){x + 2, y - 38});
    sfText_setCharacterSize(button->txt, 23);
}

void create_throw_button(but_s *button, int x, int y)
{
    sfVector2f pos = {x, y - 40};
    sfVector2f size = {70, 30};

    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfRed);
    sfRectangleShape_setOutlineThickness(button->but, 3);
    sfRectangleShape_setFillColor(button->but, sfTransparent);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    button->txt = sfText_create();
    button->font = sfFont_createFromFile("assets/texts/menu.otf");
    set_text(button->txt, "throw", button->font, (sfVector2f){x + 2, y - 38});
    sfText_setCharacterSize(button->txt, 23);
}
