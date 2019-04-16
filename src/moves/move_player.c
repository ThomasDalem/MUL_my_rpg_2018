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

    sprite_rect.left = (direction == UP) ? 61 + player->nb_perso * 120: sprite_rect.left;
    sprite_rect.left = (direction == DOWN) ? 0 + player->nb_perso * 120: sprite_rect.left;
    sprite_rect.left = (direction == LEFT) ? 30 + player->nb_perso * 120: sprite_rect.left;
    sprite_rect.left = (direction == RIGHT) ? 90 + player->nb_perso * 120: sprite_rect.left;
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
