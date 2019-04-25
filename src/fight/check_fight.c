/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** check_fight
*/

#include "prototype.h"

void disp_fight(scene_t *scene, sfSprite *sprite)
{
    sfRenderWindow_clear(scene->window, sfBlack);
    sfRenderWindow_drawSprite(scene->window, sprite, NULL);
    sfRenderWindow_drawSprite(scene->window, scene->perso->sprite, NULL);
    sfRenderWindow_drawSprite(scene->window, scene->ennemi->sprite, NULL);
    sfRenderWindow_display(scene->window);
}

void jump_condition(scene_t *scene)
{
    sfTime time;
    float second = 0;

    if (scene->perso->fight->is_jumping == 1) {
        time = sfClock_getElapsedTime(scene->perso->fight->jump_clock);
        second = sfTime_asSeconds(time);
        if (second > 1) {
            scene->perso->fight->jump_vec = (sfVector2f){0, 5};
            sfSprite_setTextureRect(scene->perso->sprite, scene->perso->fight->jump_down_rect);
        }
        if (second < 2)
            sfSprite_move(scene->perso->sprite, scene->perso->fight->jump_vec);
        if (second > 2) {
            scene->perso->fight->is_jumping = 0;
            check_orient(scene);
            sfSprite_setTextureRect(scene->perso->sprite, scene->perso->fight->rect);
        }
    }
}

void attack_condition(scene_t *scene)
{
    sfTime time = sfClock_getElapsedTime(scene->perso->anim_clock);
    float second = 0;

    if (scene->perso->fight->is_attacking == 1) {
        time = sfClock_getElapsedTime(scene->perso->fight->attack_time.clock);
        second = sfTime_asSeconds(time);
        if (second > 0.5) {
            scene->perso->fight->is_attacking = 0;
            sfClock_restart(scene->perso->fight->attack_time.clock);
            sfSprite_setTextureRect(scene->perso->sprite, scene->perso->fight->rect);
        }
    }
}

int start_fight(scene_t *scene, inv_t *invent, pause_s *pause)
{
    sfEvent event;
    sfSprite *fond = create_sprite("assets/textures/fight.png");
    sfVector2f pos = {0, 0};
    int fight = 1;

    sfSprite_setPosition(fond, pos);
    finish_init_fight_perso(scene->perso, 100, 800);
    finish_init_fight_perso(scene->ennemi, 800, 800);
    while (sfRenderWindow_isOpen(scene->window) && fight == 1) {
        disp_fight(scene, fond);
        attack_condition(scene);
        jump_condition(scene);
        defense_condition(scene);
        check_orient(scene);
        while (sfRenderWindow_pollEvent(scene->window, &event)) {
            fight = fight_event(scene, &event, pause, invent);
        }
    }
    return (fight);
}

int is_a_fight(scene_t *scene, inv_t *invent, pause_s *pause)
{
    obj_t *enn = scene->ennemi;
    sfFloatRect pos_enn;
    sfFloatRect pos_perso = sfSprite_getGlobalBounds(scene->perso->sprite);
    int i = 1;

    //i = start_fight(scene, invent, pause);
    /*
    while (scene->ennemi != NULL && i == 1) {
        pos_enn = sfSprite_getGlobalBounds(scene->ennemi->sprite);
        if (is_colliding(pos_enn, pos_perso) == 1)
            i = start_fight(scene, invent, pause);
        scene->ennemi = scene->ennemi->next;
    }
    */
    //scene->ennemi = enn;
    return (i);
}
