/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** anime_ennemi
*/

#include "prototype.h"

void anime_enn(scene_t *scene, sfVector2f move)
{
    sfIntRect rect_perso = sfSprite_getTextureRect(scene->ennemi->sprite);
    sfTime elapsed_time = sfClock_getElapsedTime(scene->ennemi->anim_clock);
    float time = sfTime_asSeconds(elapsed_time);

    if (time > 0.2) {
        if (rect_perso.left <= 0)
            rect_perso.left = rect_perso.left + 32;
        else
            rect_perso.left = 0;
        sfSprite_setTextureRect(scene->ennemi->sprite, rect_perso);
        sfSprite_move(scene->ennemi->sprite, move);
        sfCircleShape_move(scene->ennemi->detect_zone, move);
        sfClock_restart(scene->ennemi->anim_clock);
    }
}

void move_enn_up(scene_t *scene, int x, int y)
{
    sfVector2f move = {x, y};
    sfIntRect rect = sfSprite_getTextureRect(scene->ennemi->sprite);

    if (rect.top != 202)
        sfSprite_setTextureRect(scene->ennemi->sprite, scene->ennemi->char_up);
    anime_enn(scene, move);
}

void move_enn_down(scene_t *scene, int x, int y)
{
    sfVector2f move = {x, y};
    sfFloatRect rect = sfSprite_getGlobalBounds(scene->ennemi->sprite);

    if (rect.top != 8)
        sfSprite_setTextureRect(scene->ennemi->sprite,
                                scene->ennemi->char_down);
    anime_enn(scene, move);
}

void move_enn_left(scene_t *scene, int x, int y)
{
    sfVector2f move = {x, y};
    sfFloatRect rect = sfSprite_getGlobalBounds(scene->ennemi->sprite);

    if (rect.top != 72)
        sfSprite_setTextureRect(scene->ennemi->sprite,
                                scene->ennemi->char_left);
    anime_enn(scene, move);
}

void move_enn_right(scene_t *scene, int x, int y)
{
    sfVector2f move = {x, y};
    sfFloatRect rect = sfSprite_getGlobalBounds(scene->ennemi->sprite);

    if (rect.top != 138)
        sfSprite_setTextureRect(scene->ennemi->sprite,
                                scene->ennemi->char_right);
    anime_enn(scene, move);
}
