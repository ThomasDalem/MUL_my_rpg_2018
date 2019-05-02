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
    sfTexture *start = sfTexture_createFromFile("assets/textures/button.jpg", NULL);

    pos.x = 773;
    pos.y = 400;
    size.x = 300;
    size.y = 100;
    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfTransparent);
    sfRectangleShape_setOutlineThickness(button->but, 2);
    sfRectangleShape_setFillColor(button->but, sfWhite);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    sfRectangleShape_setTexture(button->but, start, sfFalse);
    button->txt = sfText_create();
    button->font = sfFont_createFromFile("assets/texts/menu.otf");
    set_text(button->txt, "play", button->font, (sfVector2f){880, 423});
    return (1);
}

int init_end_button(but_s *button)
{
    sfVector2f pos;
    sfVector2f size;
    sfTexture *start = sfTexture_createFromFile("assets/textures/button.jpg", NULL);

    pos.x = 773;
    pos.y = 600;
    size.x = 300;
    size.y = 100;
    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfTransparent);
    sfRectangleShape_setOutlineThickness(button->but, 2);
    sfRectangleShape_setFillColor(button->but, sfWhite);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    sfRectangleShape_setTexture(button->but, start, sfFalse);
    button->txt = sfText_create();
    button->font = sfFont_createFromFile("assets/texts/menu.otf");
    set_text(button->txt, "quit", button->font, (sfVector2f){885, 625});
    return (1);
}

int init_fs_button(but_s *button)
{
    sfVector2f pos;
    sfVector2f size;
    sfTexture *start = sfTexture_createFromFile("assets/textures/button.jpg", NULL);

    pos.x = 200;
    pos.y = 700;
    size.x = 300;
    size.y = 100;
    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfTransparent);
    sfRectangleShape_setOutlineThickness(button->but, 2);
    sfRectangleShape_setFillColor(button->but, sfWhite);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    sfRectangleShape_setTexture(button->but, start, sfFalse);
    button->txt = sfText_create();
    button->font = sfFont_createFromFile("assets/texts/menu.otf");
    set_text(button->txt, "Fullscreen", button->font, (sfVector2f){200, 713});
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
