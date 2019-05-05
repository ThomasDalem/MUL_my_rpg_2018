/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_sell_equipement
*/

#include "prototype.h"

void init_sell_str(but_s *thing, char *str, int r)
{
    sfVector2f pos = sfRectangleShape_getPosition(thing->but);
    char **arr = my_str_to_word_array(str, ',');
    int attack = my_getnbr(arr[0]);
    int defense = my_getnbr(arr[1]);
    int speed = my_getnbr(arr[2]);
    struct stats equip = create_stat_perso(0, attack, defense, speed);

    thing->object.damage = attack;
    thing->object.defense = defense;
    thing->object.magic = speed;
    thing->object.cost = my_getnbr(arr[3]);
    thing->font = sfFont_createFromFile("assets/texts/info.ttf");
    thing->txt = sfText_create();
    equip.life = my_getnbr(arr[3]);
    create_string_equip(thing, equip);
    pos.x = pos.x + 120;
    pos.y = pos.y + 40;
    sfText_setPosition(thing->txt, pos);
}

void init_disp_equip(but_s *things)
{
    sfTexture *texture = sfTexture_createFromFile(
        "assets/textures/equip.jpg", NULL);
    sfTexture *texture_sword = sfTexture_createFromFile(
        "assets/textures/sword_icon.png", NULL);
    sfIntRect rect = {0, 0, 0, 0};

    sfRectangleShape_setTexture(things->but, texture, sfTrue);
    if (things->object.effect == 1)
        rect = create_char_perso(37, 52, 200, 178);
    if (things->object.effect == 2)
        rect = create_char_perso(235, 13, 279, 258);
    if (things->object.effect == 3)
        rect = create_char_perso(513, 52, 200, 277);
    if (things->object.effect == 4)
        rect = create_char_perso(810, 13, 277, 188);
    if (rect.top != 0)
        sfRectangleShape_setTextureRect(things->but, rect);
    if (things->object.effect == 5)
        sfRectangleShape_setTexture(things->but, texture_sword, sfTrue);
}

void add_equipement(but_s *things, char *str, int r)
{
    char **arr = my_str_to_word_array(str, ':');

    things->object.type = my_getnbr(arr[0]);
    things->object.effect = my_getnbr(arr[1]);
    if (things->object.type == 1) {
        init_sell_str(things, arr[2], r);
        init_disp_equip(things);
    }
    if (things->object.type == 2) {
        init_potion_str(things, arr[2], r);
        init_disp_potion(things);
    }
}

int fill_sell_str(scene_t *scene)
{
    FILE *fd = fopen("source/equipement", "r");
    int t = 1;
    int i = 0;
    size_t n = 0;

    scene->sell->str = malloc(sizeof(char *) * 2);
    if (fd == NULL || scene->sell->str == NULL)
        return (84);
    scene->sell->str[i] = malloc(sizeof(char) * 4096);
    while (getline(&scene->sell->str[i], &n , fd) != -1) {
        scene->sell->str = reallocation(scene->sell->str, t);
        if (scene->sell->str == NULL)
            return (84);
        t++;
        i++;
        scene->sell->str[i] = malloc(sizeof(char) * 4096);
    }
    scene->sell->str[i] == NULL;
    return (0);
}