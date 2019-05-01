/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** ennemi_action
*/

#include "prototype.h"

void move_fight_enn(scene_t *scene, int direction)
{
    sfVector2f offset = {0, 0};
    sfIntRect sprite_rect;
    int move = animation_fight(scene->ennemi, direction);
    sfTime time = sfClock_getElapsedTime(scene->ennemi->move_clock);
    float second = sfTime_asSeconds(time);

    offset.x += (direction == LEFT) ? -20 : 0;
    offset.x += (direction == RIGHT) ? 20 : 0;
    if (direction == LEFT && scene->ennemi->fight->is_jumping != 1)
        anim_left_fight(scene->ennemi, move);
    if (direction == RIGHT && scene->ennemi->fight->is_jumping != 1)
        anim_rigth_fight(scene->ennemi, move);
    scene->ennemi->action.move = offset;
    if (second > 0.05) {
        if (!will_collide(scene->ennemi->sprite, scene->perso->sprite, offset))
            sfSprite_move(scene->ennemi->sprite, offset);
        sfClock_restart(scene->ennemi->move_clock);
    }
}

void repart_action(scene_t *scene)
{
    if (scene->ennemi->fight->is_attacking == 1 ||
        scene->ennemi->fight->is_blocking == 1)
        return;
    if (scene->ennemi->action.act == 1)
        attack(scene->ennemi, scene->perso);
    if (scene->ennemi->action.act == 2)
        defense(scene->ennemi);
    if (scene->ennemi->action.act == 3) {
        if (diff < 0)
            move_fight_enn(scene, LEFT);
        if (diff > 0)
            move_fight_enn(scene, RIGHT);
    }
    if (scene->ennemi->action.act == 4) {
        if (diff < 0)
            move_fight_enn(scene, RIGHT);
        if (diff > 0)
            move_fight_enn(scene, LEFT);
    }
}

void ennemi_action(scene_t *scene)
{
    float per_x = sfSprite_getPosition(scene->perso->sprite).x;
    float enn_x = sfSprite_getPosition(scene->ennemi->sprite).x;
    float diff = per_x - enn_x;

    repart_action(scene);
    scene->ennemi->action.act = scene->ennemi->action.prev_act;
    scene->ennemi->action.prev_act = 0;
    return;
}