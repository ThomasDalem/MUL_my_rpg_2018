/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** option
*/

#include "prototype.h"
#include "structures.h"

static int option_click(scene_t *scene, option_t *option)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);


    if (button_is_clicked(option->button[1]->but, mouse) == 0)
        restart_screen(scene);
    if (button_is_clicked(option->button[0]->but, mouse) == 0)
        return (1);
    if (button_is_clicked(option->button[2]->but, mouse) == 0) {
        if (scene->if_sound == 0)
            scene->if_sound = 1;
        if (scene->if_sound == 1)
            scene->if_sound = 0;
    }
    return (0);
}

static int option_event(sfEvent *event, scene_t *scene, option_t *option)
{
    if (event->type == sfEvtMouseButtonPressed)
        check_all_button(option->button, scene);
    if (event->type == sfEvtMouseButtonReleased) {
        return (option_click(scene, option));
    }
    if (event->type == sfEvtClosed) {
        return (3);
    }
    return (0);
}

void disp_option(scene_t *scene, option_t *option)
{
    int i = 0;

    sfRenderWindow_drawSprite(scene->window, option->spr_back, NULL);
    while (option->button[i] != NULL) {
        sfRenderWindow_drawRectangleShape(scene->window,
                            option->button[i]->but, NULL);
        sfRenderWindow_drawText(scene->window, option->button[i]->txt, NULL);
        i++;
    }
}

int option_function(scene_t *scene, option_t *option)
{
    int p = 0;
    sfEvent event;

    while (p == 0) {
        sfRenderWindow_clear(scene->window, sfBlack);
        disp_option(scene, option);
        button_disp(option->button, scene);
        sfRenderWindow_display(scene->window);
        while (sfRenderWindow_pollEvent(scene->window, &event))
            p = option_event(&event, scene, option);
    }
    return (0);
}