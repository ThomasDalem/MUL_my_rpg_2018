/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** move
*/

#include "prototype.h"

void move_up(scene_t *scene)
{
    sfVector2f move;
    sfIntRect rect = sfSprite_getTextureRect(scene->perso->sprite);

    if (rect.left != 61)
        sfSprite_setTextureRect(scene->perso->sprite, scene->perso->char_up);
}

void move_down(scene_t *scene)
{
    sfVector2f move;
    sfFloatRect rect = sfSprite_getGlobalBounds(scene->perso->sprite);

    if (rect.left != 0)
        sfSprite_setTextureRect(scene->perso->sprite, scene->perso->char_down);
}

void move_left(scene_t *scene)
{
    sfVector2f move;
    sfFloatRect rect = sfSprite_getGlobalBounds(scene->perso->sprite);

    move.x = -10;
    move.y = 0;
    if (rect.left != 30)
        sfSprite_setTextureRect(scene->perso->sprite, scene->perso->char_left);
}

void move_right(scene_t *scene)
{
    sfVector2f move;
    sfFloatRect rect = sfSprite_getGlobalBounds(scene->perso->sprite);

    move.x = 10;
    move.y = 0;
    if (rect.left != 90)
        sfSprite_setTextureRect(scene->perso->sprite, scene->perso->char_right);
}