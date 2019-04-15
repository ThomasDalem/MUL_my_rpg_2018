/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** check_collisions
*/

#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include "collisions.h"

int check_collision(scene_t *scene)
{
    sfFloatRect player = sfSprite_getGlobalBounds(scene->perso->sprite);
    sfFloatRect npc = sfSprite_getGlobalBounds(scene->ennemi->sprite);

    if (is_colliding(player, npc)) {
        return (1);
    }
    return (0);
}
