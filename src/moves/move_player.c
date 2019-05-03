/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** move_player
*/

#include "prototype.h"
#include "structures.h"
#include "collisions.h"

void move_player(scene_t *scene, obj_t *player, int direction)
{
    sfVector2f offset = {0, 0};
    sfIntRect sprite_rect;
    sfTime time = sfClock_getElapsedTime(player->move_clock);
    float seconds = sfTime_asSeconds(time);

    sfClock_restart(player->move_clock);
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
