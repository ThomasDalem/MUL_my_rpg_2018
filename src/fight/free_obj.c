/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** free_obj
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/CircleShape.h>
#include <stdlib.h>
#include "structures.h"

void free_enemy(obj_t *obj)
{
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
    sfCircleShape_destroy(obj->detect_zone);
    sfClock_destroy(obj->move_clock);
    sfClock_destroy(obj->anim_clock);
    sfClock_destroy(obj->dir_clock);
    free(obj);
}
