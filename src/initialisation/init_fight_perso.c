/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_fight_perso
*/

#include "prototype.h"

void finish_init_fight_perso(obj_t *perso, int x, int y)
{
    sfVector2f scale = {3, 3};
    sfVector2f position = {x, y};

    sfSprite_setTexture(perso->sprite, perso->fight->texture, sfTrue);
    sfSprite_setTextureRect(perso->sprite, perso->fight->rect);
    sfSprite_setPosition(perso->sprite, position);
    sfSprite_setScale(perso->sprite, scale);
    sfClock_restart(perso->fight->time_potion);
    perso->action.act = 0;
    perso->action.prev_act = 0;
}

void init_right_perso(obj_t *perso)
{
    perso->fight->rect = create_char_perso(0, 167, 17, 31);
    perso->fight->attack_rect = create_char_perso(41, 200, 32, 30);
    perso->fight->jump_high_rect = create_char_perso(80, 208, 18, 32);
    perso->fight->jump_down_rect = create_char_perso(80, 247, 18, 32);
    perso->fight->defense_rect = create_char_perso(41, 247, 17 , 31);
    perso->fight->max_char = 287;
    perso->fight->beg_char = 167;
}

void init_left_perso(obj_t *perso)
{
    perso->fight->rect = create_char_perso(0, 7, 17, 31);
    perso->fight->attack_rect = create_char_perso(40, 79, 32, 30);
    perso->fight->jump_high_rect = create_char_perso(79, 87, 18, 32);
    perso->fight->jump_down_rect = create_char_perso(80, 47, 18, 32);
    perso->fight->defense_rect = create_char_perso(41, 47, 17 , 31);
    perso->fight->max_char = 127;
    perso->fight->beg_char = 7;
}

int init_fight_perso(obj_t *perso)
{
    perso->fight = malloc(sizeof(struct fight_t));
    if (perso->fight == NULL)
        return (84);
    perso->fight->texture = sfTexture_createFromFile(
        "assets/textures/link_battle.png", NULL);
    init_right_perso(perso);
    perso->fight->attack_time.clock = sfClock_create();
    perso->fight->jump_clock = sfClock_create();
    perso->fight->block_time = sfClock_create();
    perso->fight->time_potion = sfClock_create();
    perso->fight->is_jumping = 0;
    perso->fight->is_attacking = 0;
    perso->fight->is_blocking = 0;
    perso->fight->is_potion = 0;
    return (0);
}
