/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** inventory_gestion
*/

#include "prototype.h"

void set_sprite_inventory(inv_t *invent, scene_t *scene, sfVector2f pos_sprite)
{
    scene->perso->move.x = 10;
    scene->perso->move.y = 10;
    sfSprite_setTexture(invent->sprite, scene->perso->texture, sfTrue);
    sfSprite_setTextureRect(invent->sprite, scene->perso->char_down);
    sfSprite_setPosition(invent->sprite, pos_sprite);
    sfSprite_setScale(invent->sprite, scene->perso->move);
}

void key_event(sfEvent *event, scene_t *scene, inv_t *invent)
{
    sfVector2i mouse;

    if (event->type == sfEvtMouseButtonPressed) {
        check_all_use_throw_button(invent->button, scene);
        if (cond_use_throw(invent->button, scene) == 1)
            return;
    }
    if (event->type == sfEvtMouseButtonPressed) {
        mouse = sfMouse_getPositionRenderWindow(scene->window);
        check_all_button(invent->button, scene);
    }
    if (event->type == sfEvtMouseButtonReleased) {
        switch_equipement(scene, invent);
        reboot_use_throw(invent->button);
    }
}

static int invent_event(sfEvent *event, scene_t *scene, inv_t *invent)
{
    if (event->key.code == sfKeyF)
        return (1);
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyS)
            sfSprite_setTextureRect(invent->sprite, scene->perso->char_down);
        if (event->key.code == sfKeyZ)
            sfSprite_setTextureRect(invent->sprite, scene->perso->char_up);
        if (event->key.code == sfKeyQ)
            sfSprite_setTextureRect(invent->sprite, scene->perso->char_left);
        if (event->key.code == sfKeyD)
            sfSprite_setTextureRect(invent->sprite, scene->perso->char_right);
    }
    if (event->type == sfEvtClosed)
        return (3);
    key_event(event, scene, invent);
    return (0);
}

void color_gestion(inv_t *invent)
{
    sfTime time = sfClock_getElapsedTime(invent->clock_potion);
    float second = sfTime_asSeconds(time);

    if (invent->color_potion.a == 0)
        return;
    if (second > 0.01) {
        if (invent->color_potion.a > 0) {
            invent->color_potion.a--;
            sfText_setColor(invent->pot, invent->color_potion);
        }
        sfClock_restart(invent->clock_potion);
    }
}

int inventory_gestion(inv_t *invent, scene_t *scene)
{
    int p = 0;
    sfEvent event;

    while (p == 0) {
        change_potion_str(invent, scene);
        sfRenderWindow_clear(scene->window, sfBlack);
        disp_invent(scene, invent);
        button_disp(invent->button, scene);
        use_throw_gestion(invent->button, scene);
        color_gestion(invent);
        sfRenderWindow_display(scene->window);
        while (sfRenderWindow_pollEvent(scene->window, &event))
            p = invent_event(&event, scene, invent);
    }
    return (p);
}
