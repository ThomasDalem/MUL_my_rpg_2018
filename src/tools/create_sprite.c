/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_sprite
*/

#include "prototype.h"

sfSprite *create_sprite(char *str)
{
    sfTexture *texture = sfTexture_createFromFile(str, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}
