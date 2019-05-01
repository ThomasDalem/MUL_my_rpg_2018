/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_quest
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>
#include <stdlib.h>
#include "structures.h"

static void create_text(quest_t *quest)
{
    quest->text = sfText_create();
    sfText_setFont(quest->text, quest->font);
    sfText_setFillColor(quest->text, sfBlack);
}

static void create_rect(quest_t *quest)
{
    sfColor rect_color = sfGreen;

    quest->rect = sfRectangleShape_create();
    rect_color.a = 155;
    sfRectangleShape_setFillColor(quest->rect, rect_color);
    sfRectangleShape_setOutlineColor(quest->rect, sfBlack);
    sfRectangleShape_setOutlineThickness(quest->rect, 2);
}

quest_t *create_quest(void)
{
    quest_t *quest = malloc(sizeof(quest_t));

    if (quest == NULL)
        return (NULL);
    quest->quest_name = NULL;
    quest->description = NULL;
    quest->reward = 0;
    quest->status = 0;
    quest->font = sfFont_createFromFile("./assets/texts/basic.ttf");
    create_text(quest);
    create_rect(quest);
    return (quest);
}
