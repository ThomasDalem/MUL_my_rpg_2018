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

void set_good_rect(scene_t *scene, sfVector2f move, sfIntRect *rect_perso)
{
    int i = 0;
    sfIntRect rect = *rect_perso;

    if (fabs(move.x) > fabs(move.y))
        i = 1;
    else 
        i = 0;
    if (i == 1 && move.x < 0)
        *rect_perso = scene->ennemi->char_left;
    if (i == 1 && move.x > 0)
        *rect_perso = scene->ennemi->char_right;
    if (i == 0 && move.y < 0)
        *rect_perso = scene->ennemi->char_up;
    if (i == 0 && move.y > 0)
        *rect_perso = scene->ennemi->char_down;
    rect_perso->left = rect_perso->left + rect.left;
}

void follow(scene_t *scene, sfFloatRect pos_enn, sfFloatRect pos_perso)
{
    sfVector2f move;
    int x;
    int y;
    sfIntRect rect_perso = sfSprite_getTextureRect(scene->ennemi->sprite);
    sfTime elapsed_time = sfClock_getElapsedTime(scene->ennemi->anim_clock);
    float time = sfTime_asSeconds(elapsed_time);

    x = (pos_perso.left + pos_perso.width) - (pos_enn.left + pos_enn.width);
    y = (pos_perso.top + pos_perso.height) - (pos_enn.top + pos_enn.height);
    move.x = x / 15;
    move.y = y / 15;
    set_good_rect(scene, move, &rect_perso);
    if (time > 0.2) {
        if (rect_perso.left <= 0)
            rect_perso.left = rect_perso.left + 32;
        else
            rect_perso.left = 0;
        sfSprite_setTextureRect(scene->ennemi->sprite, rect_perso);
        if (!will_collide(scene->ennemi->sprite, scene->perso->sprite, move)) {
            sfSprite_move(scene->ennemi->sprite, move);
            sfCircleShape_move(scene->ennemi->detect_zone, move);
        }
        sfClock_restart(scene->ennemi->anim_clock);
    }
}

void move_ennemie(scene_t *scene)
{
    obj_t *ennemi = scene->ennemi;
    sfVector2f enn;
    sfFloatRect pos_zone;
    sfFloatRect pos_enn;
    sfFloatRect pos_perso = sfSprite_getGlobalBounds(scene->perso->sprite);

    while (scene->ennemi != NULL) {
        pos_zone = sfCircleShape_getGlobalBounds(scene->ennemi->detect_zone);
        pos_enn = sfSprite_getGlobalBounds(scene->ennemi->sprite);
        if (sfFloatRect_intersects(&pos_zone, &pos_perso, NULL) == sfTrue)
            follow(scene, pos_enn, pos_perso);
        else
            move_random(scene);
        scene->ennemi = scene->ennemi->next;
    }
    scene->ennemi = ennemi;
}