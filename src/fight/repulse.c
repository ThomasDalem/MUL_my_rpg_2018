/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** repulse
*/

#include "prototype.h"

int cond_repulse(sfFloatRect per_rect, sfFloatRect enn_rect)
{
    int down = per_rect.top + per_rect.height;
    int right = per_rect.left + per_rect.width;
    int right_enn = enn_rect.left + enn_rect.width;

    if (down > enn_rect.top && right >= enn_rect.left &&
        right <= enn_rect.left + enn_rect.width)
        return (1);
    if (down > enn_rect.top && per_rect.left <= right_enn &&
        per_rect.left >= enn_rect.left)
        return (1);
    return (0);
}

void calc_repulse_vector(scene_t *scene, sfVector2f *perso,
                            sfVector2f *enn, sfVector2f *end)
{
    float pos_perso = fabs(sfSprite_getPosition(scene->perso->sprite).x);
    float pos_ennemie = fabs(sfSprite_getPosition(scene->ennemi->sprite).x);

    if (pos_perso - pos_ennemie >= 0) {
        *perso = (sfVector2f){10, 0};
        if (sfSprite_getPosition(scene->perso->sprite).y < 710)
            *perso = (sfVector2f){10, 2};
        *enn = (sfVector2f){-10, 0};
        if (sfSprite_getPosition(scene->ennemi->sprite).y < 710)
            *enn = (sfVector2f){-10, 2};
        *end = (sfVector2f){1300, 200};
    }
    if (pos_perso - pos_ennemie <= 0) {
        *perso = (sfVector2f){-10, 0};
        if (sfSprite_getPosition(scene->perso->sprite).y < 710)
            *perso = (sfVector2f){-10, 2};
        *enn = (sfVector2f){10, 0};
        if (sfSprite_getPosition(scene->ennemi->sprite).y < 710)
            *enn = (sfVector2f){10, 2};
        *end = (sfVector2f){200, 1300};
    }
}

obj_t *move_repulse(obj_t *perso, sfVector2f vec, sfTime time, float end)
{
    float second = sfTime_asSeconds(time);

    if (second > 0.02 && sfSprite_getPosition(perso->sprite).x != end) {
        sfSprite_move(perso->sprite, vec);
        sfClock_restart(perso->anim_clock);
    }
    return (perso);
}

void repulse(scene_t *scene, sfSprite *sprite, inv_t *invent)
{
    sfVector2f perso;
    sfVector2f ennemie;
    sfVector2f end;
    sfVector2f pos_perso = sfSprite_getPosition(scene->perso->sprite);
    sfVector2f pos_enn = sfSprite_getPosition(scene->ennemi->sprite);
    sfTime time_perso;
    sfTime time_enn;

    calc_repulse_vector(scene, &perso, &ennemie, &end);
    while (pos_perso.x != end.x && pos_enn.x != end.y) {
        calc_repulse_vector(scene, &perso, &ennemie, &end);
        time_perso = sfClock_getElapsedTime(scene->perso->anim_clock);
        time_enn = sfClock_getElapsedTime(scene->ennemi->anim_clock);
        scene->perso = move_repulse(scene->perso, perso, time_perso, end.x);
        move_repulse(scene->ennemi, ennemie, time_enn, end.y);
        pos_perso = sfSprite_getPosition(scene->perso->sprite);
        pos_enn = sfSprite_getPosition(scene->ennemi->sprite);
        disp_fight(scene, sprite, invent);
    }
}

void check_repulse(scene_t *scene, sfSprite *sprite, inv_t *invent)
{
    sfFloatRect per_rect = sfSprite_getGlobalBounds(scene->perso->sprite);
    sfFloatRect enn_rect = sfSprite_getGlobalBounds(scene->ennemi->sprite);
    sfVector2f pos_perso = sfSprite_getPosition(scene->perso->sprite);
    sfVector2f pos_enn = sfSprite_getPosition(scene->ennemi->sprite);
    sfMusic *music;

    if (scene->perso->fight->is_attacking != 1 &&
        scene->ennemi->fight->is_attacking != 1 &&
        cond_repulse(per_rect, enn_rect) == 1) {
        music = sfMusic_createFromFile("./assets/sound/repulse.ogg");
        sfMusic_play(music);
        start_repulse(scene);
        repulse(scene, sprite, invent);
        pos_perso = sfSprite_getPosition(scene->perso->sprite);
        if (pos_perso.y != 710)
            pos_perso.y = 710;
        sfSprite_setPosition(scene->perso->sprite, pos_perso);
        sfMusic_stop(music);
        sfMusic_destroy(music);
    }
}
