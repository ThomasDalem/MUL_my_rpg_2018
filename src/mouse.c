/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** mouse
*/

#include "prototype.h"

void cond_mouse(scene_t *scene)
{
    int i = 0;

    while (scene->button[i] != NULL) {
        if (button_is_clicked(scene->button[i]->but,
                              sfMouse_getPositionRenderWindow
                              (scene->window)) == 0 &&
            scene->button[i]->is_clicked == 0)
            sfRectangleShape_setOutlineColor(scene->button[i]->but, sfWhite);
        else if (scene->button[i]->is_clicked == 0)
            sfRectangleShape_setOutlineColor(scene->button[i]->but, sfRed);
        i++;
    }
}