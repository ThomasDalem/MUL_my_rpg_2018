/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** init_pause
*/

#include "prototype.h"

static void init_filter(pause_s *pause)
{
    sfVector2f size;
    sfVector2f pos;
    sfColor color;

    color.a = 100;
    color.b = 0;
    color.r = 0;
    color.g = 0;
    size.x = 1920;
    size.y = 1080;
    pos.x = 0;
    pos.y = 0;
    pause->filter = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(pause->filter, 0);
    sfRectangleShape_setFillColor(pause->filter, color);
    sfRectangleShape_setSize(pause->filter, size);
    sfRectangleShape_setPosition(pause->filter, pos);
}

static int init_resume(pause_s *pause)
{
    char *str = malloc(sizeof(char) * 7);
    sfVector2f pos;

    if (str == NULL)
        return (84);
    pos.x = 850;
    pos.y = 300;
    my_strcpy(str, "RESUME");
    sfText_setString(pause->txt[0], str);
    sfText_setFont(pause->txt[0], pause->font);
    sfText_setColor(pause->txt[0], sfWhite);
    sfText_setPosition(pause->txt[0], pos);
    sfText_setCharacterSize(pause->txt[0], 30);
    free(str);
}

static int init_quit(pause_s *pause)
{
    char *str = malloc(sizeof(char) * 5);
    sfVector2f pos;

    if (str == NULL)
        return (84);
    pos.x = 850;
    pos.y = 400;
    my_strcpy(str, "QUIT");
    sfText_setString(pause->txt[1], str);
    sfText_setFont(pause->txt[1], pause->font);
    sfText_setColor(pause->txt[1], sfWhite);
    sfText_setPosition(pause->txt[1], pos);
    sfText_setCharacterSize(pause->txt[1], 30);
    free(str);
}

static int init_quitgame(pause_s *pause)
{
    char *str = malloc(sizeof(char) * 10);
    sfVector2f pos;

    if (str == NULL)
        return (84);
    pos.x = 850;
    pos.y = 500;
    my_strcpy(str, "QUIT GAME");
    sfText_setString(pause->txt[2], str);
    sfText_setFont(pause->txt[2], pause->font);
    sfText_setColor(pause->txt[2], sfWhite);
    sfText_setPosition(pause->txt[2], pos);
    sfText_setCharacterSize(pause->txt[2], 30);
    free(str);
}

int init_pause(pause_s *pause)
{
    init_filter(pause);
    pause->font = sfFont_createFromFile("./assets/pause.ttf");
    pause->txt = malloc(sizeof(sfText *) * 4);
    if (pause->txt == NULL)
        return (84);
    pause->txt[0] = sfText_create();
    pause->txt[1]= sfText_create();
    pause->txt[2] = sfText_create();
    pause->txt[3] = NULL;
    if (init_resume(pause) == 84 || init_quit(pause) == 84 ||
        init_quitgame(pause) == 84)
        return (84);
    return (0);
}
