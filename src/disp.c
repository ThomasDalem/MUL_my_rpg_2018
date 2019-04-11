/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** disp
*/

#include "prototype.h"

void disp_scene(scene_t *scene)
{
    obj_t *ennemie = scene->ennemi;

    sfRenderWindow_clear(scene->window, sfBlack);
    sfRenderWindow_drawSprite(scene->window, scene->perso.sprite_perso, NULL);
    while (ennemie) {
        sfRenderWindow_drawSprite(scene->window, ennemie->sprite_perso, NULL);
        sfRenderWindow_drawRectangleShape(scene->window, ennemie->detect_zone, NULL);
        ennemie = ennemie->next;
    }
    sfRenderWindow_display(scene->window);
}