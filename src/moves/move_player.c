/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** move_player
*/

#include <stdio.h>
#include "prototype.h"
#include "structures.h"
#include "collisions.h"

static sfIntRect change_animation(obj_t *player, int direction)
{
    sfIntRect sprite_rect = sfSprite_getTextureRect(player->sprite);
    int up = 61 + player->nb_perso * 120;
    int down = 0 + player->nb_perso * 120;
    int left = 30 + player->nb_perso * 120;
    int right = 90 + player->nb_perso * 120;

    sprite_rect.left = (direction == UP) ? up : sprite_rect.left;
    sprite_rect.left = (direction == DOWN) ? down : sprite_rect.left;
    sprite_rect.left = (direction == LEFT) ? left : sprite_rect.left;
    sprite_rect.left = (direction == RIGHT) ? right : sprite_rect.left;
    return (sprite_rect);
}

void move_player(scene_t *scene, obj_t *player, int direction)
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
    if (!check_collision(scene, offset))
        sfSprite_move(player->sprite, offset);
}
