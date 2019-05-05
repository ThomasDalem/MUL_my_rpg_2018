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
#include "quest.h"

sfRenderWindow *createmywindow(int fs, unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    if (fs == 0) {
        window = sfRenderWindow_create(video_mode,
                                        "My_RPG/v1.0.1", sfDefaultStyle, NULL);
    }
    if (fs > 0) {
        window = sfRenderWindow_create(video_mode,
                                        "My_RPG/v1.0.1", sfFullscreen, NULL);
    }
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

void loop_function(int *gamemode, scene_t *scene, 
    pause_s *pause, inv_t *invent)
{
    move_player(scene, scene->perso, scene->perso->move_dir);
    move_particles(scene->map->particles);
    move_ennemie(scene, scene->map);
    check_quests(scene, scene->quest);
    if (*gamemode == 1)
        *gamemode = check_if_sell(scene, invent, gamemode);
    if (*gamemode == 1)
        *gamemode = is_a_fight(scene, invent, pause);
}

void set_music(sfMusic *music)
{
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
}

void game(int *gamemode, scene_t *scene, option_t *option)
{
    sfEvent event;
    pause_s pause;
    inv_t invent;
    sfMusic *music = sfMusic_createFromFile("assets/sound/game_music.ogg");

    set_music(music);
    display_intro(scene->window);
    *gamemode = init_all(scene, &pause, &invent);
    if (*gamemode == 84)
        return;
    while (sfRenderWindow_isOpen(scene->window) && *gamemode == 1) {
        disp_scene(scene, scene->quest);
        check_maps(sfSprite_getPosition(scene->perso->sprite), scene);
        loop_function(gamemode, scene, &pause, &invent);
        while (sfRenderWindow_pollEvent(scene->window, &event) &&
                *gamemode == 1)
            *gamemode = allevent(scene, &event, &pause, &invent);
        if (scene->quest == NULL) {
            display_end(scene->window);
            *gamemode = 2;
        }
    }
    if (scene->perso->stat.life <= 0)
        loosescreen(gamemode, scene);
    sfMusic_stop(music);
    free_graph(scene->map);
    close_window(scene, &pause, gamemode, &invent);
}
