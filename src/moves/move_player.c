/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** move_player
*/

#include "prototype.h"
#include "structures.h"

static sfIntRect change_animation(obj_t *player, int direction)
{
    sfIntRect sprite_rect = sfSprite_getTextureRect(player->sprite);

    sprite_rect.top = (direction == UP) ? 214: sprite_rect.top;
    sprite_rect.top = (direction == DOWN) ? 24: sprite_rect.top;
    sprite_rect.top = (direction == LEFT) ? 88: sprite_rect.top;
    sprite_rect.top = (direction == RIGHT) ? 152: sprite_rect.top;
    return (sprite_rect);
}

void move_player(obj_t *player, int direction)
{
    sfVector2f offset = {0, 0};
    sfIntRect sprite_rect;

    offset.y += (direction == UP) ? -10 : 0;
    offset.y += (direction == DOWN) ? 10 : 0;
    offset.x += (direction == LEFT) ? -10 : 0;
    offset.x += (direction == RIGHT) ? 10 : 0;
    sprite_rect = change_animation(player, direction);
    sfSprite_setTextureRect(player->sprite, sprite_rect);
    anim(player);
    sfSprite_move(player->sprite, offset);
}
