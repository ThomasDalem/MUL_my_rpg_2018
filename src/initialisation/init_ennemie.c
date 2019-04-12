/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** init_ennemie
*/

#include "prototype.h"

void create_zone_enn(obj_t *ennemie, int zone)
{
    sfFloatRect size_sp = sfSprite_getGlobalBounds(ennemie->sprite_perso);
    sfVector2f size;
    sfVector2f pos;

    pos.x = size_sp.left + size_sp.width / 2;
    pos.y = size_sp.top + size_sp.height / 2;
    size.x = zone;
    size.y = zone;
    ennemie->detect_zone = sfCircleShape_create();
    sfCircleShape_setOutlineColor(ennemie->detect_zone, sfRed);
    sfCircleShape_setOutlineThickness(ennemie->detect_zone, 2);
    sfCircleShape_setFillColor(ennemie->detect_zone, sfTransparent);
    sfCircleShape_setRadius(ennemie->detect_zone, zone);
    sfCircleShape_setOrigin(ennemie->detect_zone, size);
    sfCircleShape_setPosition(ennemie->detect_zone, pos);
}

void create_ennemie(obj_t *ennemie)
{
    ennemie->texture = sfTexture_createFromFile("assets/textures/link.png", NULL);
    ennemie->char_down = create_char_perso(0, 120, 16, 16);
    ennemie->char_up = create_char_perso(0, 120 + 61, 16, 16);
    ennemie->char_left = create_char_perso(0, 120 + 30, 16, 16);
    ennemie->char_right = create_char_perso(0, 120 + 90, 16, 16);
    ennemie->sprite_perso = sfSprite_create();
    sfSprite_setTexture(ennemie->sprite_perso, ennemie->texture, sfFalse);
    ennemie->move.y = 3;
    ennemie->move.x = 3;
    //ennemie->stat = create_stat_perso(50, 10, 30, 5);
    sfSprite_setTextureRect(ennemie->sprite_perso, ennemie->char_down);
    sfSprite_setScale(ennemie->sprite_perso, ennemie->move);
}

int init_ennemie(scene_t *scene)
{
    obj_t *ennemi = malloc(sizeof(obj_t));
    sfVector2f pos;

    if (ennemi == NULL)
        return (84);
    memset(ennemi, 0, sizeof(obj_t) * 1);
    pos.x = 1000;
    pos.y = 500;
    create_ennemie(ennemi);
    sfSprite_setPosition(ennemi->sprite_perso, pos);
    create_zone_enn(ennemi, 150);
    ennemi->timer.clock = sfClock_create();
    ennemi->next = scene->ennemi;
    scene->ennemi = ennemi;
    return (0);
}
