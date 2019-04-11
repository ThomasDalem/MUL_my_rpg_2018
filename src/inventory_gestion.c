/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** inventory_gestion
*/

#include "prototype.h"

void set_sprite_inventory(inv_t *invent, scene_t *scene, sfVector2f pos_sprite)
{
    scene->perso.move.x = 10;
    scene->perso.move.y = 10;
    sfSprite_setTexture(invent->sprite, scene->perso.texture, sfTrue);
    sfSprite_setTextureRect(invent->sprite, scene->perso.char_down);
    sfSprite_setPosition(invent->sprite, pos_sprite);
    sfSprite_setScale(invent->sprite, scene->perso.move);
}

static int invent_event(sfEvent *event, scene_t *scene, inv_t *invent)
{
    if (event->key.code == sfKeyF) {
        return (1);
    }
     if (event->type == sfEvtKeyPressed) { 
        if (event->key.code == sfKeyS)
            sfSprite_setTextureRect(invent->sprite, scene->perso.char_down);
        if (event->key.code == sfKeyZ)
            sfSprite_setTextureRect(invent->sprite, scene->perso.char_up);
        if (event->key.code == sfKeyQ)
            sfSprite_setTextureRect(invent->sprite, scene->perso.char_left);
        if (event->key.code == sfKeyD)
            sfSprite_setTextureRect(invent->sprite, scene->perso.char_right);
    }
    if (event->type == sfEvtClosed)
        return (3);
    return (0);
}

static void disp_invent(scene_t *scene, inv_t *invent)
{
    int i = 0;

    sfRenderWindow_drawSprite(scene->window, invent->sprite, NULL);
    sfRenderWindow_drawText(scene->window, invent->life, NULL);
    sfRenderWindow_drawText(scene->window, invent->attack, NULL);
    sfRenderWindow_drawText(scene->window, invent->defense, NULL);
    sfRenderWindow_drawText(scene->window, invent->magic, NULL);
    while (invent->button[i] != NULL) {
        sfRenderWindow_drawRectangleShape(scene->window, invent->button[i]->but, NULL);
        i++;
    }
}

int inventory_gestion(inv_t *invent, scene_t *scene)
{
    int p = 0;
    sfEvent event;

    while (p == 0) {
        sfRenderWindow_clear(scene->window, sfBlack);
        disp_invent(scene, invent);
        sfRenderWindow_display(scene->window);
        while (sfRenderWindow_pollEvent(scene->window, &event))
            p = invent_event(&event, scene, invent);
    }
    return (p);
}
