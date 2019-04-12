/*
** EPITECH PROJECT, 2019
** Tower Defense
** File description:
** Menu file
*/

#include "prototype.h"

void disp_menu(scene_t *scene)
{
    int i = 0;

    sfRenderWindow_clear(scene->window, sfBlack);
    while (scene->button[i] != NULL) {
        sfRenderWindow_drawRectangleShape(scene->window,
                                          scene->button[i]->but, NULL);
        i ++;
    }
    sfRenderWindow_display(scene->window);
}

void screenevent(sfEvent *event, scene_t *scene, int *gamemode)
{
    sfVector2i mouse;

    if (event->type == sfEvtMouseButtonPressed) {
        mouse = sfMouse_getPositionRenderWindow(scene->window);
        if (button_is_clicked(scene->button[0]->but, mouse) == 0) {
            sfRectangleShape_setOutlineColor(scene->button[0]->but, sfBlue);
            (*gamemode) = 1;
        }
        if (button_is_clicked(scene->button[1]->but, mouse) == 0)
            (*gamemode) = 3;
    }
    if (event->type == sfEvtClosed)
        *gamemode = 3;
}

int init_menu_scene(scene_t *scene)
{
    scene->button = malloc(sizeof(but_s) * 3);
    if (scene->button == NULL)
        return (84);
    scene->button[0] = malloc(sizeof(but_s));
    scene->button[1] = malloc(sizeof(but_s));
    scene->button[2] = NULL;
    if (scene->button[0] == NULL || scene->button[1] == NULL)
        return (84);
    init_start_button(scene->button[0]);
    init_end_button(scene->button[1]);
    return (0);
}

void destroy_menu(scene_t *scene, int *gamemode)
{
    int i = 0;

    while (scene->button[i] != NULL) {
        sfRectangleShape_destroy(scene->button[i]->but);
        free(scene->button[i]);
        i ++;
    }
    free(scene->button);
    if (*gamemode == 3)
        sfRenderWindow_close(scene->window);
}

int mainscreen(int *gamemode, scene_t *scene)
{
    sfEvent click;
    int a = 0;

    init_music(scene);
    sfMusic_play(scene->music->main);
    *gamemode = init_menu_scene(scene);
    if (*gamemode == 84)
        return (84);
    while (sfRenderWindow_isOpen(scene->window) && *gamemode == 0) {
        disp_menu(scene);
        sfMusic_setLoop(scene->music->main, sfTrue);
        cond_mouse(scene);
        while (sfRenderWindow_pollEvent(scene->window, &click))
            screenevent(&click, scene, gamemode);
    }
    destroy_menu(scene, gamemode);
    return (0);
}
