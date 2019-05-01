/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** fight_move
*/

#include "prototype.h"
#include "collisions.h"

void anim_rigth_fight(obj_t *player, int move)
{
    sfIntRect rect_perso = sfSprite_getTextureRect(player->sprite);
    sfTime elapsed_time = sfClock_getElapsedTime(player->anim_clock);
    float time = sfTime_asSeconds(elapsed_time);

    if (time > 0.1) {
        if (rect_perso.left < player->fight->max_char)
            rect_perso.left = rect_perso.left + move;
        else
            rect_perso.left = player->fight->beg_char;
        sfSprite_setTextureRect(player->sprite, rect_perso);
        sfClock_restart(player->anim_clock);
    }
}

void anim_left_fight(obj_t *player, int move)
{
    sfIntRect rect_perso = sfSprite_getTextureRect(player->sprite);
    sfTime elapsed_time = sfClock_getElapsedTime(player->anim_clock);
    float time = sfTime_asSeconds(elapsed_time);

    if (time > 0.1) {
        if (rect_perso.left > player->fight->beg_char)
            rect_perso.left = rect_perso.left + move;
        else
            rect_perso.left = player->fight->max_char;
        sfSprite_setTextureRect(player->sprite, rect_perso);
        sfClock_restart(player->anim_clock);
    }
}

int animation_fight(obj_t *player, int direction)
{
    sfIntRect sprite_rect = sfSprite_getTextureRect(player->sprite);

    if (direction == LEFT)
        return (-40);
    if (direction == RIGHT)
        return (40);
    return (0);
}

void move_fight(scene_t *scene, int direction)
{
    sfVector2f offset = {0, 0};
    sfIntRect sprite_rect;
    int move = animation_fight(scene->perso, direction);
    sfTime time = sfClock_getElapsedTime(scene->perso->move_clock);
    float second = sfTime_asSeconds(time);

    offset.x += (direction == LEFT) ? -20 : 0;
    offset.x += (direction == RIGHT) ? 20 : 0;
    if (direction == LEFT && scene->perso->fight->is_jumping != 1)
        anim_left_fight(scene->perso, move);
    if (direction == RIGHT && scene->perso->fight->is_jumping != 1)
        anim_rigth_fight(scene->perso, move);
    scene->ennemi->action.move = offset;
    if (second > 0.05 - scene->perso->stat.magic / 100) {
        if (!will_collide(scene->perso->sprite, scene->ennemi->sprite, offset))
            sfSprite_move(scene->perso->sprite, offset);
        sfClock_restart(scene->perso->move_clock);
    }
}
