/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** move_ennemie
*/

#include "prototype.h"

void move_random(scene_t *scene)
{
    int r = 0;
    srand(time(NULL));
    r = rand() % 4;
    if (r == 0)
        move_enn_up(scene, 0, -10);
    if (r == 1)
        move_enn_left(scene, -10, 0);
    if (r == 2)
        move_enn_right(scene, 10, 0);
    if (r == 3)
        move_enn_down(scene, 0, 10);
}

void follow(scene_t *scene, sfFloatRect pos_enn, sfFloatRect pos_perso)
{
    sfVector2f move;
    int x;
    int y;
    sfIntRect rect_perso = sfSprite_getTextureRect(scene->ennemi->sprite_perso);

    x = (pos_perso.left + pos_perso.width) - (pos_enn.left + pos_enn.width);
    y = (pos_perso.top + pos_perso.height) - (pos_enn.top + pos_enn.height);
    move.x = x / 15;
    move.y = y / 15;
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

void move_ennemie(scene_t *scene)
{
    obj_t *ennemi = scene->ennemi;
    sfVector2f enn;
    sfFloatRect pos_zone;
    sfFloatRect pos_enn;
    sfFloatRect pos_perso = sfSprite_getGlobalBounds(scene->perso.sprite_perso);

    while (scene->ennemi != NULL) {
        pos_zone = sfCircleShape_getGlobalBounds(scene->ennemi->detect_zone);
        pos_enn = sfSprite_getGlobalBounds(scene->ennemi->sprite_perso);
        if (sfFloatRect_intersects(&pos_zone, &pos_perso, NULL) == sfTrue)
            follow(scene, pos_enn, pos_perso);
        else
            move_random(scene);
        scene->ennemi = scene->ennemi->next;
    }
    scene->ennemi = ennemi;
}