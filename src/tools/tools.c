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
