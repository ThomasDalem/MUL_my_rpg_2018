/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** after_fight
*/

#include "prototype.h"

void after_fight_function(scene_t *scene, sfVector2f pos)
{
    sfVector2f scale = {1.5, 1.5};

    sfSprite_setTexture(scene->perso->sprite, scene->perso->texture, sfTrue);
    sfSprite_setTextureRect(scene->perso->sprite, scene->perso->char_left);
    sfSprite_setScale(scene->perso->sprite, scale);
    sfSprite_setPosition(scene->perso->sprite, pos);
    scene->perso->money+= 20;
    scene->perso->is_fighting = 0;
    scene->perso->move_dir = 0;
}