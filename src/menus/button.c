/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button
*/

#include "inventory.h"

void button_disp(but_s **button, scene_t *scene)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);
    int i = 0;

    while (button[i] != NULL) {
        if (button_is_clicked(button[i]->but, mouse) == 0 &&
            button[i]->is_clicked == 0)
            sfRectangleShape_setOutlineColor(button[i]->but, sfWhite);
        else if (button[i]->is_clicked == 1 &&
                button_is_clicked(button[i]->but, mouse) == 0)
            sfRectangleShape_setOutlineColor(button[i]->but, sfBlue);
        else
            sfRectangleShape_setOutlineColor(button[i]->but, sfRed);
        i++;
    }
}

void check_all_button(but_s **button, scene_t *scene)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);
    int i = 0;
    int j = 0;

    while (button[i] != NULL) {
        if (button_is_clicked(button[i]->but, mouse) == 0) {
            button[i]->is_clicked = 1;
        }
        else
            button[i]->is_clicked = 0;
        i ++;
    }
}
