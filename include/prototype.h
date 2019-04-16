/*
** EPITECH PROJECT, 2019
** prototype.h
** File description:
** prototype
*/

#ifndef PROTOTYPE_H
#define PROTOTYPE_H

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
#include "my.h"

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

void move_player(scene_t *scene, obj_t *player, int direction);
int will_collide(sfSprite *sprite1, sfSprite *sprite2, sfVector2f direction);

//anime_ennemie.c

//close.c
void close_window(scene_t *scene, pause_s *pause, int *gamemode);

//discuss.c
void start_discuss(scene_t *scene);

//disp
void disp_scene(scene_t *scene);

//event.c
int allevent(scene_t *scene, sfEvent *event, pause_s *pause, inv_t *invent);

//game.c
sfRenderWindow *createmywindow(unsigned int width, unsigned int height);
void game(int *gamemode, scene_t *scene);
void anim(obj_t *player);

//initialisation/init.c
int init_all(scene_t *scene, pause_s *pause, inv_t *invent);
stats create_stat_perso(int life, int attack, int defense, int magic);

//initialisation/init_ennemie.c
int init_ennemie(scene_t *scene);
void create_zone_enn(obj_t *ennemie, int zone);

//initialisation/init_inventory.c
int init_inventory(inv_t *invent, scene_t *scene);
int set_stats_equipement(inv_t *invent);
int set_equipement(inv_t *invent, scene_t *scene);

//initialisation/init_menu.c
int button_is_clicked(sfRectangleShape *button, sfVector2i click_position);
int init_end_button(but_s *button);
int init_start_button(but_s *button);

//inititalisation/init_phrase.c
int copy_into_by(obj_t *pnj);
int copy_into_sell(obj_t *pnj);
int copy_into_hi(obj_t *pnj);

//initialisation/init_pause.c
int init_pause(pause_s *pause);

//initialisation/init_pnj.c
int init_pnj(scene_t *scene);
//initialisation/init_sound.c
int init_music(scene_t *scene);

//inventory_gestion.c
int inventory_gestion(inv_t *invent, scene_t *scene);

//main.c

//menu.c
void screenevent(sfEvent *event, scene_t *scene, int *gamemode);
void disp_menu(scene_t *scene);
int init_menu_scene(scene_t *scene);
void destroy_menu(scene_t *scene, int *gamemode);
int mainscreen(int *gamemode, scene_t *scene);

//mouse.c
void cond_mouse(but_s **button, scene_t *scene);

//move.c
void move_right(scene_t *scene);
void move_left(scene_t *scene);
void move_down(scene_t *scene);
void move_up(scene_t *scene);

//move ennemie
void move_enn_up(scene_t *scene, int x, int y);
void move_enn_down(scene_t *scene, int x, int y);
void move_enn_left(scene_t *scene, int x, int y);
void move_enn_right(scene_t *scene, int x, int y);
void move_ennemie(scene_t *scene);

//pause.c
int pause_function(scene_t *scene, pause_s *pause);

//select.c

//set_str.c
char *set_attack_str(scene_t *scene);
char *set_life_str(scene_t *scene);
char *set_defense_str(scene_t *scene);
char *set_magic_str(scene_t *scene);

//tools.c
int lf_stat(char *str, char **env);
int my_argvlen(char **argv);

#endif
