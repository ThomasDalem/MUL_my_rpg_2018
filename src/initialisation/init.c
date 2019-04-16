/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** init
*/

#include "prototype.h"

sfIntRect create_char_perso(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.height = height;
    rect.width = width;
    return (rect);
}

stats create_stat_perso(int life, int attack, int defense, int magic)
{
    stats stat;

    stat.max_life = life;
    stat.attack = attack;
    stat.defense = defense;
    stat.magic = magic;
    return (stat);
}

static int init_perso(obj_t *perso)
{
    perso->sprite = sfSprite_create();
    perso->texture = sfTexture_createFromFile("assets/textures/link.png", NULL);
    sfSprite_setTexture(perso->sprite, perso->texture, sfFalse);
    perso->char_down = create_char_perso(0, perso->nb_perso * 120, 16, 16);
    perso->char_up = create_char_perso(0, perso->nb_perso * 120 + 61, 16, 16);
    perso->char_left = create_char_perso(0, perso->nb_perso * 120 + 30, 16, 16);
    perso->char_right = create_char_perso(0, perso->nb_perso * 120 + 90, 16, 16);
    perso->move.y = 3;
    perso->move.x = 3;
    perso->move_clock = sfClock_create();
    perso->anim_clock = sfClock_create();
    perso->stat = create_stat_perso(100, 10, 30, 5);
    perso->stat = (stats){100, 100, 30, 5};
    sfSprite_setTextureRect(perso->sprite, perso->char_down);
    sfSprite_setScale(perso->sprite, perso->move);
    return (0);
}

int init_all(scene_t *scene, pause_s *pause, inv_t *invent)
{
    sfRenderWindow_setFramerateLimit(scene->window, 60);
    scene->ennemi = NULL;
    scene->pnj = NULL;

    if (init_pause(pause) == 84 || scene->perso == NULL)
        return (84);
    if (init_perso(scene->perso) == 84)
        return (84);
    if (init_inventory(invent, scene) == 84)
        return (84);
    if (init_ennemie(scene) == 84)
        return (84);
    if (init_pnj(scene) == 84)
        return (84);
    return (1);
}
