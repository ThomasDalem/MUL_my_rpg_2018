/*
** EPITECH PROJECT, 2018
** structures.h
** File description:
** HEADER
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct map_obj_s
{
    sfTexture *texture;
    sfSprite *sprite;
    int has_collider;
    struct map_obj_s *next;
} map_obj_t;

typedef struct map_s
{
    sfTexture *background_texture;
    sfSprite *background_sprite;
    map_obj_t *objects;
    struct map_s *up;
    struct map_s *down;
    struct map_s *left;
    struct map_s *right;
} map_t;

typedef struct musics
{
    sfMusic *main;
    sfTime time_cl;
} musics;

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
    int damage;
    int life;
    int defense;
    int magic;
} object;

typedef struct pnj
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect char_rect;
    sfVector2f pos;
    info_t info;
    struct object *object;
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
    int max_life;
    int attack;
    int defense;
    int magic;
} stats;

typedef struct fight_t
{
    sfIntRect char_right;
    sfIntRect char_left;
    sfTexture *texture;
    sfVector2f move;
} fight_s;

typedef struct fight_scene
{
    sfTexture *texture;
    sfSprite *sprite;
} fight_scene;

typedef struct obj_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f move;
    sfIntRect char_up;
    sfIntRect char_down;
    sfIntRect char_right;
    sfIntRect char_left;
    sfCircleShape *detect_zone;
    int nb_perso;
    int discuss;
    struct textes_variables text;
    struct fight_t *fight;
    sfClock *move_clock;
    sfClock *anim_clock;
    struct stats stat;
    struct obj_s *next;
} obj_t;

typedef struct pause_t
{
    sfFont *font;
    sfRectangleShape *filter;
    sfText **txt;
    sfText *txt_q;
    sfText *txt_qg;
} pause_s;

typedef struct inventory
{
    sfFont *font;
    sfSprite *sprite;
    sfText *attack;
    sfText *life;
    sfText *max_life;
    sfText *defense;
    sfText *magic;
    struct stats *stat_equip;
    struct button_s **button;
    struct button_s **equipement;
} inv_t;

typedef struct scene_s
{
    sfRenderWindow *window;
    musics *music;
    struct button_s **button;
    struct  obj_s *perso;
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

#endif
