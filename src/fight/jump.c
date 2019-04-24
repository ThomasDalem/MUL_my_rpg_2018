/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** jump
*/

#include "prototype.h"

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