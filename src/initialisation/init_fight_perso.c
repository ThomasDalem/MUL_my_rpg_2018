/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_fight_perso
*/

#include "prototype.h"

int init_fight_perso(obj_t *perso)
{
    perso->fight = malloc(sizeof(struct fight_t));
    //perso->fight->texture = sfTexture_createFromFile("assets/textures/link_battle.png", NULL);
    perso->fight->char_left = create_char_perso(0, 167, 41, 17);
    perso->fight->char_right = create_char_perso(0, 8, 41, 17);
    //sfSprite_setTexture(perso->sprite, perso->fight->texture, sfTrue);
    //sfSprite_setTextureRect(perso->sprite, perso->fight->char_left);
    return (0);
}