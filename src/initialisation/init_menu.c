/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** init_menu
*/

#include "prototype.h"

static int cond_pos(sfVector2f pos1, sfVector2f pos2)
{
    if (pos1.x + 30 >= pos2.x && pos1.x + 30 <= pos2.x + 375 &&
        pos1.y + 55 >= pos2.y && pos1.y + 55 <= pos2.x + 55)
        return (1);
    return (0);
}

int init_start_button(but_s *button)
{
    sfVector2f pos;
    sfVector2f size;
    sfTexture *start = sfTexture_createFromFile("assets/textures/start.png", NULL);

    pos.x = 773;
    pos.y = 400;
    size.x = 375;
    size.y = 55;
    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfRed);
    sfRectangleShape_setOutlineThickness(button->but, 5);
    sfRectangleShape_setFillColor(button->but, sfWhite);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    sfRectangleShape_setTexture(button->but, start, sfFalse);
    return (1);
}

int init_end_button(but_s *button)
{
    sfVector2f pos;
    sfVector2f size;
    sfTexture *start = sfTexture_createFromFile("assets/textures/quit.png", NULL);

    pos.x = 860;
    pos.y = 600;
    size.x = 200;
    size.y = 37;
    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfRed);
    sfRectangleShape_setOutlineThickness(button->but, 5);
    sfRectangleShape_setFillColor(button->but, sfWhite);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    sfRectangleShape_setTexture(button->but, start, sfFalse);
    return (1);
}

int button_is_clicked(sfRectangleShape *button, sfVector2i click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button);
    sfVector2f size = sfRectangleShape_getSize(button);

    if (button_pos.x > click_position.x
        || button_pos.x + size.x < click_position.x)
        return (1);
    if (button_pos.y > click_position.y
        || button_pos.y + size.y < click_position.y)
        return (1);
    return (0);
}
