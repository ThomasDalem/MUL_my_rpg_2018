/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** set_quest_attributes
*/

#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <stdio.h>
#include "structures.h"
#include "my.h"

static sfVector2f center_text_pos(sfRectangleShape *rect, sfText *text)
{
    sfFloatRect rect_rect = sfRectangleShape_getGlobalBounds(rect);
    sfFloatRect text_rect = sfText_getGlobalBounds(text);
    sfVector2f new_pos;

    new_pos.x = rect_rect.left + rect_rect.width / 2 - text_rect.width / 2;
    new_pos.y = rect_rect.top + rect_rect.height / 2 - text_rect.height / 1.5;
    return (new_pos);
}

static void resize_rect(sfRectangleShape *rect, sfText *text)
{
    sfFloatRect text_rect = sfText_getGlobalBounds(text);
    sfVector2f new_size;

    new_size.x = text_rect.width + 20;
    new_size.y = text_rect.height + 20;
    sfRectangleShape_setSize(rect, new_size);
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

void set_quest_name(sfRenderWindow *window, quest_t *quest, char *name)
{
    sfVector2f rect_size;
    int char_size = 0;

    quest->quest_name = name;
    sfText_setString(quest->text, quest->quest_name);
    sfText_setCharacterSize(quest->text, 32);
    sfText_setColor(quest->text, sfBlack);
    resize_rect(quest->rect, quest->text);
    move_rect(window, quest->rect);
    sfText_setPosition(quest->text, center_text_pos(quest->rect, quest->text));
}
