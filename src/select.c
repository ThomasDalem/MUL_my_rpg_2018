/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** select
*/

#include "prototype.h"

void create_button(but_s *but, int x, int pos_x)
{
    sfVector2f pos;
    sfVector2f size;
    sfTexture *texture = sfTexture_createFromFile("assets/textures/link.png", NULL);

    pos.x = pos_x;
    pos.y = 500;
    size.x = 200;
    size.y = 200;
    but->char_rect = create_char_perso(0, x, 16, 16);
    but->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(but->but, sfRed);
    sfRectangleShape_setOutlineThickness(but->but, 1);
    sfRectangleShape_setFillColor(but->but, sfWhite);
    sfRectangleShape_setSize(but->but, size);
    sfRectangleShape_setPosition(but->but, pos);
    sfRectangleShape_setTexture(but->but, texture, sfFalse);
    sfRectangleShape_setTextureRect(but->but, but->char_rect);
    but->is_clicked = 0;
}

void disp_select(scene_t *scene, but_s **button)
{
    sfRenderWindow_clear(scene->window, sfBlack);
    sfRenderWindow_drawRectangleShape(scene->window, button[0]->but, NULL);
    sfRenderWindow_drawRectangleShape(scene->window, button[1]->but, NULL);
    sfRenderWindow_drawRectangleShape(scene->window, button[2]->but, NULL);
    sfRenderWindow_display(scene->window);
}

int select_event(sfEvent *event, scene_t *scene, but_s **button)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);

    if (event->type == sfEvtMouseButtonPressed) {
        if (button_is_clicked(button[0]->but, mouse) == 0)
            return (0);
        if (button_is_clicked(button[1]->but, mouse) == 0)
            return (1);
        if (button_is_clicked(button[2]->but, mouse) == 0)
            return (2);
    }
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(scene->window);
        return (3);
    }
    return (-1);
}

void cond_select(scene_t *scene, but_s **button)
{
    int i = 0;

    while (button[i] != NULL) {
        if (button_is_clicked(button[i]->but,
                              sfMouse_getPositionRenderWindow
                              (scene->window)) == 0 
            && button[i]->is_clicked == 0)
            sfRectangleShape_setOutlineColor(button[i]->but, sfWhite);
        else if (button[i]->is_clicked == 0)
            sfRectangleShape_setOutlineColor(button[i]->but, sfRed);
        i ++;
    }
}
int select_perso(scene_t *scene, int *gamemode)
{
    sfEvent event;
    but_s **button = malloc(sizeof(but_s) * 4);
    int chose = -1;

    if (button == NULL) {
        *gamemode = 3;
        return (84);
    }
    button[0] = malloc(sizeof(but_s));
    button[1] = malloc(sizeof(but_s));
    button[2] = malloc(sizeof(but_s));
    button[3] = NULL;
    create_button(button[0], 0, 400);
    create_button(button[1], 120, 650);
    create_button(button[2], 240, 900);
    while (sfRenderWindow_isOpen(scene->window) && chose == -1) {
        disp_select(scene, button);
        cond_select(scene, button);
        while (sfRenderWindow_pollEvent(scene->window, &event))
            chose = select_event(&event, scene, button);
    }
    if (chose == 0 || chose == 1 || chose == 2)
        scene->perso.nb_perso = chose;
    return (chose);
}
