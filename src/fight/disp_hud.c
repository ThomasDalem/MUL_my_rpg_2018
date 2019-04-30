/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** disp_hud
*/

#include "prototype.h"

void set_text(sfText *text, char *str, sfFont *font, sfVector2f pos)
{
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, 35);
    sfText_setPosition(text, pos);
}

void disp_hud(scene_t *scene, obj_t *perso, int x, int y)
{
    sfFont *font = sfFont_createFromFile("assets/texts/pause.ttf");
    sfText *life = sfText_create();
    sfText *attack = sfText_create();
    sfText *defense = sfText_create();
    sfText *speed = sfText_create();
    sfVector2f pos = {x, y};

    pos = (sfVector2f){x, y + 40};
    set_text(life, set_life_str(perso), font, pos);
    sfRenderWindow_drawText(scene->window, life, NULL);
    pos = (sfVector2f){x, y + 80};
    set_text(attack, set_attack_str(perso), font, pos);
    sfRenderWindow_drawText(scene->window, attack, NULL);
    pos = (sfVector2f){x, y + 120};
    set_text(defense, set_defense_str(perso), font, pos);
    sfRenderWindow_drawText(scene->window, defense, NULL);
    pos = (sfVector2f){x, y + 160};
    set_text(speed, set_magic_str(perso), font, pos);
    sfRenderWindow_drawText(scene->window, speed, NULL);
    sfFont_destroy(font);
}