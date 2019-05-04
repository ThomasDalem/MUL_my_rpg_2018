/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** jump
*/

#include "prototype.h"

void jump_action(scene_t *scene, sfTime time, float second, sfVector2f pos)
{
    sfTime time_anime;
    float second_anime = 0;

    time_anime = sfClock_getElapsedTime(scene->perso->anim_clock);
    second_anime = sfTime_asSeconds(time_anime);
    if (second > 1) {
        scene->perso->fight->jump_vec = (sfVector2f){0, 5};
        sfSprite_setTextureRect(scene->perso->sprite,
                                scene->perso->fight->jump_down_rect);
    }
    if (second_anime > 0.01) {
        sfClock_restart(scene->perso->anim_clock);
        sfSprite_move(scene->perso->sprite, scene->perso->fight->jump_vec);
    }
    if (pos.y >= 705 && scene->perso->fight->jump_vec.y == 5) {
        scene->perso->fight->is_jumping = 0;
        check_orient(scene);
        sfSprite_setTextureRect(scene->perso->sprite,
                                scene->perso->fight->rect);
    }
}

void jump_condition(scene_t *scene)
{
    sfTime time;
    float second = 0;
    sfVector2f pos = sfSprite_getPosition(scene->perso->sprite);

    if (scene->perso->fight->is_jumping == 1) {
        scene->perso->fight->jump_vec = (sfVector2f){0, -5};
        time = sfClock_getElapsedTime(scene->perso->fight->jump_clock);
        second = sfTime_asSeconds(time);
        jump_action(scene, time, second, pos);
    }
}

void jump(scene_t *scene)
{
    sfIntRect jump_char = create_char_perso(80, 208, 18, 32);

    if (scene->perso->fight->is_jumping == 1)
        return;
    sfSprite_setTextureRect(scene->perso->sprite, jump_char);
    sfClock_restart(scene->perso->fight->jump_clock);
    sfClock_restart(scene->perso->anim_clock);
    scene->perso->fight->jump_vec = (sfVector2f){0, -5};
    scene->perso->fight->is_jumping = 1;
}