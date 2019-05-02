/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** game
*/

#include "collisions.h"
#include "prototype.h"
#include "map.h"
#include "particles.h"

sfRenderWindow *createmywindow(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode,
                                   "My_RPG/v1.0.7", sfDefaultStyle, NULL);
    return (window);
}

void anim(obj_t *player)
{
    sfIntRect rect_perso = sfSprite_getTextureRect(player->sprite);
    sfTime elapsed_time = sfClock_getElapsedTime(player->anim_clock);
    float time = sfTime_asSeconds(elapsed_time);

    if (time > 0.1) {
        if (rect_perso.left <= 0)
            rect_perso.left = rect_perso.left + 32;
        else
            rect_perso.left = 0;
        sfSprite_setTextureRect(player->sprite, rect_perso);
        sfClock_restart(player->anim_clock);
    }
}

void game(int *gamemode, scene_t *scene)
{
    sfEvent event;
    pause_s pause;
    inv_t invent;
    int nb_perso;
    particle_t *particles = NULL;

    *gamemode = init_all(scene, &pause, &invent);
    if (*gamemode == 84)
        return;
    while (sfRenderWindow_isOpen(scene->window) && *gamemode == 1) {
        disp_scene(scene, particles);
        move_ennemie(scene);
        *gamemode = is_a_fight(scene, &invent, &pause);
        check_maps(sfSprite_getPosition(scene->perso->sprite), scene);
        while (sfRenderWindow_pollEvent(scene->window, &event) &&
               *gamemode == 1)
            *gamemode = allevent(scene, &event, &pause, &invent);
        move_particles(scene->map->particles);
    }
    if (scene->perso->stat.life <= 0)
        loosescreen(gamemode, scene);
    free_graph(scene->map);
    close_window(scene, &pause, gamemode, &invent);
}
