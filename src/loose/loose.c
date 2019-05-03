/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** loose
*/

#include "prototype.h"

int init_button_loose(but_s *button, char *str, int x, int y)
{
    sfVector2f pos = {x, y};
    sfVector2f size = {300, 100};
    sfTexture *start = sfTexture_createFromFile
        ("assets/textures/button.jpg", NULL);

    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfTransparent);
    sfRectangleShape_setOutlineThickness(button->but, 2);
    sfRectangleShape_setFillColor(button->but, sfWhite);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    sfRectangleShape_setTexture(button->but, start, sfFalse);
    button->txt = sfText_create();
    button->font = sfFont_createFromFile("assets/texts/menu.otf");
    set_text(button->txt, str, button->font, (sfVector2f){853, y + 20});
    return (1);
}

int init_loose_scene(scene_t *scene)
{
    char *path_back = "assets/textures/menu.jpg";
    int i = 0;

    scene->button = malloc(sizeof(but_s) * 4);
    if (scene->button == NULL)
        return (84);
    for (i = 0; i != 3; i++)
        scene->button[i] = malloc(sizeof(but_s));
    scene->button[i] = NULL;
    if (scene->button[0] == NULL || scene->button[1] == NULL ||
        scene->button[2] == NULL)
        return (84);
    scene->text_back = sfTexture_createFromFile(path_back, NULL);
    scene->spr_back = sfSprite_create();
    sfSprite_setTexture(scene->spr_back, scene->text_back, sfFalse);
    init_button_loose(scene->button[0], "restart", 773, 300 + 0 * 200);
    init_button_loose(scene->button[1], "menu", 773, 300 + 1 * 200);
    init_button_loose(scene->button[2], "quit", 773, 300 + 2 * 200);
    return (0);
}
