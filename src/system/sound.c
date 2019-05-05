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
    case 0: sfMusic_play(scene->pnj->talk->sound);
        break;
    case 1: sfMusic_play(scene->pnj->talk2->sound);
        break;
    case 2: sfMusic_play(scene->pnj->talk3->sound);
        break;
    default: write(2, "Unknow Error :/\n", 16);
    }
}