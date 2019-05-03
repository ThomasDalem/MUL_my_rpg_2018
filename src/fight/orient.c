/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** orient
*/

#include "prototype.h"

void orient_left_right(scene_t *scene)
{
    sfIntRect rect_perso = sfSprite_getTextureRect(scene->perso->sprite);
    sfIntRect rect_enn = sfSprite_getTextureRect(scene->ennemi->sprite);

    if (rect_perso.left < 167 && scene->perso->fight->is_jumping == 0) {
        init_right_perso(scene->perso);
        sfSprite_setTextureRect(scene->perso->sprite,
                                scene->perso->fight->rect);
    }
    if (rect_enn.left > 147 && scene->ennemi->fight->is_jumping == 0) {
        init_left_perso(scene->ennemi);
        sfSprite_setTextureRect(scene->ennemi->sprite,
                                scene->ennemi->fight->rect);
    }
}

void orient_right_left(scene_t *scene)
{
    sfIntRect rect_perso = sfSprite_getTextureRect(scene->perso->sprite);
    sfIntRect rect_enn = sfSprite_getTextureRect(scene->ennemi->sprite);

    if (rect_perso.left > 147 && scene->perso->fight->is_jumping == 0) {
        init_left_perso(scene->perso);
        sfSprite_setTextureRect(scene->perso->sprite,
                                scene->perso->fight->rect);
    }
    if (rect_enn.left < 167 && scene->ennemi->fight->is_jumping == 0) {
        init_right_perso(scene->ennemi);
        sfSprite_setTextureRect(scene->ennemi->sprite,
                                scene->ennemi->fight->rect);
    }
}

void check_orient(scene_t *scene)
{
    float pos_perso = fabs(sfSprite_getPosition(scene->perso->sprite).x);
    float pos_ennemie = fabs(sfSprite_getPosition(scene->ennemi->sprite).x);

    if (pos_perso - pos_ennemie > 0)
        orient_right_left(scene);
    if (pos_perso - pos_ennemie < 0)
        orient_left_right(scene);
}
