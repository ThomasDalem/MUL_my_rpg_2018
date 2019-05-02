/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** enemy_movement
*/

#include <stdio.h>
#include "prototype.h"
#include "structures.h"
#include "collisions.h"

void move_enemy(scene_t *scene, obj_t *enemy, int direction)
{
    sfVector2f offset = {0, 0};
    sfIntRect sprite_rect;
    sfTime time = sfClock_getElapsedTime(enemy->move_clock);
    float seconds = sfTime_asSeconds(time);

    sfClock_restart(enemy->move_clock);
    if (direction == 0)
        return;
    offset.y += (direction == UP) ? -1.0f * seconds * 60.0f : 0;
    offset.y += (direction == DOWN) ? 1.0f * seconds * 60.0f : 0;
    offset.x += (direction == LEFT) ? -1.0f * seconds * 60.0f : 0;
    offset.x += (direction == RIGHT) ? 1.0f * seconds * 60.0f : 0;
    sprite_rect = change_enemy_animation(enemy, direction);
    sfSprite_setTextureRect(enemy->sprite, sprite_rect);
    anim(enemy);
    if (check_enemy_collision(scene, enemy, offset) == 0) {
        sfSprite_move(enemy->sprite, offset);
        sfCircleShape_move(enemy->detect_zone, offset);
    }
}
