/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** change_animation
*/

#include "prototype.h"
#include "structures.h"

sfIntRect change_enemy_animation(obj_t *player, int direction)
{
    sfIntRect sprite_rect = sfSprite_getTextureRect(player->sprite);

    sprite_rect.top = (direction == UP) ? 202 : sprite_rect.top;
    sprite_rect.top = (direction == DOWN) ? 8 : sprite_rect.top;
    sprite_rect.top = (direction == LEFT) ? 72 : sprite_rect.top;
    sprite_rect.top = (direction == RIGHT) ? 138 : sprite_rect.top;
    return (sprite_rect);
}

sfIntRect change_animation(obj_t *player, int direction)
{
    sfIntRect sprite_rect = sfSprite_getTextureRect(player->sprite);

    sprite_rect.top = (direction == UP) ? 214 : sprite_rect.top;
    sprite_rect.top = (direction == DOWN) ? 24 : sprite_rect.top;
    sprite_rect.top = (direction == LEFT) ? 88 : sprite_rect.top;
    sprite_rect.top = (direction == RIGHT) ? 152 : sprite_rect.top;
    return (sprite_rect);
}