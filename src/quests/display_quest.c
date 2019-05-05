/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_quest
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdio.h>
#include "structures.h"

void display_quest(quest_t *quest, sfRenderWindow *window)
{
    if (quest != NULL) {
        sfRenderWindow_drawRectangleShape(window, quest->rect, NULL);
        sfRenderWindow_drawText(window, quest->text, NULL);
        sfRenderWindow_drawText(window, quest->rewards, NULL);
    }
}