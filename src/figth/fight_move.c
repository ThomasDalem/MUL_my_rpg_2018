/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** fight_move
*/

#include "prototype.h"

void anim_left_fight(obj_t *player)
{
    sfIntRect rect_perso = sfSprite_getTextureRect(player->sprite);
    sfTime elapsed_time = sfClock_getElapsedTime(player->anim_clock);
    float time = sfTime_asSeconds(elapsed_time);

    if (time > 0.1) {
        if (rect_perso.left < 287)
            rect_perso.left = rect_perso.left + 27;
        else
            rect_perso.left = player->fight->char_left.left;
        sfSprite_setTextureRect(player->sprite, rect_perso);
        sfClock_restart(player->anim_clock);
    }
}

void anim_right_fight(obj_t *player)
{
    sfIntRect rect_perso = sfSprite_getTextureRect(player->sprite);
    sfTime elapsed_time = sfClock_getElapsedTime(player->anim_clock);
    float time = sfTime_asSeconds(elapsed_time);

    if (time > 0.1) {
        if (rect_perso.left < 127)
            rect_perso.left = rect_perso.left + 27;
        else
            rect_perso.left = player->fight->char_left.left;
        sfSprite_setTextureRect(player->sprite, rect_perso);
        sfClock_restart(player->anim_clock);
    }
}

static sfIntRect animation_fight(obj_t *player, int direction)
{
    sfIntRect sprite_rect = sfSprite_getTextureRect(player->sprite);

    sprite_rect.top = (direction == LEFT) ? 88: sprite_rect.top;
    sprite_rect.top = (direction == RIGHT) ? 152: sprite_rect.top;
    return (sprite_rect);
}

void move_player(obj_t *player, int direction)
{
    sfVector2f offset = {0, 0};
    sfIntRect sprite_rect;

    offset.x += (direction == LEFT) ? -20 : 0;
    offset.x += (direction == RIGHT) ? 20 : 0;
    sprite_rect = animation_fight(player, direction);
    sfSprite_setTextureRect(player->sprite, sprite_rect);
    if (direction == LEFT)
        anim_left_fight(player);
    if (direction == RIGHT)
        anim_left_fight(player);
    sfSprite_move(player->sprite, offset);
}
