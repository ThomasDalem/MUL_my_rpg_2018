/*
** EPITECH PROJECT, 2018
** structures.h
** File description:
** HEADER
*/

#ifndef STRUCT_H
#define STRUCT_H

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio/Sound.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/Event.h>

typedef struct musics
{
    sfMusic *sound;
    sfTime time_cl;
} musics;

typedef struct particle_s {
    sfVector2f begin_pos;
    sfVector2f velocity;
    sfCircleShape *circle;
    float bounce_vel;
    sfClock *move_clock;
    struct particle_s *next;
} particle_t;

typedef struct back_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f size;
    sfVector2f pos;
    sfVector2f speed;
} ent_t;

typedef struct info
{
    sfFont *font;
    sfText *damage;
    sfText *slow;
    sfText *reload_time;
    sfText *cost;
    sfText *zone;
    sfText *up;
} info_t;

typedef struct object
{
    sfTexture *texture;
    sfSprite *sprite;
    int cost;
    int number;
    int type;
    int effect;
    int damage;
    int life;
    int defense;
    int magic;
    float duration;
    int capacities;
} object;

typedef struct pnj
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect char_rect;
    sfVector2f pos;
    info_t info;
    struct object *object;
    musics *talk;
    musics *talk2;
    musics *talk3;
} pnj;

typedef struct button_s
{
    sfRectangleShape *but;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect char_rect;
    sfVector2f pos;
    int is_clicked;
    int is_placed;
    int is_filled;
    struct object object;
    info_t info;
    sfFont *font;
    sfText *txt;
    struct button_s *next;
} but_s;

typedef struct textes_variables
{
    sfTexture *texture;
    sfSprite *sprite_bubble;
    int var;
    char **hi_phrase;
    char **sell_phrase;
    char **by_phrase;
    sfText *phrase;
    sfFont *font;
    int nb_dialog;
} vartxt;

typedef struct horloge
{
    sfClock *clock;
    sfTime time;
    float second;
} timer;

typedef struct stats
{
    int life;
    int attack;
    int defense;
    int magic;
} stats;

typedef struct ai
{
    sfVector2f move;
    int prev_act;
    int act;
    sfClock *clock;
} ai_t;

typedef struct fight_t
{
    sfIntRect rect;
    sfIntRect attack_rect;
    sfIntRect defense_rect;
    sfIntRect jump_high_rect;
    sfIntRect jump_down_rect;
    sfTexture *texture;
    sfVector2f move;
    int is_attacking;
    int is_jumping;
    int is_blocking;
    struct horloge attack_time;
    sfClock *jump_clock;
    sfClock *block_time;
    sfClock *time_potion;
    sfVector2f jump_vec;
    int max_char;
    int beg_char;
    int is_potion;
    int type; 
    int effect;
} fight_s;

typedef struct fight_scene
{
    sfTexture *texture;
    sfSprite *sprite;
} fight_scene;

typedef struct obj_s
{
    int id;
    int discuss;
    int money;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f move;
    sfIntRect char_up;
    sfIntRect char_down;
    sfIntRect char_right;
    sfIntRect char_left;
    sfCircleShape *detect_zone;
    sfClock *move_clock;
    sfClock *anim_clock;
    sfClock *dir_clock;
    int move_dir;
    int is_fighting;
    musics *talk;
    musics *talk2;
    musics *talk3;
    struct textes_variables text;
    struct fight_t *fight;
    struct stats stat;
    struct obj_s *next;
    struct ai action;
 } obj_t;

typedef struct pause_t
{
    sfTexture *text_back;
    struct button_s **button;
    sfSprite *spr_back;
    sfFont *font;
    sfRectangleShape *filter;
    sfText **txt;
    sfText *txt_q;
    sfText *txt_qg;
} pause_s;

typedef struct option_s
{
    sfTexture *text_back;
    sfSprite *spr_back;
    struct button_s **button;
} option_t;

typedef struct inventory
{
    sfFont *font;
    sfSprite *sprite;
    sfText *attack;
    sfText *life;
    sfText *max_life;
    sfText *defense;
    sfText *magic;
    sfText *pot;
    sfColor color_potion;
    sfClock *clock_potion;
    struct stats *stat_equip;
    struct button_s **button;
    struct button_s **equipement;
} inv_t;

typedef struct sell
{
    char **str;
    sfRectangleShape *back;
    sfFont *font;
    sfText *money;
    sfText *not_money;
    sfText *no_place;
    sfColor color_money;
    sfColor color_place;
    sfClock *clock_money;
    sfClock *clock_place;
    struct button_s **things;
} sell_t;

typedef struct scene_s
{
    int if_sound;
    sfRenderWindow *window;
    musics *music;
    sfTexture *text_back;
    sfSprite *spr_back;
    struct quest_s *quest;
    struct button_s **button;
    struct obj_s *perso;
    struct sell *sell;
    struct obj_s *ennemi;
    struct obj_s *pnj;
    struct object *object;
    struct fight_scene *fight_scene;
    struct map_s *map;
} scene_t;

typedef struct structure
{
    sfEvent event;
    ent_t back;
    timer timer[3];
    float counter;
    vartxt money;
    vartxt score;
} strct;

typedef struct map_obj_s
{
    sfTexture *texture;
    sfSprite *sprite;
    int has_collider;
    sfFloatRect collision_rect;
    struct map_obj_s *next;
} map_obj_t;

typedef struct map_s
{
    map_obj_t *objects;
    particle_t *particles;
    obj_t *enemies;
    obj_t *pnj;
    struct map_s *up;
    struct map_s *down;
    struct map_s *left;
    struct map_s *right;
    char *map_file;
} map_t;

typedef struct quest_s {
    char *quest_name;
    char *description;
    sfFont *font;
    sfText *text;
    sfText *rewards;
    sfRectangleShape *rect;
    int status;
    int money;
    int exp;
    int objective_id;
    int (*check_quest_end)(void *obj, void *check);
    struct quest_s *next;
} quest_t;

#endif
