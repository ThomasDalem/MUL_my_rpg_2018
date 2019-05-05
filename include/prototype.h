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
#include "inventory.h"
#include "fight.h"

static const int UP = 1;
static const int DOWN = 2;
static const int LEFT = 3;
static const int RIGHT = 4;

void move_player(scene_t *scene, obj_t *player, int direction);
void chose_ennemi_action(scene_t *scene);
void free_enn(scene_t *scene);
void restart_screen(scene_t *scene);
void create_ennemie(obj_t *ennemie);
void init_disp_potion(but_s *things);
void init_potion_str(but_s *thing, char *str, int r);
void set_new_equipement(scene_t *scene, inv_t *invent, int i);
void jump_condition(scene_t *scene);
void  set_already_effect_str(inv_t *invent);
int init_pnj_phrase(obj_t *pnj);
void create_pnj(obj_t *pnj);
void display_intro(sfRenderWindow *window);
void display_end(sfRenderWindow *window);
//anime_ennemie.c

//close.c
void close_window(scene_t *scene,
                  pause_s *pause, int *gamemode, inv_t *invent);

//collision
int check_collision(scene_t *scene, sfVector2f direction);
int will_collide(sfSprite *sprite1, sfSprite *sprite2, sfVector2f direction);
//collisions/collision.c
int is_colliding(sfFloatRect rect1, sfFloatRect rect2);

//discuss.c
void start_discuss(scene_t *scene);

//disp
void disp_scene(scene_t *scene, quest_t *quest);
void disp_hud(scene_t *scene, obj_t *perso, int x, int y);
//event.c
int allevent(scene_t *scene, sfEvent *event, pause_s *pause, inv_t *invent);

//free/free_global.c
int free_global(scene_t *scene);

//free/music_free.c
int free_music(scene_t *scene);

//free/music_free.c
void free_perso(scene_t *scene);

//game.c
sfRenderWindow *createmywindow(int fs, unsigned int w, unsigned int h);
void game(int *gamemode, scene_t *scene, option_t *option);
void anim(obj_t *player);

//initialisation/game
void create_map(map_t *map);
map_t *create_graph(int x, int y);

//initialisation/init.c
int init_all(scene_t *scene, pause_s *pause, inv_t *invent);
stats create_stat_perso(int life, int attack, int defense, int magic);

//initialisation/init_ennemie.c
int init_ennemie(scene_t *scene);
void create_zone_enn(obj_t *ennemie, int zone);

//initialisation/init_fight_perso.c
int init_fight_perso(obj_t *perso);

//initialisation/init_inventory.c
int init_inventory(inv_t *invent, scene_t *scene);
int set_stats_equipement(inv_t *invent);
int set_equipement(inv_t *invent, scene_t *scene);
void set_sprite_inventory(inv_t *invent,
                          scene_t *scene, sfVector2f pos_sprite);
int create_string_equip(but_s *button, struct stats equip);
int set_text_inventory(inv_t *invent, scene_t *scene);
void set_pos_text(inv_t *invent, sfVector2f pos_text);
void set_potion_effect(scene_t *scene, inv_t *invent, int i);
//initialisation/init_menu.c
int button_is_clicked(sfRectangleShape *button, sfVector2i click_position);
int init_end_button(but_s *button);
int init_start_button(but_s *button);
int init_option_button(but_s *button);

//inititalisation/init_phrase.c
int copy_into_by(obj_t *pnj);
int copy_into_sell(obj_t *pnj);
int copy_into_hi(obj_t *pnj);

//initialisation/init_pause.c
int init_pause(pause_s *pause);
//initialisation/potion
void init_potion_str(but_s *thing, char *str, int r);
void init_disp_potion(but_s *things);
//initialisation/init_pnj.c
int init_pnj(scene_t *scene);
//initialisation/init_sound.c
int init_music(scene_t *scene);

//inventory_gestion.c
int inventory_gestion(inv_t *invent, scene_t *scene);
void use_throw_gestion(but_s **button, scene_t *scene);
int cond_use_throw(but_s **button, scene_t *scene);
void check_all_use_throw_button(but_s **button, scene_t *scene);
void disp_invent(scene_t *scene, inv_t *invent);
void change_potion_str(inv_t *invent, scene_t *scene);

//main.c

//menu.c
void screenevent(sfEvent *event, scene_t *scene, 
                    int *gamemode, option_t *option);
void disp_menu(scene_t *scene);
int init_menu_scene(scene_t *scene);
void destroy_menu(scene_t *scene, int *gamemode);
int mainscreen(int *gamemode, scene_t *scene, option_t *option);

//mouse.c
void cond_mouse(but_s **button, scene_t *scene);
sfIntRect change_animation(obj_t *player, int direction);
sfIntRect change_enemy_animation(obj_t *player, int direction);

//move.c
void move_right(scene_t *scene);
void move_left(scene_t *scene);
void move_down(scene_t *scene);
void move_up(scene_t *scene);
sfVector2f get_distance(obj_t *enemy, obj_t *player);
void move_enemy(scene_t *scene, obj_t *player, int direction);
void move_norm(sfFloatRect *pos_zone, sfFloatRect *pos_enn, float *time,
                obj_t *enemies);

//move ennemie
void move_enn_up(obj_t *enemy);
void move_enn_down(obj_t *enemy);
void move_enn_left(obj_t *enemy);
void move_enn_right(obj_t *enemy);
void move_ennemie(scene_t *scene, map_t *map);

//pause.c
int pause_function(scene_t *scene, pause_s *pause);

//select.c
//switch
int switch_equipement(scene_t *scene, inv_t *invent);

//option
int init_option(option_t *option);
static int option_click(scene_t *scene, option_t *option);
static int option_event(sfEvent *event, scene_t *scene, option_t *option);
void disp_option(scene_t *scene, option_t *option);
int option_function(scene_t *scene, option_t *option);
void init_exit(but_s *button);
void init_fs(but_s *button);
void init_mute(but_s *button);
void mute_sound(scene_t *scene);

//set_str.c
char *set_attack_str(obj_t *perso);
char *set_life_str(obj_t *perso);
char *set_defense_str(obj_t *perso);
char *set_magic_str(obj_t *perso);
//sell
int init_sell(scene_t *scene);
int fill_sell_str(scene_t *scene);
void fill_equipement(scene_t *scene);
void add_new_equipement(scene_t *scene, inv_t *invent, int i, int j);
int check_if_sell(scene_t *scene, inv_t *invent, int *gamemode);
void add_equipement(but_s *things, char *str, int r);
int set_money_text(scene_t *scene);
void check_text(scene_t *scene);
void remove_equipement(scene_t *scene, inv_t *invent, int i);
void set_new_equipement(scene_t *scene, inv_t *invent, int i);
//sound.c
void talk(scene_t *scene);

//tools.c
int lf_stat(char *str, char **env);
int my_argvlen(char **argv);

//init_fight
int init_fight_perso(obj_t *perso);
void init_right_perso(obj_t *perso);
void init_left_perso(obj_t *perso);

//orient
void check_orient(scene_t *scene);

sfSprite *create_sprite(char *str);
//loose
int loosescreen(int *gamemode, scene_t *scene);
int init_loose_scene(scene_t *scene);
int init_button_loose(but_s *button, char *str, int x, int y);

//reboot
void reboot_use_throw(but_s **button);

//potion
void potion_effect(scene_t *scene);
#endif
