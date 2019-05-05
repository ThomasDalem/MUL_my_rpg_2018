/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** inventory_use_throw
*/

#include "prototype.h"

void check_all_use_throw_button(but_s **button, scene_t *scene)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);
    int i = 0;
    int j = 0;

    while (button[i] != NULL) {
        if (button_is_clicked(button[i]->next[0].but, mouse) == 0)
            button[i]->next[0].is_clicked = 1;
        else
            button[i]->next[0].is_clicked = 0;
        if (button_is_clicked(button[i]->next[1].but, mouse) == 0)
            button[i]->next[1].is_clicked = 1;
        else
            button[i]->next[1].is_clicked = 0;
        i ++;
    }
}

void button_use_throw_disp(but_s *button, scene_t *scene)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);
    int i = 0;

    while (i != 2) {
        if (button_is_clicked(button->next[i].but, mouse) == 0 &&
            button->next[i].is_clicked == 0)
            sfRectangleShape_setOutlineColor(button->next[i].but, sfWhite);
        else if (button->next[i].is_clicked == 1 &&
                button_is_clicked(button->next[i].but, mouse) == 0)
            sfRectangleShape_setOutlineColor(button->next[i].but, sfBlue);
        else
            sfRectangleShape_setOutlineColor(button->next[i].but, sfRed);
        i ++;
    }
}

void use_throw_gestion(but_s **button, scene_t *scene)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);
    int i = 0;

    while (button[i] != NULL) {
        button_use_throw_disp(button[i], scene);
        i ++;
    }
}

int check_use_throw(but_s *button, sfVector2i mouse)
{
    if (button_is_clicked(button->next[0].but, mouse) == 0) {
        button->next[0].is_clicked = 1;
        return (1);
    }
    else
        button->next[0].is_clicked = 1;
    if (button_is_clicked(button->next[1].but, mouse) == 0) {
        button->next[1].is_clicked = 1;
        return (1);
    }
    else
        button->next[1].is_clicked = 1;
    return (0);
}

int cond_use_throw(but_s **button, scene_t *scene)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);
    int i = 0;
    int r = 0;

    while (button[i] != NULL) {
        if (button[i]->is_clicked == 1) {
            r = check_use_throw(button[i], mouse);
            return (r);
        }
        i ++;
    }
    return (0);
}
