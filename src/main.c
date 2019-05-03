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
    option_t option;

    srand(time(NULL));
    if (env[0] == NULL)
        return (84);
    scene.window = createmywindow(0, 1920, 1080);
    if (ac == 2 && my_str("-h", argv[1]) == 0)
        return (0);
    if (init_option(&option) == 84)
        return (84);
    while (gamemode >= 0)
        switch (gamemode) {
        case 0: mainscreen(&gamemode, &scene, &option);
            break;
        case 1: game(&gamemode, &scene, &option);
            break;
        case 2: mainscreen(&gamemode, &scene, &option);
            break;
        case 3: return (0);
            break;
        default: return (84);
        }
    return (0);
}