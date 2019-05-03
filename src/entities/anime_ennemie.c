/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** anime_ennemi
*/

#include "prototype.h"

void anime_enn(obj_t *enemy)
{
    sfIntRect rect_perso = sfSprite_getTextureRect(enemy->sprite);
    float time = sfTime_asSeconds(sfClock_getElapsedTime(enemy->anim_clock));

    if (time > 0.1) {
        if (rect_perso.left <= 0)
            rect_perso.left = rect_perso.left + 32;
        else
            rect_perso.left = 0;
        sfSprite_setTextureRect(enemy->sprite, rect_perso);
        sfClock_restart(enemy->anim_clock);
    }
}

void move_enn_up(obj_t *enemy)
{
    sfVector2f move = {0, 0};
    sfIntRect rect = sfSprite_getTextureRect(enemy->sprite);
    float time = sfTime_asSeconds(sfClock_getElapsedTime(enemy->move_clock));

    move.y = -1.0f * time * 60.0f;
    if (rect.top != 202)
        sfSprite_setTextureRect(enemy->sprite, enemy->char_up);
}

void move_enn_down(obj_t *enemy)
{
    sfVector2f move = {0, 0};
    sfFloatRect rect = sfSprite_getGlobalBounds(enemy->sprite);
    float time = sfTime_asSeconds(sfClock_getElapsedTime(enemy->move_clock));

    move.y = 1.0f * time * 60.0f;
    if (rect.top != 8)
        sfSprite_setTextureRect(enemy->sprite,
                                enemy->char_down);
}

void move_enn_left(obj_t *enemy)
{
    sfVector2f move = {0, 0};
    sfFloatRect rect = sfSprite_getGlobalBounds(enemy->sprite);
    float time = sfTime_asSeconds(sfClock_getElapsedTime(enemy->move_clock));

    move.x = -1.0f * time * 60.0f;
    if (rect.top != 72)
        sfSprite_setTextureRect(enemy->sprite,
                                enemy->char_left);
}

void move_enn_right(obj_t *enemy)
{
    sfVector2f move = {0, 0};
    sfFloatRect rect = sfSprite_getGlobalBounds(enemy->sprite);
    float time = sfTime_asSeconds(sfClock_getElapsedTime(enemy->move_clock));

    move.x = 1.0f * time * 60.0f;
    if (rect.top != 138)
        sfSprite_setTextureRect(enemy->sprite,
                                enemy->char_right);
}
