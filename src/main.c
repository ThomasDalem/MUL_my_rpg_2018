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

    scene.window = createmywindow(1920, 1080);
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
        case 3: return (free_global(&scene));
            break;
        default: return (84);
        }
    return (0);
}
