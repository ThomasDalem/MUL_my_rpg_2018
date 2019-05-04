/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_sell
*/

#include "prototype.h"

int set_money_text(scene_t *scene)
{
    char *str = malloc(sizeof(char) * 4096);
    sfVector2f pos = {10, 10};

    if (str == NULL)
        return (84);
    my_strcpy(str, "money = ");
    my_strcat(str, int_to_char(scene->perso->money));
    set_text(scene->sell->money, str, scene->sell->font, pos);
    return (0);
}

int init_sell_button(scene_t *scene)
{
    int i = 0;
    sfVector2f pos = {100, 100};
    sfVector2f size = {100, 100};

    while (i != 5) {
        scene->sell->things[i] = malloc(sizeof(struct button_s));
        if (scene->sell->things[i] == NULL)
            return (84);
        scene->sell->things[i]->but = sfRectangleShape_create();
        sfRectangleShape_setSize(scene->sell->things[i]->but, size);
        sfRectangleShape_setFillColor(scene->sell->things[i]->but, sfWhite);
        sfRectangleShape_setOutlineThickness(scene->sell->things[i]->but, 3);
        sfRectangleShape_setOutlineColor(scene->sell->things[i]->but, sfRed);
        sfRectangleShape_setPosition(scene->sell->things[i]->but, pos);
        pos.y = pos.y + 110;
        i++;
    }
    scene->sell->things[i] = NULL;
    return (0);
}

void fill_equipement(scene_t *scene)
{
    int i = 0;
    int r = rand() % 20;

    while (scene->sell->things[i] != NULL) {
        if (scene->sell->str[r][0] == '1') {
            scene->sell->things[i]->object.number = r;
            add_equipement(scene->sell->things[i], scene->sell->str[r], r);
            i++;
        }
        if (scene->sell->str[r][0] == '2') {
            scene->sell->things[i]->object.number = r;
            add_equipement(scene->sell->things[i], scene->sell->str[r], r);
            i++;
        }
        r = rand() % 20;
    }
    set_money_text(scene);
}

int set_error_text(scene_t *scene)
{
    sfVector2f pos_money = {1200, 200};
    sfVector2f pos_place = {1200, 400};
    scene->sell->no_place =  sfText_create();
    scene->sell->not_money = sfText_create();
    scene->sell->color_money = (sfColor){255, 255, 255, 0};
    scene->sell->color_place = (sfColor){255, 255, 255, 0};
    set_text(scene->sell->no_place, 
                "no more place", scene->sell->font, pos_place);
    set_text(scene->sell->not_money,
                "no more money", scene->sell->font, pos_money);
    sfText_setColor(scene->sell->no_place, scene->sell->color_place);
    sfText_setColor(scene->sell->not_money, scene->sell->color_money);
    scene->sell->clock_money = sfClock_create();
    scene->sell->clock_place = sfClock_create();
    return (0);
}

int init_sell(scene_t *scene)
{
    scene->sell = malloc(sizeof(struct sell));
    scene->sell->things = malloc(sizeof(struct button_s) * 6);
    int i = 0;
    sfVector2f pos_things;

    if (scene->sell == NULL || scene->sell->things == NULL)
        return (84);
    scene->sell->back = sfRectangleShape_create();
    sfRectangleShape_setSize(scene->sell->back, (sfVector2f){1920, 1080});
    sfRectangleShape_setPosition(scene->sell->back, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(scene->sell->back, sfBlack);
    scene->sell->font = sfFont_createFromFile("assets/texts/menu.otf");
    scene->sell->money = sfText_create();
    if (set_money_text(scene) == 84 || init_sell_button(scene) == 84)
        return (84);
    if (set_error_text(scene) == 84)
        return (84);
    if (fill_sell_str(scene) == 84)
        return (84);
    fill_equipement(scene);
    return (0);
}