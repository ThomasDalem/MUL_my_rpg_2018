/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** anime_ennemi
*/

#include "prototype.h"

void anime_enn(scene_t *scene, sfVector2f move)
{
    sfIntRect rect_perso = sfSprite_getTextureRect(scene->ennemi->sprite_perso);

    scene->ennemi->timer.time = sfClock_getElapsedTime(scene->ennemi->timer.clock);
    scene->ennemi->timer.second = sfTime_asMilliseconds(scene->ennemi->timer.time);
    if (scene->ennemi->timer.second > 200) {
        if (rect_perso.top <= 0)
            rect_perso.top = rect_perso.top + 30;
        else
            rect_perso.top = 0;
        sfSprite_setTextureRect(scene->ennemi->sprite_perso, rect_perso);
        sfSprite_move(scene->ennemi->sprite_perso, move);
        sfCircleShape_move(scene->ennemi->detect_zone, move);
        sfClock_restart(scene->ennemi->timer.clock);
    }
}

void move_enn_up(scene_t *scene, int x, int y)
{
    sfVector2f move;
    sfIntRect rect = sfSprite_getTextureRect(scene->ennemi->sprite_perso);

    move.x = x;
    move.y = y;
    if (rect.left != 61)
        sfSprite_setTextureRect(scene->ennemi->sprite_perso, scene->ennemi->char_up);
    anime_enn(scene, move);
}

void move_enn_down(scene_t *scene, int x, int y)
{
    sfVector2f move;
    sfFloatRect rect = sfSprite_getGlobalBounds(scene->ennemi->sprite_perso);

    move.x = x;
    move.y = y;
    if (rect.left != 0) {
        sfSprite_setTextureRect(scene->ennemi->sprite_perso, scene->ennemi->char_down);
    }
    anime_enn(scene, move);
}

void move_enn_left(scene_t *scene, int x, int y)
{
    sfVector2f move;
    sfFloatRect rect = sfSprite_getGlobalBounds(scene->ennemi->sprite_perso);

    move.x = x;
    move.y = y;
    if (rect.left != 30)
        sfSprite_setTextureRect(scene->ennemi->sprite_perso, scene->ennemi->char_left);
    anime_enn(scene, move);
}

void move_enn_right(scene_t *scene, int x, int y)
{
    sfVector2f move;
    sfFloatRect rect = sfSprite_getGlobalBounds(scene->ennemi->sprite_perso);

    move.x = x;
    move.y = y;
    if (rect.left != 90)
        sfSprite_setTextureRect(scene->ennemi->sprite_perso, scene->ennemi->char_right);
    anime_enn(scene, move);
}