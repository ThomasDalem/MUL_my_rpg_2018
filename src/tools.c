/*
** EPITECH PROJECT, 2019
** My RPG
** File description:
** oui
*/

#include "prototype.h"

int lf_stat(char *str, char **env)
{
    int z = 0;

    while (env[z + 1] != NULL) {
        if (my_strcmp(str, env[z]) == 0)
            return (z);
        z ++;
    }
    return (-1);
}

int my_argvlen(char **argv)
{
    int i = 0;

    while (argv[i] != NULL)
	i ++;
    return (i);
}

int env_check(char **env)
{
    int y = lf_stat("DISPLAY", env);
    int o = lf_stat("X11 display", env);
    int b = lf_stat("X11", env);

    if (env == NULL || env[y] == NULL || env[o] == NULL ||
        env[b] == NULL || y < 0) {
        printf("my_jevaistenikersalope\n");
        return (84);
    }
}
