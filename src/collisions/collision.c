/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** collision
*/

#include <SFML/Graphics/Sprite.h>
#include <unistd.h>

int is_colliding(sfFloatRect rect1, sfFloatRect rect2)
{
    if (rect1.left < rect2.left + rect2.width &&
        rect1.left + rect1.width > rect2.left &&
        rect1.top < rect2.top + rect2.height &&
        rect1.top + rect1.height > rect2.top) {
        write(1, "collision\n", 10);
        return (1);
    }
    return (0);
}

int will_intersect(sfSprite *sprite1, sfSprite *sprite2, sfVector2f direction)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(sprite1);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(sprite2);

    direction = direction;
    if (is_colliding(rect1, rect2)) {
        return (1);
    }
    return (0);
}
