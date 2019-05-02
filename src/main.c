/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** main
*/

#include "prototype.h"

int main(int ac, char **argv, char **env)
{
    int gamemode = 0;
    scene_t scene;

    scene.window = createmywindow(0, 1920, 1080);
    if (ac == 2 && my_str("-h", argv[1]) == 0)
        return (0);
    while (gamemode >= 0)
        switch (gamemode) {
        case 0: mainscreen(&gamemode, &scene);
            break;
        case 1: game(&gamemode, &scene);
            break;
        case 2: mainscreen(&gamemode, &scene);
            break;
        case 3: return (0);
            break;
        default: return (84);
        }
    return (0);
}

void restart_screen(scene_t *scene)
{
    static int p = 1;
    int gamemode = 1;

    sfRenderWindow_destroy(scene->window);
    if (p == 0) {
        scene->window = createmywindow(0, 1920, 1080);
        p++;
    }
    else {
        scene->window = createmywindow(1, 1920, 1080);
        p = 0;
    }
}