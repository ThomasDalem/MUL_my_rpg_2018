/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** mouse
*/

#include "prototype.h"

void cond_mouse(but_s **button, scene_t *scene)
{
    int i = 0;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);

    while (button[i] != NULL) {
        if (button_is_clicked(button[i]->but, mouse) == 0 &&
            button[i]->is_clicked == 0)
            sfRectangleShape_setOutlineColor(button[i]->but, sfWhite);
        else if (button[i]->is_clicked == 0)
            sfRectangleShape_setOutlineColor(button[i]->but, sfRed);
        i ++;
    }
}
