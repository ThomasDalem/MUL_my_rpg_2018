/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** check_fight
*/

#include "fight.h"

void disp_fight(scene_t *scene, sfSprite *sprite, inv_t *invent)
{
    sfRenderWindow_clear(scene->window, sfBlack);
    sfRenderWindow_drawSprite(scene->window, sprite, NULL);
    set_text(scene->perso->text.phrase, "PERSO", invent->font,
            (sfVector2f){10, 10});
    sfRenderWindow_drawText(scene->window, scene->perso->text.phrase, NULL);
    disp_hud(scene, scene->perso, 10, 10);
    set_text(scene->ennemi->text.phrase, "ENNEMIE", invent->font,
            (sfVector2f){1700, 10});
    disp_hud(scene, scene->ennemi, 1700, 10);
    sfRenderWindow_drawText(scene->window, scene->ennemi->text.phrase, NULL);
    sfRenderWindow_drawSprite(scene->window, scene->perso->sprite, NULL);
    sfRenderWindow_drawSprite(scene->window, scene->ennemi->sprite, NULL);
    sfRenderWindow_display(scene->window);
}

int fight_action(scene_t *scene, sfSprite *fond, inv_t *invent)
{
    attack_condition(scene->perso);
    jump_condition(scene);
    defense_condition(scene->perso);
    check_orient(scene);
    check_repulse(scene, fond, invent);
    chose_ennemi_action(scene);
    attack_condition(scene->ennemi);
    defense_condition(scene->ennemi);
    ennemi_action(scene);
}

int start_fight(scene_t *scene, inv_t *invent, pause_s *pause)
{
    sfEvent event;
    sfSprite *fond = create_sprite("assets/textures/fight.png");
    int fight = 1;

    sfSprite_setPosition(fond, (sfVector2f){0, 0});
    finish_init_fight_perso(scene->perso, 100, 710);
    finish_init_fight_perso(scene->ennemi, 800, 710);
    sfClock_restart(scene->ennemi->action.clock);
    while (sfRenderWindow_isOpen(scene->window) && fight == 1) {
        disp_fight(scene, fond, invent);
        fight_action(scene, fond, invent);
        fight = check_alive(scene);
        potion_effect(scene);
        while (sfRenderWindow_pollEvent(scene->window, &event) && fight == 1)
            fight = fight_event(scene, &event, pause, invent);
    }
    if (fight == 0)
        fight = 1;
    return (fight);
}

int check_fight(sfSprite *sprite1, sfSprite *sprite2)
{
    sfVector2f up = {0, -5};
    sfVector2f down = {0, 5};
    sfVector2f left = {-5, 0};
    sfVector2f right = {5, 0};

    if (will_collide(sprite1, sprite2, up) == 1)
        return (1);
    if (will_collide(sprite1, sprite2, down) == 1)
        return (1);
    if (will_collide(sprite1, sprite2, right) == 1)
        return (1);
    if (will_collide(sprite1, sprite2, left) == 1)
        return (1);
    return (0);
}

int is_a_fight(scene_t *scene, inv_t *invent, pause_s *pause)
{
    obj_t *enn = scene->map->enemies;
    sfFloatRect pos_enn;
    sfFloatRect pos_perso = sfSprite_getGlobalBounds(scene->perso->sprite);
    sfVector2f pos = sfSprite_getPosition(scene->perso->sprite);
    int i = 1;

    scene->ennemi = scene->map->enemies;
    while (scene->ennemi != NULL && i == 1) {
        pos_enn = sfSprite_getGlobalBounds(scene->ennemi->sprite);
        if (check_fight(scene->perso->sprite, scene->ennemi->sprite) == 1) {
            scene->perso->is_fighting = 1;
            i = start_fight(scene, invent, pause);
            remove_enemy(scene->ennemi, &scene->map->enemies);
            after_fight_function(scene, pos);
            return (i);
        }
        scene->ennemi = scene->ennemi->next;
    }
    scene->map->enemies = enn;
    return (i);
}
