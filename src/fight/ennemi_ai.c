/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** ennemi_ai
*/

#include "prototype.h"

void ennemie_ai_part1(scene_t *scene)
{
    int r = rand() % 4;

    if (r == 0) {
        scene->ennemi->action.act = 1;
        scene->ennemi->action.prev_act = 4;
    }
    if (r == 1) {
        scene->ennemi->action.act = 3;
        scene->ennemi->action.prev_act = 1;
    }
    if (r == 2) {
        scene->ennemi->action.act = 2;
        scene->ennemi->action.prev_act = 0;
    }
    if (r == 3) {
        scene->ennemi->action.act = 4;
        scene->ennemi->action.prev_act = 2;
    }
}

void ennemie_ai_part2(scene_t *scene)
{
    int r = rand() % 4;

    if (r == 0) {
        scene->ennemi->action.act = 4;
        scene->ennemi->action.prev_act = 1;
    }
    if (r == 1) {
        scene->ennemi->action.act = 3;
        scene->ennemi->action.prev_act = 2;
    }
    if (r == 2) {
        scene->ennemi->action.act = 1;
        scene->ennemi->action.prev_act = 4;
    }
    if (r == 3) {
        scene->ennemi->action.act = 4;
        scene->ennemi->action.prev_act = 0;
    }
}

void ennemie_ai_part3(scene_t *scene)
{
    int r = rand() % 4;

    if (r == 0) {
        scene->ennemi->action.act = 4;
        scene->ennemi->action.prev_act = 0;
    }
    if (r == 1) {
        scene->ennemi->action.act = 3;
        scene->ennemi->action.prev_act = 1;
    }
    if (r == 2) {
        scene->ennemi->action.act = 4;
        scene->ennemi->action.prev_act = 2;
    }
    if (r == 3) {
        scene->ennemi->action.act = 1;
        scene->ennemi->action.prev_act = 3;
    }
}

void repart_ennemi_action(scene_t *scene, float second, int diff)
{
    if (scene->ennemi->action.act != 0 && second < 0.75 &&
        scene->ennemi->fight->is_attacking != 1 &&
        scene->ennemi->fight->is_blocking != 1)
        return;
    if ((diff > 0 && diff < 70) || (diff < 0 && diff >= -70)) {
        ennemie_ai_part1(scene);
        return;
    }
    if (scene->perso->fight->is_blocking == 1) {
        ennemie_ai_part2(scene);
        return;
    }
    if (scene->perso->fight->is_attacking == 1) {
        ennemie_ai_part3(scene);
        return;
    }
}

void chose_ennemi_action(scene_t *scene)
{
    sfVector2f pos_perso = sfSprite_getPosition(scene->perso->sprite);
    sfVector2f pos_enn = sfSprite_getPosition(scene->ennemi->sprite);
    int diff = pos_perso.x - pos_enn.x;
    sfTime time;
    float second;

    time = sfClock_getElapsedTime(scene->ennemi->action.clock);
    second = sfTime_asSeconds(time);
    repart_ennemi_action(scene, second, diff);
    sfClock_restart(scene->ennemi->action.clock);
}
