/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** remove_endline
*/

#include "my.h"

void remove_endline(char *line)
{
    int i = 0;

    while (line[i] != '\n' && line[i] != '\0')
        i ++;
    if (line[i] == '\n')
        line[i] = '\0';
}
