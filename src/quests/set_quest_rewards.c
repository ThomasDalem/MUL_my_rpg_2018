/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** set_quest_rewards
*/

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Text.h>
#include "structures.h"
#include "quest.h"
#include "my.h"

static char *set_str(int money, int exp)
{
    char *money_str = int_to_char(money);
    char *exp_str = int_to_char(exp);
    int size = 20 + my_strlen(money_str) + my_strlen(exp_str);
    char *str = malloc(sizeof(char) * (size + 1));

    str[0] = '\0';
    my_strcat(str, "Reward: ");
    my_strcat(str, money_str);
    my_strcat(str, " Exp: ");
    my_strcat(str, exp_str);
    return (str);
}

static void resize_rect(sfRectangleShape *rect, quest_t *quest)
{
    sfFloatRect text_rect = sfText_getGlobalBounds(quest->text);
    sfFloatRect reward_rect = sfText_getGlobalBounds(quest->rewards);
    sfVector2f new_size;

    new_size.x = text_rect.width + 20;
    new_size.y = text_rect.height + reward_rect.height + 20;
    sfRectangleShape_setSize(rect, new_size);
}

static sfVector2f center_text_pos(sfRectangleShape *rect, quest_t *quest)
{
    sfFloatRect rect_rect = sfRectangleShape_getGlobalBounds(rect);
    sfFloatRect text_rect = sfText_getGlobalBounds(quest->text);
    sfFloatRect reward_rect = sfText_getGlobalBounds(quest->rewards);
    sfVector2f text_pos;
    sfVector2f new_pos;

    text_pos.x = text_rect.left;
    text_pos.y = rect_rect.height / 2 - text_rect.height / 2 - 5;
    text_pos.y -= reward_rect.height / 2 + rect_rect.top;
    new_pos.x = rect_rect.left + rect_rect.width / 2 - text_rect.width / 2;
    new_pos.y = rect_rect.top + rect_rect.height / 2 - text_rect.height / 2;
    new_pos.y += reward_rect.height + 5;
    sfText_setPosition(quest->text, text_pos);
    sfText_setPosition(quest->rewards, new_pos);
    return (new_pos);
}

static void move_rect(sfRenderWindow *window, sfRectangleShape *rect)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfFloatRect rect_rect = sfRectangleShape_getGlobalBounds(rect);
    sfVector2f new_pos;

    new_pos.x = window_size.x - rect_rect.width - 20;
    new_pos.y = 0;
    sfRectangleShape_setPosition(rect, new_pos); 
}

void set_quest_rewards(sfRenderWindow *win, quest_t *quest, int money, int exp)
{
    quest->money = money;
    quest->exp = exp;

    sfText_setString(quest->rewards, set_str(money, exp));
    sfText_setCharacterSize(quest->rewards, 20);
    resize_rect(quest->rect, quest);
    center_text_pos(quest->rect, quest);
    move_rect(win, quest->rect);
}
