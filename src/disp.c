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
    obj_t *pnj = scene->pnj;

    sfRenderWindow_clear(scene->window, sfBlack);
    sfRenderWindow_drawSprite(scene->window, scene->map->background_sprite, NULL);
    sfRenderWindow_drawSprite(scene->window, scene->perso->sprite, NULL);
    while (ennemie) {
        sfRenderWindow_drawSprite(scene->window, ennemie->sprite, NULL);
        ennemie = ennemie->next;
    }
    while (pnj) {
        sfRenderWindow_drawSprite(scene->window, pnj->sprite, NULL);
        if (pnj->discuss == 1) {
            sfRenderWindow_drawSprite(scene->window, pnj->text.sprite_bubble, NULL);
            sfRenderWindow_drawText(scene->window, pnj->text.phrase, NULL);
        }
        pnj = pnj->next;
    }
    sfRenderWindow_display(scene->window);
}