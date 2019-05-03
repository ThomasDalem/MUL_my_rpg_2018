/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** pause
*/

#include "prototype.h"

static int check_click(scene_t *scene, pause_s *pause)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);
    int i = 0;

    while (pause->button[i] != NULL) {
        if (button_is_clicked(pause->button[i]->but, mouse) == 0)
            return (i + 1);
        i++;
    }
    return (0);
}


static int pause_event(sfEvent *event, scene_t *scene, pause_s *pause)
{

    if (event->type == sfEvtMouseButtonPressed)
        check_all_button(pause->button, scene);
    if (event->type == sfEvtMouseButtonReleased)
        return (check_click(scene, pause));
    if (event->type == sfEvtClosed)
        return (3);
    return (0);
}

static void disp_pause(scene_t *scene, pause_s *pause)
{
    int i = 0;

    sfRenderWindow_drawSprite(scene->window, pause->spr_back, NULL);
    sfRenderWindow_drawRectangleShape(scene->window, pause->filter, NULL);
    while (pause->button[i] != NULL) {
        sfRenderWindow_drawRectangleShape(scene->window, pause->button[i]->but,
                                            NULL);
        sfRenderWindow_drawText(scene->window, pause->button[i]->txt, NULL);
        i++;
    }
}

int pause_function(scene_t *scene, pause_s *pause)
{
    int p = 0;
    sfEvent event;

    while (p == 0) {
        sfRenderWindow_clear(scene->window, sfBlack);
        disp_pause(scene, pause);
        sfRenderWindow_display(scene->window);
        button_disp(pause->button, scene);
        while (sfRenderWindow_pollEvent(scene->window, &event))
            p = pause_event(&event, scene, pause);
    }
    return (p);
}
