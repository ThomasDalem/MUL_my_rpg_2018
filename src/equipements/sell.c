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
        sfRenderWindow_drawRectangleShape(
            scene->window, scene->sell->things[i]->but, NULL);
        sfRenderWindow_drawText(
            scene->window, scene->sell->things[i]->txt, NULL);
        i++;
    }
    sfText_setColor(scene->sell->no_place, scene->sell->color_place);
    sfText_setColor(scene->sell->not_money, scene->sell->color_money);
    sfRenderWindow_drawText(scene->window, scene->sell->no_place, NULL);
    sfRenderWindow_drawText(scene->window, scene->sell->not_money, NULL);
    sfRenderWindow_drawText(scene->window, scene->sell->money, NULL);
}

void check_pay(scene_t *scene, inv_t *invent, sfVector2i mouse)
{
    int i = 0;

    while (scene->sell->things[i] != NULL) {
        if (button_is_clicked(scene->sell->things[i]->but, mouse) == 0)
            set_new_equipement(scene, invent, i);
        i++;
    }
}

void sell_key_event(sfEvent *event, scene_t *scene, inv_t *invent)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);

    if (event->type == sfEvtMouseButtonPressed) {
        check_all_button(scene->sell->things, scene);
    }
    if (event->type == sfEvtMouseButtonReleased) {
        check_pay(scene, invent, mouse);
        reboot(scene->sell->things);
    }
}

static int sell_event(sfEvent *event, scene_t *scene, inv_t *invent)
{
    if (event->key.code == sfKeyO)
        return (2);
    if (event->type == sfEvtClosed)
        return (3);
    sell_key_event(event, scene, invent);
    return (1);
}

int check_if_sell(scene_t *scene, inv_t *invent, int *gamemode)
{
    int p = 1;
    sfEvent event;

    if (!scene->map->pnj || scene->map->pnj->text.nb_dialog != 2)
        return (1);
    fill_equipement(scene);
    while (p == 1) {
        sfRenderWindow_clear(scene->window, sfBlack);
        disp_sell(scene);
        button_disp(scene->sell->things, scene);
        sfRenderWindow_display(scene->window);
        check_text(scene);
        while (sfRenderWindow_pollEvent(scene->window, &event))
            p = sell_event(&event, scene, invent);
    }
    scene->map->pnj->text.nb_dialog++;
    if (p == 2)
        return (1);
    return (p);
}
