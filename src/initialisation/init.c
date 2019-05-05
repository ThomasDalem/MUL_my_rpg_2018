/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** init
*/

#include "prototype.h"
#include "map.h"
#include "quest.h"

sfIntRect create_char_perso(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.height = height;
    rect.width = width;
    return (rect);
}

stats create_stat_perso(int life, int attack, int defense, int magic)
{
    stats stat;

    stat.life = life;
    stat.attack = attack;
    stat.defense = defense;
    stat.magic = magic;
    return (stat);
}

void finish_init_perso(obj_t *perso)
{
    perso->move_clock = sfClock_create();
    perso->anim_clock = sfClock_create();
    perso->stat = create_stat_perso(100, 10, 5, 5);
}

int init_perso(obj_t *perso)
{
    perso->sprite = sfSprite_create();
    perso->texture = sfTexture_createFromFile(
        "assets/textures/player_5.png", NULL);
    sfSprite_setTexture(perso->sprite, perso->texture, sfFalse);
    perso->char_down = create_char_perso(24, 4, 24, 40);
    perso->char_up = create_char_perso(214, 6, 24, 40);
    perso->char_left = create_char_perso(88, 6, 24, 40);
    perso->char_right = create_char_perso(152, 4, 24, 40);
    perso->move = (sfVector2f){1.5, 1.5};
    perso->money = 100;
    perso->move_dir = 0;
    sfSprite_setTextureRect(perso->sprite, perso->char_down);
    sfSprite_setScale(perso->sprite, perso->move);
    sfSprite_setPosition(perso->sprite, (sfVector2f){600, 600});
    perso->text.phrase = sfText_create();
    finish_init_perso(perso);
    if (init_fight_perso(perso) == 84)
        return (84);
    return (0);
}

int init_all(scene_t *scene, pause_s *pause, inv_t *invent)
{
    sfRenderWindow_setFramerateLimit(scene->window, 60);
    scene->ennemi = NULL;
    scene->pnj = NULL;
    scene->perso = malloc(sizeof(obj_t));
    if (init_pause(pause) == 84)
        return (84);
    scene->perso->is_fighting = 0;
    scene->map = get_top_left_map(create_graph(3, 3));
    scene->quest = create_quests(scene->window);
    if (init_perso(scene->perso) == 84)
        return (84);
    if (init_inventory(invent, scene) == 84)
        return (84);
    if (init_pnj(scene) == 84)
        return (84);
    if (init_sell(scene) == 84)
        return (84);
    return (1);
}
