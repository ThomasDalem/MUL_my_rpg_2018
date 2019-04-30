/*
** EPITECH PROJECT, 2019
** My RPG
** File description:
** Sound file
*/

#include "prototype.h"

void talk(scene_t *scene)
{
    int y = 0;

    srand(time(NULL));
    y = rand() % 3;
    switch (y) {
        printf("[%d]\n", y);
    case 0: sfMusic_play(scene->pnj->talk->sound); break;
    case 1: printf("talk 2\n"); break;
    case 2: printf("talk 3\n"); break;
    default: printf("Unknow Error :/\n");
    }
}
