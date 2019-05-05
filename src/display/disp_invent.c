/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** disp_invent
*/

#include "prototype.h"

void disp_invent_button(scene_t *scene, inv_t *invent)
{
    int i = 0;

    while (invent->button[i] != NULL) {
        sfRenderWindow_drawRectangleShape(scene->window, 
                                        invent->button[i]->but, NULL);
        if (invent->button[i]->is_clicked == 1) {
            sfRenderWindow_drawRectangleShape(scene->window,
                                            invent->button[i]->next[0].but,
                                            NULL);
            sfRenderWindow_drawText(scene->window,
                                    invent->button[i]->next[0].txt, NULL);
            sfRenderWindow_drawRectangleShape(scene->window,
                                            invent->button[i]->next[1].but,
                                            NULL);
            sfRenderWindow_drawText(scene->window,
                                    invent->button[i]->next[1].txt,
                                    NULL);
        }
        i ++;
    }
}

void disp_invent(scene_t *scene, inv_t *invent)
{
    int j = 0;

    sfRenderWindow_drawSprite(scene->window, invent->sprite, NULL);
    sfRenderWindow_drawText(scene->window, invent->life, NULL);
    sfRenderWindow_drawText(scene->window, invent->attack, NULL);
    sfRenderWindow_drawText(scene->window, invent->defense, NULL);
    sfRenderWindow_drawText(scene->window, invent->magic, NULL);
    sfRenderWindow_drawText(scene->window, invent->pot, NULL);
    disp_invent_button(scene, invent);
    while (invent->equipement[j] != NULL) {
        sfRenderWindow_drawRectangleShape(scene->window,
                                        invent->equipement[j]->but, NULL);
        sfRenderWindow_drawText(scene->window, invent->equipement[j]->txt,
                                NULL);
        j ++;
    }
}
