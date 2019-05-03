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
#include "quest.h"

static void create_text(quest_t *quest)
{
    quest->text = sfText_create();
    quest->rewards = sfText_create();
    sfText_setFont(quest->text, quest->font);
    sfText_setFont(quest->rewards, quest->font);
    sfText_setFillColor(quest->text, sfBlack);
    sfText_setFillColor(quest->rewards, sfBlack);
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

quest_t *create_quest(quest_t *next)
{
    quest_t *quest = malloc(sizeof(quest_t));

    if (quest == NULL)
        return (NULL);
    quest->quest_name = NULL;
    quest->description = NULL;
    quest->money = 0;
    quest->status = 0;
    quest->font = sfFont_createFromFile("./assets/texts/basic.ttf");
    create_text(quest);
    create_rect(quest);
    quest->next = next;
    return (quest);
}

quest_t *create_quests(sfRenderWindow *window)
{
    quest_t *quests = NULL;

    quests = create_quest(quests);
    if (quests == NULL)
        return (NULL);
    set_quest_name(window, quests, "Objective : Kill another enemy.");
    set_quest_rewards(window, quests, 1000, 354);
    quests = create_quest(quests);
    if (quests == NULL)
        return (NULL);
    set_quest_name(window, quests, "Objective : Kill the enemy.");
    set_quest_rewards(window, quests, 100, 35);
    return (quests);
}
