/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** remove_endline
*/

#include "my.h"

void remove_endline(char *line)
{
    int i = my_strlen(line);

    line[i - 1] = '\0';
}
