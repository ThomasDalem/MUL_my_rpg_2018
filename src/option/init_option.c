/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_option
*/

#include "prototype.h"
#include "structures.h"

int init_option(option_t *option)
{
    char *path_back = "assets/textures/menu.jpg";

    option->button = malloc(sizeof(but_s) * 4);
    if (option->button == NULL)
        return (84);
    for (int i = 0; i != 4; i++)
        option->button[i] = malloc(sizeof(struct button_s));
    if (option->button[0] == NULL || option->button[1] == NULL
                                    || option->button[2] == NULL)
        return (84);
    init_exit(option->button[0]);
    init_fs(option->button[1]);
    init_mute(option->button[2]);
    option->button[3] = NULL;
    option->text_back = sfTexture_createFromFile(path_back, NULL);
    option->spr_back = sfSprite_create();
    sfSprite_setTexture(option->spr_back, option->text_back, sfFalse);
    return (0);
}

void init_mute(but_s *button)
{
    char *path_button = "assets/textures/button.jpg";
    sfVector2f pos = {773, 600};
    sfVector2f size = {300, 100};
    sfTexture *text = sfTexture_createFromFile(path_button, NULL);

    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfTransparent);
    sfRectangleShape_setOutlineThickness(button->but, 2);
    sfRectangleShape_setFillColor(button->but, sfWhite);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    sfRectangleShape_setTexture(button->but, text, sfFalse);
    button->txt = sfText_create();
    button->font = sfFont_createFromFile("assets/texts/menu.otf");
    set_text(button->txt, "mute", button->font, (sfVector2f){880, 630});
}

void init_exit(but_s *button)
{
    char *path_button = "assets/textures/button.jpg";
    sfVector2f pos = {773, 800};
    sfVector2f size = {300, 100};
    sfTexture *text = sfTexture_createFromFile(path_button, NULL);

    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfTransparent);
    sfRectangleShape_setOutlineThickness(button->but, 2);
    sfRectangleShape_setFillColor(button->but, sfWhite);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    sfRectangleShape_setTexture(button->but, text, sfFalse);
    button->txt = sfText_create();
    button->font = sfFont_createFromFile("assets/texts/menu.otf");
    set_text(button->txt, "EXIT", button->font, (sfVector2f){880, 830});
}

void init_fs(but_s *button)
{
    char *path_button = "assets/textures/button.jpg";
    sfVector2f pos = {773, 400};
    sfVector2f size = {300, 100};
    sfTexture *text = sfTexture_createFromFile(path_button, NULL);

    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfTransparent);
    sfRectangleShape_setOutlineThickness(button->but, 2);
    sfRectangleShape_setFillColor(button->but, sfWhite);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    sfRectangleShape_setTexture(button->but, text, sfFalse);
    button->txt = sfText_create();
    button->font = sfFont_createFromFile("assets/texts/menu.otf");
    set_text(button->txt, "Fullscreen", button->font, (sfVector2f){830, 425});
}

void restart_screen(scene_t *scene)
{
    static int p = 1;
    int gamemode = 1;

    sfRenderWindow_destroy(scene->window);
    if (p == 0) {
        scene->window = createmywindow(0, 1920, 1080);
        p++;
    }
    else {
        scene->window = createmywindow(1, 1920, 1080);
        p = 0;
    }
}