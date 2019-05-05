/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** loose_button
*/

#include "prototype.h"

void disp_loose(scene_t *scene)
{
    int i = 0;

    sfRenderWindow_clear(scene->window, sfBlack);
    while (scene->button[i] != NULL) {
        sfRenderWindow_drawRectangleShape(scene->window,
                                        scene->button[i]->but, NULL);
        sfRenderWindow_drawText(scene->window, scene->button[i]->txt, NULL);
        i ++;
    }
    sfRenderWindow_display(scene->window);
}

void looseevent(sfEvent *event, scene_t *scene, int *gamemode)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);

    if (event->type == sfEvtMouseButtonPressed)
        check_all_button(scene->button, scene);
    if (event->type == sfEvtMouseButtonReleased) {
        if (button_is_clicked(scene->button[0]->but, mouse) == 0)
            (*gamemode) = 1;
        if (button_is_clicked(scene->button[1]->but, mouse) == 0)
            (*gamemode) = 2;
        if (button_is_clicked(scene->button[2]->but, mouse) == 0)
            (*gamemode) = 3;
        reboot(scene->button);
    }
    if (event->type == sfEvtClosed) {
        *gamemode = 3;
    }
}

void destroy_loose(scene_t *scene, int *gamemode)
{
    int i = 0;

    while (scene->button[i] != NULL) {
        sfRectangleShape_destroy(scene->button[i]->but);
        free(scene->button[i]);
        i ++;
    }
    free(scene->button);
}

int loosescreen(int *gamemode, scene_t *scene)
{
    sfEvent click;
    int a = 0;
    musics *dead_scream = malloc(sizeof(musics));

    if (dead_scream == NULL)
        return (84);
    dead_scream->sound = sfMusic_createFromFile("assets/sound/dead_scream.ogg");
    *gamemode = init_loose_scene(scene);
    if (*gamemode == 84)
        return (84);
    *gamemode = 0;
    sfMusic_play(dead_scream->sound);
    while (sfRenderWindow_isOpen(scene->window) && *gamemode == 0) {
        disp_loose(scene);
        button_disp(scene->button, scene);
        while (sfRenderWindow_pollEvent(scene->window, &click))
            looseevent(&click, scene, gamemode);
    }
    destroy_loose(scene, gamemode);
    sfMusic_destroy(dead_scream->sound);
    return (0);
}
