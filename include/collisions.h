/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** collisions
*/

#ifndef COLLISIONS_H_
#define COLLISIONS_H_

#include <SFML/Graphics/Sprite.h>

#include "prototype.h"
#include "structures.h"

int will_collide(sfSprite *sprite1, sfSprite *sprite2, sfVector2f direction);
int will_intersect(sfSprite *sprite1, sfSprite *sprite2, sfVector2f direction);
int is_colliding(sfFloatRect rect1, sfFloatRect rect2);
int check_collision(scene_t *scene, sfVector2f direction);

#endif /* !COLLISIONS_H_ */
