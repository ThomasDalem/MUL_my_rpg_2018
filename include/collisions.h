/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** collisions
*/

#ifndef COLLISIONS_H_
#define COLLISIONS_H_

#include "prototype.h"
#include "structures.h"

int will_collide(sfSprite *sprite1, sfSprite *sprite2, sfVector2f direction);
int will_rect_collide(sfFloatRect rect1,
                        sfFloatRect rect2, sfVector2f direction);
int will_intersect(sfSprite *sprite1, sfSprite *sprite2, sfVector2f direction);
int is_colliding(sfFloatRect rect1, sfFloatRect rect2);
int check_collision(scene_t *scene, sfVector2f direction);
int check_enemy_collision(scene_t *scene, obj_t *enemy, sfVector2f direction);

int check_collision_enemies(obj_t *character, obj_t *enemies, sfVector2f dir);
int check_collision_npc(sfSprite *player, obj_t *npc, sfVector2f dir);
int check_collision_objs(sfSprite *player, map_obj_t *objects, sfVector2f dir);

#endif /* !COLLISIONS_H_ */
