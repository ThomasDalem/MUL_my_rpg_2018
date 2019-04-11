/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** check_collision
*/

#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include "printf.h"

int is_colliding(sfFloatRect rect1, sfFloatRect rect2)
{
    if (rect1.left < rect2.left + rect2.width &&
        rect1.left + rect1.width > rect2.left &&
        rect1.top < rect2.top + rect2.height &&
        rect1.top + rect1.height > rect2.top) {
        my_printf("collision\n");
    }
    return (0);
}

int will_intersect(sfSprite *sprite1, sfSprite *sprite2, sfVector2f direction)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(sprite1);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(sprite2);

    if (is_colliding(rect1, rect2)) {

    }
}
