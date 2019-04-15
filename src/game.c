/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** game
*/

#include "collisions.h"
#include "prototype.h"
sfRenderWindow *createmywindow(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode,
                                   "My_RPG/v0.2.5", sfDefaultStyle, NULL);
    return (window);
}

void anime(scene_t *scene, sfVector2f move)
{
    sfIntRect rect_perso = sfSprite_getTextureRect(scene->perso.sprite_perso);

    scene->perso.timer.time = sfClock_getElapsedTime(scene->perso.timer.clock);
    scene->perso.timer.second = sfTime_asMilliseconds(scene->perso.timer.time);
    if (scene->perso.timer.second > 50) {
        if (rect_perso.top <= 0)
            rect_perso.top = rect_perso.top + 30;
        else
            rect_perso.top = 0;
        sfSprite_setTextureRect(scene->perso.sprite_perso, rect_perso);
        sfClock_restart(scene->perso.timer.clock);
    }
}

void game(int *gamemode, scene_t *scene)
{
    sfEvent event;
    pause_s pause;
    inv_t invent;
    int nb_perso = select_perso(scene, gamemode);

    if (nb_perso == 84 || nb_perso == 3) {
        *gamemode = 3;
        return;
    }
    *gamemode = init_all(scene, &pause, &invent);
    while (sfRenderWindow_isOpen(scene->window) && *gamemode == 1) {
        disp_scene(scene);
        move_ennemie(scene);
        while (sfRenderWindow_pollEvent(scene->window, &event)) {
            *gamemode = allevent(scene, &event, &pause, &invent);
        }
        check_collision(scene);
        move_player();
    }
    close_window(scene, &pause, gamemode);
}


