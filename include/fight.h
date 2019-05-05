/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** fight
*/

#ifndef FIGHT_H_
#define FIGHT_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "structures.h"
#include "collisions.h"

int fight_event(scene_t *scene, sfEvent *event,
                pause_s *pause, inv_t *invent);
void disp_fight(scene_t *scene, sfSprite *sprite, inv_t *invent);
//fight/repulse.c
void check_repulse(scene_t *scene, sfSprite *sprite, inv_t *invent);
void set_sprite_inventory(inv_t *invent, scene_t *scene,
                            sfVector2f pos_sprite);
sfIntRect create_char_perso(int top, int left, int width, int height);
int select_perso(scene_t *scene, int *gamemode);
void finish_init_fight_perso(obj_t *perso, int x, int y);
int fight_event(scene_t *scene, sfEvent *event,
                pause_s *pause, inv_t *invent);
void move_fight(scene_t *scene, int direction);
int is_a_fight(scene_t *scene, inv_t *invent, pause_s *pause);
void set_text(sfText *text, char *str, sfFont *font, sfVector2f pos);
//action
void attack(obj_t *perso1, obj_t *perso2);
void attack_condition(obj_t *perso);
void jump(scene_t *scene);
void defense_condition(obj_t *perso);
void defense(obj_t *perso);
int cond_repulse(sfFloatRect per_rect, sfFloatRect enn_rect);
void check_orient(scene_t *scene);
void disp_hud(scene_t *scene, obj_t *perso, int x, int y);
sfSprite *create_sprite(char *str);
void ennemi_action(scene_t *scene);

void anim_left_fight(obj_t *player, int move);
void anim_rigth_fight(obj_t *player, int move);
int diff(obj_t *perso, obj_t *ennemi);
int animation_fight(obj_t *player, int direction);
int check_alive(scene_t *scene);
void create_use_button(but_s *button, int x, int y);
void create_throw_button(but_s *button, int x, int y);
void free_enemy(obj_t *obj);
void remove_enemy(obj_t *enemy, obj_t **list);
void after_fight_function(scene_t *scene, sfVector2f pos);
void jump_condition(scene_t *scene);
void start_repulse(scene_t *scene);
#endif /* !FIGHT_H_ */
