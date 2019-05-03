/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** attack
*/

#include "fight.h"

void attack_condition(obj_t *perso)
{
    sfTime time = sfClock_getElapsedTime(perso->anim_clock);
    float second = 0;

    if (perso->fight->is_attacking == 1) {
        time = sfClock_getElapsedTime(perso->fight->attack_time.clock);
        second = sfTime_asSeconds(time);
        if (second > 0.5) {
            perso->fight->is_attacking = 0;
            sfClock_restart(perso->fight->attack_time.clock);
            sfSprite_setTextureRect(perso->sprite, perso->fight->rect);
        }
    }
}

void attack(obj_t *perso1, obj_t *perso2)
{
    sfFloatRect per_rect;
    sfFloatRect enn_rect = sfSprite_getGlobalBounds(perso2->sprite);

    if (perso1->fight->is_blocking == 1 || perso2->fight->is_attacking == 1)
        return;
    sfSprite_setTextureRect(perso1->sprite, perso1->fight->attack_rect);
    perso1->fight->is_attacking = 1;
    if (diff(perso1, perso2) == -1)
        sfSprite_move(perso1->sprite, (sfVector2f){-20, 0});
    per_rect = sfSprite_getGlobalBounds(perso1->sprite);
    sfClock_restart(perso1->fight->attack_time.clock);
    if (sfFloatRect_intersects(&per_rect, &enn_rect, NULL) == sfTrue &&
        perso2->fight->is_blocking != 1) {
        perso2->stat.life = perso2->stat.life - perso1->stat.attack;
        if (diff(perso1, perso2) == 1)
            sfSprite_move(perso2->sprite, (sfVector2f){40, 0});
        if (diff(perso1, perso2) == -1)
            sfSprite_move(perso2->sprite, (sfVector2f){-40, 0});
    }
}
