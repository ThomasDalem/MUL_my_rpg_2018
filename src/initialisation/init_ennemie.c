/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** init_ennemie
*/

#include "prototype.h"

void create_zone_enn(obj_t *ennemie, int zone)
{
    sfFloatRect size_sp = sfSprite_getGlobalBounds(ennemie->sprite);
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
    ennemie->texture = sfTexture_createFromFile(
        "assets/textures/player_2.png", NULL);
    ennemie->char_down = create_char_perso(8, 4, 24, 44);
    ennemie->char_up = create_char_perso(202, 6, 24, 44);
    ennemie->char_left = create_char_perso(72, 6, 24, 44);
    ennemie->char_right = create_char_perso(138, 4, 24, 44);
    ennemie->stat = (stats){100, 30, 30, 5};
    ennemie->sprite = sfSprite_create();
    sfSprite_setTexture(ennemie->sprite, ennemie->texture, sfFalse);
    ennemie->move.y = 1.5;
    ennemie->move.x = 1.5;
    sfSprite_setTextureRect(ennemie->sprite, ennemie->char_down);
    sfSprite_setScale(ennemie->sprite, ennemie->move);
    ennemie->text.phrase = sfText_create();
    ennemie->action.clock = sfClock_create();
}

int init_ennemie(scene_t *scene)
{
    obj_t *ennemi = malloc(sizeof(obj_t));
    sfVector2f pos = {1000, 500};

    if (ennemi == NULL)
        return (84);
    memset(ennemi, 0, sizeof(obj_t) * 1);
    create_ennemie(ennemi);
    sfSprite_setPosition(ennemi->sprite, pos);
    if (init_fight_perso(ennemi) == 84)
        return (84);
    create_zone_enn(ennemi, 150);
    ennemi->anim_clock = sfClock_create();
    ennemi->move_clock = sfClock_create();
    ennemi->next = scene->ennemi;
    scene->ennemi = ennemi;
    return (0);
}
