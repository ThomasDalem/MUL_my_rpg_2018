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
    sfFloatRect text;
    int i = 0;

    while (pause->txt[i] != NULL) {
        text = sfText_getGlobalBounds(pause->txt[i]);
        if (mouse.x > text.left && mouse.x < text.left + text.width &&
            mouse.y > text.top && mouse.y < text.top + text.height) {
            sfText_setFillColor(pause->txt[i], sfRed);
            return (i + 1);
        }
        i++;
    }
    return (0);
}

static int pause_event(sfEvent *event, scene_t *scene, pause_s *pause)
{
    if (event->type == sfEvtMouseButtonPressed) {
        return (check_click(scene, pause));
    }
    if (event->type == sfEvtClosed) {
        return (3);
    }
    return (0);
}

static void disp_pause(scene_t *scene, pause_s *pause)
{
    int i = 0;
    sfRenderWindow_drawSprite(scene->window, pause->spr_back, NULL);
    sfRenderWindow_drawRectangleShape(scene->window, pause->filter, NULL);
    while (pause->txt[i] != NULL) {
        sfRenderWindow_drawText(scene->window, pause->txt[i], NULL);
        i++;
    }
}

static void check_pos(scene_t *scene, pause_s *pause)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);
    sfFloatRect text;
    int i = 0;

    while (pause->txt[i] != NULL) {
        text = sfText_getGlobalBounds(pause->txt[i]);
        if (mouse.x > text.left && mouse.x < text.left + text.width &&
            mouse.y > text.top && mouse.y < text.top + text.height) {
            sfText_setFillColor(pause->txt[i], sfBlue);
            return;
        }
        sfText_setFillColor(pause->txt[i], sfWhite);
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
        check_pos(scene, pause);
        while (sfRenderWindow_pollEvent(scene->window, &event))
            p = pause_event(&event, scene, pause);
    }
    return (p);
}