/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sell
*/

#include "prototype.h"

void disp_sell(scene_t *scene)
{
    int i = 0;

    sfRenderWindow_drawRectangleShape(scene->window, scene->sell->back, NULL);
    while (scene->sell->things[i] != NULL) {
        sfRenderWindow_drawRectangleShape(scene->window, scene->sell->things[i]->but, NULL);
        i++;
    }
    sfRenderWindow_drawText(scene->window, scene->sell->money, NULL);
}

void sell_key_event(sfEvent *event, scene_t *scene)
{
    sfVector2i mouse;

    if (event->type == sfEvtMouseButtonPressed) {
        mouse = sfMouse_getPositionRenderWindow(scene->window);
        check_all_button(scene->sell->things, scene);
    }
    if (event->type == sfEvtMouseButtonReleased)
        reboot(scene->sell->things);
}

static int sell_event(sfEvent *event, scene_t *scene)
{
    if (event->key.code == sfKeyO)
        return (2);
    if (event->type == sfEvtClosed)
        return (3);
    sell_key_event(event, scene);
    return (1);
}

int check_if_sell(scene_t *scene, int *gamemode)
{
    int p = 1;
    sfEvent event;

    if (scene->pnj->text.nb_dialog != 2)
        return (1);
    while (p == 1) {
        sfRenderWindow_clear(scene->window, sfBlack);
        disp_sell(scene);
        sfRenderWindow_display(scene->window);
        while (sfRenderWindow_pollEvent(scene->window, &event))
            p = sell_event(&event, scene);
    }
    scene->pnj->text.nb_dialog++;
    if (p == 2)
        return (1);
    return (p);
}