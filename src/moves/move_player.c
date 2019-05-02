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

    sprite_rect.top = (direction == UP) ? 214 : sprite_rect.top;
    sprite_rect.top = (direction == DOWN) ? 24 : sprite_rect.top;
    sprite_rect.top = (direction == LEFT) ? 88 : sprite_rect.top;
    sprite_rect.top = (direction == RIGHT) ? 152 : sprite_rect.top;
    return (sprite_rect);
}

void move_player(scene_t *scene, obj_t *player, int direction)
{
    sfVector2f offset = {0, 0};
    sfIntRect sprite_rect;
    sfTime time = sfClock_getElapsedTime(player->move_clock);
    float seconds = sfTime_asSeconds(time);

    sfClock_restart(scene->perso->move_clock);
    if (direction == 0)
        return;
    offset.y += (direction == UP) ? -5.0f * seconds * 60.0f : 0;
    offset.y += (direction == DOWN) ? 5.0f * seconds * 60.0f : 0;
    offset.x += (direction == LEFT) ? -5.0f * seconds * 60.0f : 0;
    offset.x += (direction == RIGHT) ? 5.0f * seconds * 60.0f : 0;
    sprite_rect = change_animation(player, direction);
    sfSprite_setTextureRect(player->sprite, sprite_rect);
    anim(player);
    if (!check_collision(scene, offset))
        sfSprite_move(player->sprite, offset);
}
